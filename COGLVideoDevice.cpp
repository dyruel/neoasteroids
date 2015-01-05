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

#include "COGLVideoDevice.h"


bool COGLVideoDevice::init()
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
    
    glClearColor( 0.f, 1.f, 0.f, 1.f );
    
    m_basicProgram = glCreateProgram();
    
    GLuint vertexShader = glCreateShader( GL_VERTEX_SHADER );
    
    const GLchar* vertexShaderSource[] =
    {
        "#version 140\nin vec2 LVertexPos2D; void main() { gl_Position = vec4( LVertexPos2D.x, LVertexPos2D.y, 0, 1 ); }"
    };
    

    glShaderSource( vertexShader, 1, vertexShaderSource, NULL );
    
    glCompileShader( vertexShader );
    
    GLint vShaderCompiled = GL_FALSE;
    glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &vShaderCompiled );
    
    if( vShaderCompiled != GL_TRUE )
    {
        CFileLogger::logFormat( "Unable to compile vertex shader.\n");
        return false;
    }
    else
    {
        glAttachShader( m_basicProgram, vertexShader );
        
        GLuint fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
        
        const GLchar* fragmentShaderSource[] =
        {
            "#version 140\nout vec4 LFragment; void main() { LFragment = vec4( 1.0, 1.0, 1.0, 1.0 ); }"
        };
        
        glShaderSource( fragmentShader, 1, fragmentShaderSource, NULL );
        
        glCompileShader( fragmentShader );
        

        GLint fShaderCompiled = GL_FALSE;
        glGetShaderiv( fragmentShader, GL_COMPILE_STATUS, &fShaderCompiled );
        
        if( fShaderCompiled != GL_TRUE )
        {
            CFileLogger::log( "Unable to compile fragment shader.\n");
            return false;
        }
        else
        {
            glAttachShader( m_basicProgram, fragmentShader );
            
            glLinkProgram( m_basicProgram );
            

            GLint programSuccess = GL_TRUE;
            glGetProgramiv( m_basicProgram, GL_LINK_STATUS, &programSuccess );
            
            if( programSuccess != GL_TRUE )
            {
                CFileLogger::log( "Error linking program.\n");
                return false;
            }
            else
            {
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
            }
        }
    }
    
    return true;
}

bool COGLVideoDevice::shutdown()
{

    SDL_Delay(2000);
    SDL_GL_DeleteContext( m_glcontext );
    SDL_DestroyWindow( m_window ); // m_screen is freed by SDL_DestroyWindow
    m_window = nullptr;

    TTF_Quit();
    SDL_Quit();
    
    return true;
}

void COGLVideoDevice::beginFrame() const
{
    glClear( GL_COLOR_BUFFER_BIT );
    
    glUseProgram( m_basicProgram );
}

void COGLVideoDevice::endFrame() const
{
    glUseProgram( NULL );
    SDL_GL_SwapWindow( m_window );
}