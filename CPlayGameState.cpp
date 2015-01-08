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
    
    m_graphicsSystem.init(m_entities);
    m_inputSystem.init(m_entities);
/*
    m_world.init(20);
    
 
    m_world.addSystem<CGraphicsSystem>();
    m_world.addSystem<CInputSystem>();
*/
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
    m_graphicsSystem.shutdown();
    m_inputSystem.shutdown();
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
    m_graphicsSystem.update(delta);
    m_inputSystem.update(delta);
    
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


void CPlayGameState::broadcast(const glm::i32& msg)
{
    m_graphicsSystem.receive(msg);
    m_inputSystem.receive(msg);
}


glm::u32 CPlayGameState::addEntity()
{
    assert(m_entities != nullptr);
    
    for (glm::u32 id = 0; id < m_numEntities; ++id)
    {
        if(m_entities[id].mask == COMPONENT_NONE)
        {
            return id;
        }
    }
    
    CFileLogger::log( "No more entities left.\n");
    
    return m_numEntities;
}

void CPlayGameState::removeEntity(const glm::u32& id)
{
    assert(id < m_numEntities && m_entities != nullptr);
    m_entities[id].mask = COMPONENT_NONE;
}


glm::u32 CPlayGameState::addAsteroid()
{
    return 0;
}


glm::u32 CPlayGameState::addSpaceship()
{
     return 0;
}

glm::u32 CPlayGameState::addUfo()
{
     return 0;
}

glm::u32 CPlayGameState::addBullet()
{
     return 0;
}

void CPlayGameState::nextLevel()
{
    
}