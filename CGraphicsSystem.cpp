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

#include "CGraphicsSystem.h"


bool CGraphicsSystem::init()
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
    
    glViewport(0, 0, 800, 600);
    glClearColor( 0.5f, 0.5f, 0.5f, 1.f );
    
    m_basicProgram = createProgram(
                                   "#version 150\nin vec4 position; void main() { gl_Position = position; }",
                                   "#version 150\nout vec4 out_color; void main() { out_color = vec4( 1.0, 1.0, 1.0, 1.0 ); }"
                                   );
    glUseProgram(m_basicProgram);
    
    return true;
}

bool CGraphicsSystem::shutdown()
{
    SDL_GL_DeleteContext( m_glcontext );
    SDL_DestroyWindow( m_window ); // m_screen is freed by SDL_DestroyWindow
    m_window = nullptr;
    
    TTF_Quit();
    SDL_Quit();
    
    return true;
}


void CGraphicsSystem::beginFrame() const
{
    glClear( GL_COLOR_BUFFER_BIT );
}

void CGraphicsSystem::endFrame() const
{
    glFlush();
    SDL_GL_SwapWindow( m_window );
}


glm::u32 CGraphicsSystem::createProgram(const char *vertexShaderSource, const char *fragmentShaderSource)
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

void CGraphicsSystem::useProgram(const glm::u32& programId) const
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

void CGraphicsSystem::run()
{
//    SComponentsContainer* entities = m_world->getComponentsContainers();
    
//    glEnableClientState(GL_VERTEX_ARRAY);
    if(m_entities == nullptr)
    {
        return;
    }

    
    for (glm::u32 id = 0; id < PE::MAX_ENTITIES; ++id)
    {
        if (m_entities[id].mask & PE::GRAPHICS_LISTENER)
        {
                
        }
    }
    
    
}

void CGraphicsSystem::receive(const CMessage& msg)
{
    if (msg.getReceivers() & PE::GRAPHICS_LISTENER)
    {
        if (msg.getMessageIds() & PE::ENTITIES_MESSAGE) {
            m_entities = (SEntity*) msg.getData();
        }
    }
}


/*
 gVertexPos2DLocation = glGetAttribLocation( gProgramID, "LVertexPos2D" );
 if( gVertexPos2DLocation == -1 )
 {
 printf( "LVertexPos2D is not a valid glsl program variable!\n" );
 success = false;
 }
 else
 {
 
 glClearColor( 0.f, 0.f, 0.f, 1.f );
 
 GLfloat vertexData[] =
 {
 -0.5f, -0.5f,
 0.5f, -0.5f,
 0.5f,  0.5f,
 -0.5f,  0.5f
 };
 
 
 GLuint indexData[] = { 0, 1, 2, 3 };
 
 
 glGenBuffers( 1, &gVBO );
 glBindBuffer( GL_ARRAY_BUFFER, gVBO );
 glBufferData( GL_ARRAY_BUFFER, 2 * 4 * sizeof(GLfloat), vertexData, GL_STATIC_DRAW );
 
 
 glGenBuffers( 1, &gIBO );
 glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, gIBO );
 glBufferData( GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(GLuint), indexData, GL_STATIC_DRAW );
 }
 */