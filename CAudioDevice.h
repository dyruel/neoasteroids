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

#ifndef CAUDIODEVICE_H
#define CAUDIODEVICE_H

#ifdef WIN32
	#include <SDL.h>
	#include <SDL_mixer.h>
#elif __APPLE__
	#include <SDL/SDL.h>
	#include <SDL2_mixer/SDL_mixer.h>
#endif

#include "CSound.h"
#include "CMusic.h"
#include "CFileLogger.h"

#include <iostream>

class CAudioDevice
{
    
public:
    
    CAudioDevice() {};
    virtual ~CAudioDevice() {};
    
    bool    init();
    
    bool    shutdown();
    
    CSound  loadSound     (const char * file) const;
    
    void    freeSound(CSound* sound) const;
    
    CMusic  loadMusic     (const char * file) const;
    
    void    freeMusic(CMusic* music) const;
        
private:

    
};
#endif
