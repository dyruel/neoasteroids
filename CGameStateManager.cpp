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


void CGameStateManager::change(IGameState* state)
{
    if ( !m_gameStates.empty() )
    {
        m_gameStates.back()->shutdown();
        m_gameStates.pop_back();
    }
    
    m_gameStates.push_back(state);
    m_gameStates.back()->init();
    
    state->m_gameStateManager = this;
}

void CGameStateManager::push(IGameState* state)
{
    if ( !m_gameStates.empty() )
    {
        m_gameStates.back()->pause();
    }
    
    m_gameStates.push_back(state);
    m_gameStates.back()->init();
    
    state->m_gameStateManager = this;
}

void CGameStateManager::pop()
{
    if ( !m_gameStates.empty() )
    {
        m_gameStates.back()->shutdown();
        m_gameStates.pop_back();
    }
    
    if ( !m_gameStates.empty() )
    {
        m_gameStates.back()->resume();
    }
}

CGameStateManager::IGameState* CGameStateManager::current()
{
    return m_gameStates.back();
}

bool CGameStateManager::empty()
{
    return m_gameStates.empty();
}

void CGameStateManager::clear()
{
    while ( !m_gameStates.empty() ) {
        m_gameStates.back()->shutdown();
        m_gameStates.pop_back();
    }
}
