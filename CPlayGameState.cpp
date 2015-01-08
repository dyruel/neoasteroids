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

void CPlayGameState::init(CNeoAsteroids* neoAsteroids)
{
//    glm::u32 i;
    
    m_neoAsteroids = neoAsteroids;
    
    m_level = 1;
    m_lives = 3;
    m_score = 0;
    
    m_world.init(20);
    
    m_world.addSystem<CGraphicsSystem>();
    m_world.addSystem<CInputSystem>();
/*
    m_numAsteroids = 4;
    for (i = 0; i < m_numAsteroids && i < MAX_ASTEROIDS; ++i) {
        m_asteroids[i].init();
    }
    
    m_numBullets = 0;
 */
}

void CPlayGameState::pause()
{
    
}

void CPlayGameState::resume()
{
    
}

void CPlayGameState::shutdown()
{
    m_world.shutdown();
}

void CPlayGameState::update(const glm::u32& delta)
{
//    glm::u32 i;
/*
    m_spaceship.update(delta);
    
    m_ufo.update(delta);
    
    for (i = 0; i < m_numAsteroids && i < MAX_ASTEROIDS; ++i) {
        m_asteroids[i].update(delta);
    }
    
    for (i = 0; i < m_numBullets && i < MAX_BULLETS; ++i) {
        m_bullets[i].update(delta);
    }
 */
    m_world.update(delta);
    
    m_neoAsteroids->quit();
}

void CPlayGameState::display()
{
//    glm::u32 i;
//    IVideoDevice* videoDevice = m_gameEngine->getVideoDevice();
    
//    videoDevice->beginFrame();
/*
    m_spaceship.display();
    
    for (i = 0; i < m_numAsteroids && i < MAX_ASTEROIDS; ++i) {
        m_asteroids[i].display();
    }
*/
//    videoDevice->endFrame();
    
//    SDL_Delay(2000);
}

glm::u32 CPlayGameState::addAsteroid()
{
    return 0;
}


glm::u32 addSpaceship()
{
     return 0;
}

glm::u32 addUfo()
{
     return 0;
}

glm::u32 addBullet()
{
     return 0;
}

void CPlayGameState::nextLevel()
{
    
}