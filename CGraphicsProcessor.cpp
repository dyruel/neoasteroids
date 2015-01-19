/*************************************************************************
 * NeoAsteroids                                                          *
 * Copyright (C) 2014  Chopin Morgan                                     *
 *                                                                       *
 * This program is free software: you can redistribute it and/or modify  *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 *************************************************************************/

#include "CGraphicsProcessor.h"


bool CGraphicsProcessor::init()
{
    
    if( SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        CFileLogger::logFormat( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    
    if ( TTF_Init() < 0 ) {
        CFileLogger::logFormat( "SDL_ttf could not initialize! SDL_Error: %s\n", TTF_GetError() );
        return false;
    }
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    
    m_window = SDL_CreateWindow( "NeoAsteroids",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                800,
                                600,
                                SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
    if( m_window == NULL )
    {
        CFileLogger::logFormat( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    
    m_glcontext = SDL_GL_CreateContext( m_window );
    
    if ( m_glcontext == NULL ) {
        CFileLogger::logFormat( "Could not create an OpenGL context! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    //m_screen = SDL_GetWindowSurface( m_window );
    
    //int maj = 0, min = 0;
    //glGetIntegerv(GL_MAJOR_VERSION, &maj);
    //glGetIntegerv(GL_MINOR_VERSION, &min);
    //std::cout << maj << " " << min << std::endl;
    
    
    glClearColor( 0.0f, 0.0f, 0.0f, 1.f );
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    m_basicProgram = createProgram(
                                   "#version 150\n\
\
                                   in vec4 position;\
\
                                   uniform mat4 Projection;\
\
                                   uniform mat4 Model;\
\
                                   void main()\
                                   {\
                                    gl_Position = Projection * Model * position;\
                                   }\
                                   ",
                                   "#version 150\nout vec4 out_color; void main() { out_color = vec4( 1.0, 1.0, 1.0, 1.0 ); }"
                                   );
    glUseProgram(m_basicProgram);
    
    m_winWidth = 800;
    m_winHeight = 600;
    
    //
    glViewport(0, 0, m_winWidth, m_winHeight);
    
    GLfloat aspect = (GLfloat)m_winWidth / (GLfloat)m_winHeight;
    
    glm::mat4 projection;
    
    if ( m_winWidth >= m_winHeight )
    {
        projection = glm::ortho(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
    }
    else
    {
        projection = glm::ortho(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
    }

    
    glUniformMatrix4fv( glGetUniformLocation(m_basicProgram, "Projection" ), 1, GL_FALSE, glm::value_ptr(projection) );
    
    //
    m_modelMatrix = glGetUniformLocation(m_basicProgram, "Model" );
    
    
    GLint vertexPositionAttrib = glGetAttribLocation ( m_basicProgram, "position") ;
    
    // Initialize VAOs/VBOs/IBOs
#if 0
    glGenVertexArrays ( PE::NUM_MESH, m_vaos);
    glGenBuffers( PE::NUM_MESH, m_vbos );
    glGenBuffers( PE::NUM_MESH, m_ibos );
    

    // Asteroids VBOs/IBOs
    
    GLfloat asteroid1Vertices[] =
    {
        -0.1f, -0.1f, 0.0f,
        0.1f, -0.1f, 0.0f,
        0.1f,  0.1f, 0.0f,
        -0.1f,  0.1f, 0.0f,
    };
    GLuint asteroid1Indices[] = { 0, 1, 2, 3 };
    
    m_numIndices[PE::ASTEROID1_MESH] = 4;
    
    glBindBuffer( GL_ARRAY_BUFFER, m_vbos[PE::ASTEROID1_MESH]);
    glBufferData( GL_ARRAY_BUFFER, 12 * sizeof(GLfloat), asteroid1Vertices, GL_STATIC_DRAW );
    
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_ibos[PE::ASTEROID1_MESH] );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, m_numIndices[PE::ASTEROID1_MESH] * sizeof(GLuint), asteroid1Indices, GL_STATIC_DRAW );
    
    // VAO
    glBindVertexArray (m_vaos[PE::ASTEROID1_MESH]);
        glEnableVertexAttribArray (vertexPositionAttrib);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbos[PE::ASTEROID1_MESH]);
        glVertexAttribPointer (vertexPositionAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibos[PE::ASTEROID1_MESH]);
    glBindVertexArray (0);
    
    // Spaceship VBOs/IBOs
    GLfloat spaceshipVertices[] =
    {
        -0.05f, -0.1f, 0.0f,
        -0.05f, 0.1f, 0.0f,
        0.1f,  0.0f, 0.0f,
    };
    GLuint spaceshipIndices[] = { 0, 1, 2 };
    
    m_numIndices[PE::SPACESHIP_MESH] = 3;
    
    glBindBuffer( GL_ARRAY_BUFFER, m_vbos[PE::SPACESHIP_MESH]);
    glBufferData( GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), spaceshipVertices, GL_STATIC_DRAW );
    
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_ibos[PE::SPACESHIP_MESH] );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, m_numIndices[PE::SPACESHIP_MESH] * sizeof(GLuint), spaceshipIndices, GL_STATIC_DRAW );
    
    // VAO
    glBindVertexArray (m_vaos[PE::SPACESHIP_MESH]);
        glEnableVertexAttribArray (vertexPositionAttrib);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbos[PE::SPACESHIP_MESH]);
        glVertexAttribPointer (vertexPositionAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibos[PE::SPACESHIP_MESH]);
    glBindVertexArray (0);
    
    // UFO VBOs/IBOs
    GLfloat ufoVertices[] =
    {
        -0.1f, -0.1f, 0.0f,
        0.1f, -0.1f, 0.0f,
        0.0f,  0.1f, 0.0f,
    };
    GLuint ufoIndices[] = { 0, 1, 2 };
    
    m_numIndices[PE::UFO_MESH] = 3;
    
    glBindBuffer( GL_ARRAY_BUFFER, m_vbos[PE::UFO_MESH]);
    glBufferData( GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), ufoVertices, GL_STATIC_DRAW );
    
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_ibos[PE::UFO_MESH] );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, 3 * sizeof(GLuint), ufoIndices, GL_STATIC_DRAW );

    // VAO
    glBindVertexArray (m_vaos[PE::UFO_MESH]);
        glEnableVertexAttribArray (vertexPositionAttrib);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbos[PE::UFO_MESH]);
        glVertexAttribPointer (vertexPositionAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibos[PE::UFO_MESH]);
    glBindVertexArray (0);
