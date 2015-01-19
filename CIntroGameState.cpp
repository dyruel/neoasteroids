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

#include "CIntroGameState.h"

CIntroGameState CIntroGameState::m_introGameState;

void CIntroGameState::init()
{
    std::cout << "Intro init" << std::endl;
    glm::u32 id = m_space.addEntity();
    
    m_space[id].components = TRANSITION_COMPONENT;
    m_space[id].targetGameState = &CMenuGameState::instance();
}

void CIntroGameState::pause()
{
    
}

void CIntroGameState::resume()
{
    
}

void CIntroGameState::shutdown()
{
    std::cout << "Intro shutdown" << std::endl;
}

void CIntroGameState::receive(const CMessage& msg)
{
    switch (msg.getMessageId()) {
        case CHANGE_STATE_MSG:
            m_gameStateManager->changeState( (IGameState*) msg.getData() );
            break;
            
        default:
            break;
    }
}
