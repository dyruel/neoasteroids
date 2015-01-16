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

#ifndef CAUDIOSYSTEM_H
#define CAUDIOSYSTEM_H

#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>

#include "ISystem.h"
#include "CFileLogger.h"

#include <iostream>

class CAudioSystem : public ISystem
{
    
public:
    
    CAudioSystem() : m_menuMusic(nullptr) {};
    virtual ~CAudioSystem() {};
    
    // ISystem specific methods
    bool    init();
    
    bool    shutdown();
    
    void    run();
    
    void    receive(const CMessage& msg);
    
private:
    
    // Musics
    Mix_Music* m_menuMusic;
    
    // Sounds
    
};
#endif
