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

#ifndef COGLVIDEODEVICE_H
#define COGLVIDEODEVICE_H

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
#include <iostream>

#include "IVideoDevice.h"
#include "CFileLogger.h"

class COGLVideoDevice : public IVideoDevice
{
    
public:
    COGLVideoDevice() {};
    ~COGLVideoDevice() {};
    
    bool        init        ();
    bool        shutdown    ();
    
    void        beginFrame  () const;
    void        endFrame    () const;
    
    // Matrices : projection, view, model
    
    
    
    // Shaders management
    
    glm::u32    createProgram   (const char *vertexShader, const char *fragmentShader);
    void        useProgram      (const glm::u32& programId) const;

    // Buffers management
    
//    glm::u32    createBuffer    (const glm::u64& size, const EBufferType& type);
//    void        fillBuffer      (const glm::u32& id, const void* data);
private:
    
    COGLVideoDevice(const COGLVideoDevice&){};
    COGLVideoDevice& operator=(const COGLVideoDevice& ){ return *this;};
    
    // OpenGL
    GLuint  m_basicProgram;
    
    // SDL
    SDL_Window*  m_window;
    SDL_GLContext m_glcontext;
    
};

#endif