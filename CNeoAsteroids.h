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

#ifndef CNEOASTEROIDS_H
#define CNEOASTEROIDS_H

#include <iostream>
#include <vector>

#include "Common.h"
#include "CMemory.h"
#include "CUtils.h"
#include "IGameState.h"

#include "CIntroGameState.h"
#include "CMenuGameState.h"
#include "CPlayGameState.h"



class CNeoAsteroids
{
public:
    
    CNeoAsteroids()
    : m_running(true), m_lastTime(0), m_currentState(-1) {}
    virtual ~CNeoAsteroids(){}
    
    // Main game engine methods
    
    bool init(int& argc, char** argv);
    
    bool shutdown();
    
    void quit();
    
    bool running();
    
    void update();
    
    void display();
    
    // Game states management
    
    void changeState(IGameState* state);
    
    void pushState(IGameState* state);
    
    void popState();
    
    IGameState* currentState();
    
    bool hasStates();
    
    void removeAllStates();
    
private:
    
    glm::i32    m_currentState;
    IGameState* m_states[PE::MAX_GAME_STATES];

    glm::u32    m_lastTime;
    glm::u8     m_running;
};

#endif
