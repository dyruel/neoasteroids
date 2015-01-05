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

#include "CPlayGameState.h"

CPlayGameState CPlayGameState::m_playGameState;

void CPlayGameState::init()
{
    glm::u32 i;
    
    m_level = 1;
    m_lives = 3;
    m_score = 0;
    m_numAsteroids = 4;
    
    for (i = 0; i < m_numAsteroids && i < MAX_ASTEROIDS; ++i) {
        m_asteroids[i].init();
    }
}

void CPlayGameState::pause()
{
    
}

void CPlayGameState::resume()
{
    
}

void CPlayGameState::shutdown()
{
    
}

void CPlayGameState::update(const glm::u32& delta)
{
    glm::u32 i;
    
    m_spaceship.update(delta);
    
    for (i = 0; i < m_numAsteroids && i < MAX_ASTEROIDS; ++i) {
        m_asteroids[i].update(delta);
    }
}

void CPlayGameState::display()
{
    glm::u32 i;
    
    m_spaceship.display();
    
    for (i = 0; i < m_numAsteroids && i < MAX_ASTEROIDS; ++i) {
        m_asteroids[i].display();
    }
    
    m_gameStateManager->clear();
}

void CPlayGameState::nextLevel()
{
    
}