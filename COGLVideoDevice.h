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
    bool init();
    bool shutdown();
    
    void beginFrame() const;
    void endFrame() const;
    
    static COGLVideoDevice& instance()
    {
        return m_videoDevice;
    }
    
private:
    COGLVideoDevice() {};
    COGLVideoDevice(const COGLVideoDevice&){};
    COGLVideoDevice& operator=(const COGLVideoDevice& ){ return *this;};
    
    SDL_Window*  m_window;
//    SDL_Surface* m_screen;
    SDL_GLContext m_glcontext;
    
    static COGLVideoDevice m_videoDevice;
};

#endif