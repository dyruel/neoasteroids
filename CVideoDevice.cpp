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

#include "CVideoDevice.h"

bool CVideoDevice::init()
{
    
    if( SDL_InitSubSystem(SDL_INIT_VIDEO) < 0 )
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
    
    return true;
}

bool CVideoDevice::shutdown()
{
    SDL_GL_DeleteContext( m_glcontext );
    SDL_DestroyWindow( m_window ); // m_screen is freed by SDL_DestroyWindow
    m_window = nullptr;
    
    TTF_Quit();
    return true;
}

void CVideoDevice::beginRender() const
{
    glClear( GL_COLOR_BUFFER_BIT );    
}

void CVideoDevice::endRender() const
{
    glFlush();
    
    SDL_GL_SwapWindow( m_window );
}


glm::u32 CVideoDevice::createProgram(const char *vertexShaderSource, const char *fragmentShaderSource)
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

void CVideoDevice::useProgram(const glm::u32& programId) const
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

CTexture CVideoDevice::loadTexture(const char *file) const
{
    SDL_Surface *surface;
    CTexture    tex;
    int mode;
    
    surface = IMG_Load(file);

    if (!surface)
    {
        CFileLogger::logFormat( "Failed to load image file %s! SDL_image Error: %s\n", file , IMG_GetError() );
        return tex;
    }
    
    if (surface->format->BytesPerPixel == 3)
    {
        mode = GL_RGB;
        
    }
    else if (surface->format->BytesPerPixel == 4)
    {
        mode = GL_RGBA;
        
    }
    else
    {
        SDL_FreeSurface( surface );
        return tex;
    }
    

    glGenTextures(1, &tex.m_textureId);
    
    glBindTexture(GL_TEXTURE_2D, tex.m_textureId);
    
    glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    SDL_FreeSurface( surface );
    
    return tex;
}


void CVideoDevice::freeTexture(CTexture* texture) const
{
    
}