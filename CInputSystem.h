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

#ifndef CINPUTSYSTEM_H
#define CINPUTSYSTEM_H

#include <SDL2/SDL.h>

#include "ISystem.h"

#include <iostream>

class CInputSystem : public ISystem
{
    
public:
    
    CInputSystem() : m_commandsStatus(0) {};
    virtual ~CInputSystem() {};
    
    // ISystem specific methods
    bool    init();
    
    bool    shutdown();
    
    void    run();
    
    void    receive(const CMessage& msg);
    
private:
    
    glm::u32   m_commandsStatus;
};
#endif