#endif
    return true;
}

bool CGraphicsProcessor::shutdown()
{
#if 0
    glDeleteBuffers(PE::NUM_MESH, m_vbos);
//    glDeleteBuffers(PE::NUM_MESH, m_vbos);
#endif
    SDL_GL_DeleteContext( m_glcontext );
    SDL_DestroyWindow( m_window ); // m_screen is freed by SDL_DestroyWindow
    m_window = nullptr;
    
    TTF_Quit();
    SDL_Quit();
    
    return true;
}


glm::u32 CGraphicsProcessor::createProgram(const char *vertexShaderSource, const char *fragmentShaderSource)
{
    GLuint shaderProgram = 0;
    
    if(!vertexShaderSource && !vertexShaderSource)
    {
        return 0;
    }
    
    shaderProgram = glCreateProgram();
    
    if(vertexShaderSource)
    {
        GLuint vertexShader = glCreateShader( GL_VERTEX_SHADER );
        
        glShaderSource( vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader( vertexShader );
        
        GLint status = GL_FALSE;
        glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &status );
        
        if( status != GL_TRUE )
        {
            glDeleteShader(vertexShader);
            glDeleteProgram(shaderProgram);
            CFileLogger::logFormat( "Unable to compile vertex shader %s.\n", vertexShaderSource);
            return 0;
        }
        
        glAttachShader(shaderProgram, vertexShader);
        glDeleteShader(vertexShader);
    }
    
    if(fragmentShaderSource)
    {
        GLuint fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
        
        glShaderSource( fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader( fragmentShader );
        
        GLint status = GL_FALSE;
        glGetShaderiv( fragmentShader, GL_COMPILE_STATUS, &status );
        
        if( status != GL_TRUE )
        {
            glDeleteShader(fragmentShader);
            glDeleteProgram(shaderProgram);
            CFileLogger::logFormat( "Unable to compile fragment shader %s.\n", fragmentShaderSource);
            return 0;
        }
        
        glAttachShader(shaderProgram, fragmentShader);
        glDeleteShader(fragmentShader);
    }
    
    
    glLinkProgram(shaderProgram);
    
    GLint status = GL_TRUE;
    glGetProgramiv( shaderProgram, GL_LINK_STATUS, &status );
    
    if( status != GL_TRUE )
    {
        glDeleteProgram(shaderProgram);
        CFileLogger::log( "Error linking program.\n");
        return 0;
    }
    
    return shaderProgram;
}

void CGraphicsProcessor::useProgram(const glm::u32& programId) const
{
    if(programId > 0)
    {
        glUseProgram(programId);
    }
    else
    {
        glUseProgram(m_basicProgram);
    }
}

void CGraphicsProcessor::process(const IProcessible* processible)
{
/*
    if(m_entities == nullptr)
    {
        return;
    }
*/
    glClear( GL_COLOR_BUFFER_BIT );
    
    for (glm::u32 id = 0; id < PE::MAX_ENTITIES; ++id)
    {
/*
        if (m_entities[id].systemIds & PE::GRAPHICS_SYSTEM)
        {
            glm::mat4 rotationMatrix;
            rotationMatrix = glm::rotate(rotationMatrix, m_entities[id].angle, glm::vec3(0.0f, 0.0f, 1.0f));
            
            glm::mat4 translationMatrix;
            translationMatrix = glm::translate(translationMatrix, m_entities[id].position);
            
            glm::mat4 modelMatrix = translationMatrix * rotationMatrix;
            
            glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));
            
            if(m_entities[id].mesh >= 0)
            {
                glBindVertexArray (m_vaos[m_entities[id].mesh]);
                glDrawElements (GL_LINE_LOOP, m_numIndices[m_entities[id].mesh], GL_UNSIGNED_INT, 0);
                glBindVertexArray (0);
            }

        }
*/
    }
    
    glFlush();
    
    SDL_GL_SwapWindow( m_window );
}

/*
void CGraphicsProcessor::receive(const CMessage& msg)
{
    if (msg.getReceivers() & PE::GRAPHICS_LISTENER)
    {
        if (msg.getMessageIds() & PE::ENTITIES_MESSAGE)
        {
            attachEntities((SEntity*) msg.getData());
        }
    }
}
*/

