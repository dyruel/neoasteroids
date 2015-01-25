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

#ifndef CGAMESTATEMANAGER_H
#define CGAMESTATEMANAGER_H

#include "IReceiver.h"

#include "IGameState.h"

#include "CIntroGameState.h"


class CGameStateManager : public IReceiver
{
    
public:
    CGameStateManager() : m_currentState(-1) {};
    ~CGameStateManager() {};
    

    bool    init();
    
    bool    shutdown();
    
//    void    run();
    
    // IReceiver
    
    void receive(const CMessage& msg);
    
    // Game states management
    
    void changeState(IGameState* state);
    
    void pushState(IGameState* state);
    
    void popState();
    
    IGameState* currentState();
    
    bool hasStates();
    
    void removeAllStates();
    
private:
    
    glm::i32    m_currentState;
    IGameState* m_states[CST::MAX_GAME_STATES];
};
#endif
