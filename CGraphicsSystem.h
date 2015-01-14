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

#ifndef CGRAPHICSSYSTEM_H
#define CGRAPHICSSYSTEM_H

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
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "ISystem.h"
#include "CFileLogger.h"

class CGraphicsSystem : public ISystem
{

public:
    CGraphicsSystem() : m_window(nullptr) {};
    virtual ~CGraphicsSystem() {};
    
    // ISystem specific methods
    bool    init();
    
    bool    shutdown();
    
    void    run();
    
    void    receive(const CMessage& msg);
    
private:
    
    // OpenGL variables
    GLuint  m_basicProgram;
    GLuint  m_vbos[PE::NUM_MESH];
    GLuint  m_ibos[PE::NUM_MESH];
    GLuint  m_vaos[PE::NUM_MESH];
    GLsizei m_numIndices[PE::NUM_MESH];
    GLint   m_modelMatrix;
    
    // SDL variables
    SDL_Window*  m_window;
    SDL_GLContext m_glcontext;
    
        
    // Shaders methods
    
    glm::u32    createProgram   (const char *vertexShader, const char *fragmentShader);
    void        useProgram      (const glm::u32& programId) const;
};

#endif
