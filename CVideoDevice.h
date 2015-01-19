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

#ifndef CVIDEODEVICE_H
#define CVIDEODEVICE_H

#ifdef WIN32
    #include <GL/glew.h>
#elif __APPLE__
    #define GL3_PROTOTYPES 1
    #include <OpenGL/gl3.h>
#else
    #define GL3_PROTOTYPES 1
    #include <GL3/gl3.h>
#endif

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Common.h"
#include "CFileLogger.h"
#include "CTexture.h"

class CVideoDevice
{
    
public:
    
    CVideoDevice()
     : m_window(nullptr), m_winWidth(800), m_winHeight(600) {};
    virtual ~CVideoDevice() {};
    
    bool    init();
    
    bool    shutdown();
    
    void    beginRender() const;
    
    void    endRender() const;
    
    // Shaders methods
    
    glm::u32    createProgram   (const char *vertexShader, const char *fragmentShader);
    void        useProgram      (const glm::u32& programId) const;
    
    CTexture    loadTexture     (const char * file) const;
    void        freeTexture     (CTexture* texture) const;
    
private:
    glm::u32    m_winWidth;
    glm::u32    m_winHeight;
    
    // OpenGL variables
    GLuint  m_basicProgram;
    //    GLuint  m_vbos[PE::NUM_MESH];
    //    GLuint  m_ibos[PE::NUM_MESH];
    //    GLuint  m_vaos[PE::NUM_MESH];
    //    GLsizei m_numIndices[PE::NUM_MESH];
    GLint   m_modelMatrix;
    
    // SDL variables
    SDL_Window*     m_window;
    SDL_GLContext   m_glcontext;
};
#endif
