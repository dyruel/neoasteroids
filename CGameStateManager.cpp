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

#include "CGameStateManager.h"


bool CGameStateManager::init()
{
    return true;
}

bool CGameStateManager::shutdown()
{
    return true;
}

void CGameStateManager::receive(const CMessage& msg)
{
    if ( hasStates() )
    {
        m_states[m_currentState]->receive(msg);
    }
}

void CGameStateManager::changeState(IGameState* state)
{
    if ( hasStates() )
    {
        m_states[m_currentState]->shutdown();
    }
    else
    {
        ++m_currentState;
    }
    
    m_states[m_currentState] = state;
    state->attachGameStateManager(this);
    state->init();
}

void CGameStateManager::pushState(IGameState* state)
{
    assert( (m_currentState + 1 < CST::MAX_GAME_STATES) && (state != nullptr) );
    
    if ( hasStates() )
    {
        m_states[m_currentState]->pause();
    }
    
    ++m_currentState;
    m_states[m_currentState] = state;
    state->attachGameStateManager(this);
    state->init();
}

void CGameStateManager::popState()
{
    if ( hasStates() )
    {
        m_states[m_currentState]->shutdown();
        --m_currentState;
    }
    
    if ( hasStates() )
    {
        m_states[m_currentState]->resume();
    }
}

IGameState* CGameStateManager::currentState()
{
    return m_states[m_currentState];
}

bool CGameStateManager::hasStates()
{
    return m_currentState >= 0;
}

void CGameStateManager::removeAllStates()
{
    while ( m_currentState >= 0 ) {
        m_states[m_currentState]->shutdown();
        --m_currentState;
    }
}


