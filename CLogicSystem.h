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

#ifndef CLOGICSYSTEM_H
#define CLOGICSYSTEM_H

#include "ISystem.h"

#include "IGameState.h"

#include "CIntroGameState.h"


class CLogicSystem : public ISystem
{
    
public:
    CLogicSystem() : m_currentState(-1) {};
    ~CLogicSystem() {};
    
    // ISystem specific methods
    bool    init();
    
    bool    shutdown();
    
    void    run();
    
    void    receive(const CMessage& msg);
    
    
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
};
#endif
