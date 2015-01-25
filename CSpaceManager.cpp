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

#include "CSpaceManager.h"


bool CSpaceManager::init()
{
    return true;
}

bool CSpaceManager::shutdown()
{
    return true;
}

/*
void CGameStateManager::receive(const CMessage& msg)
{
    switch (msg.getMessageId())
    {
        case CHANGE_STATE_MSG:
            changeState( (IGameState*) msg.getData() );
            break;
            
        case PUSH_STATE_MSG:
            pushState( (IGameState*) msg.getData() );
            break;
            
        default:
            if ( hasStates() )
            {
                m_states[m_currentState]->receive(msg);
            }
            break;
    }
}
*/

void CSpaceManager::changeSpace(CSpace* space)
{
	if ( hasSpaces() )
    {
		m_spaces[m_currentSpace]->shutdown();
    }
    else
    {
		++m_currentSpace;
    }
    
	m_spaces[m_currentSpace] = space;
//    state->attachGameStateManager(this);
    state->init();
}

void CSpaceManager::pushSpace(CSpace* space)
{
	assert((m_currentSpace + 1 < CST::MAX_GAME_SPACES) && (space != nullptr));
    
	if ( hasSpaces() )
    {
		m_spaces[m_currentSpace]->pause();
    }
    
	++m_currentSpace;
	m_spaces[m_currentSpace] = space;
 //   state->attachGameStateManager(this);
    state->init();
}

void CSpaceManager::popSpace()
{
	if ( hasSpaces() )
    {
		m_spaces[m_currentSpace]->shutdown();
		--m_currentSpace;
    }
    
	if ( hasSpaces() )
    {
		m_spaces[m_currentSpace]->resume();
    }
}

CSpace* CSpaceManager::currentSpace()
{
	return m_spaces[m_currentSpace];
}

bool CSpaceManager::hasSpaces()
{
	return m_currentSpace >= 0;
}

void CSpaceManager::removeAllSpaces()
{
	while (m_currentSpace >= 0) {
		m_spaces[m_currentSpace]->shutdown();
		--m_currentSpace;
    }
}


