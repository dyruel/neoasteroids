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

#include "CMenuSpace.h"

#include <iostream>

//CMenuGameState CMenuGameState::m_menuGameState;

void CMenuSpace::init()
{
    std::cout << "Menu init" << std::endl;
    
	/*
    glm::u32 id = m_space.addEntity();
    
    m_space[id].components = TRANSITION_COMPONENT;
    m_space[id].gameState = &CPlayGameState::instance();
    m_space[id].op = PUSH_STATE_MSG;
	*/
}

void CMenuSpace::pause()
{
    
}

void CMenuSpace::resume()
{
    
}

void CMenuSpace::shutdown()
{
std::cout << "Menu shutdown" << std::endl;
}

/*
void CMenuSpace::receive(const CMessage& msg)
{

}
*/