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

#include "CPlaySpace.h"

#include <iostream>

//CPlayGameState CPlayGameState::m_playGameState;

void CPlaySpace::init()
{
    std::cout << "Play init" << std::endl;
    m_level = 1;
    m_lives = 3;
    m_score = 0;
    
    m_spaceshipId = 0;

    prepareLevel(m_level);
}

void CPlaySpace::pause()
{
    
}

void CPlaySpace::resume()
{
    
}

void CPlaySpace::shutdown()
{
 std::cout << "Play shutdown" << std::endl;
}

void CPlaySpace::update()
{
    

}

/*
void CPlaySpace::receive(const CMessage& msg)
{


}
*/



void CPlaySpace::resetSpaceship()
{
    SEntity* m_entities = getEntities();
    
    m_entities[m_spaceshipId].position.x = .0f;
    m_entities[m_spaceshipId].position.y = .0f;
    m_entities[m_spaceshipId].position.z = .0f;
    
    m_entities[m_spaceshipId].velocity.x = .0f;
    m_entities[m_spaceshipId].velocity.y = .0f;
    m_entities[m_spaceshipId].velocity.z = .0f;
    
    m_entities[m_spaceshipId].accel.x = .0f;
    m_entities[m_spaceshipId].accel.y = .0f;
    m_entities[m_spaceshipId].accel.z = .0f;
    
//    m_entities[m_spaceshipId].speed = .0f;
    m_entities[m_spaceshipId].angle = CST::PI / 2;
}


void CPlaySpace::addAsteroid()
{
    glm::u32 id = addEntity();
    
    if (id == CST::MAX_ENTITIES)
    {
        return;
    }
    
    m_entities[id].components = RENDER_COMPONENT;
    
    m_entities[id].position.x = (CUtils::getRandomNumber() / 2) + 0.5f;
    
    if (CUtils::getRandomNumber() < 0.5f)
    {
        m_entities[id].position.x *= -1.f;
    }
    
    m_entities[id].position.y = (CUtils::getRandomNumber() / 2) + 0.5f;
    
    if (CUtils::getRandomNumber() < 0.5f)
    {
        m_entities[id].position.y *= -1.f;
    }
    
    m_entities[id].position.z = .0f;
    
    
    m_entities[id].angle = 2 * CST::PI * CUtils::getRandomNumber();
    
    m_entities[id].velocity.x = cosf( m_entities[id].angle );
    m_entities[id].velocity.y = sinf( m_entities[id].angle );
    
    m_entities[id].velocity *= 0.5f;

}


void CPlaySpace::addSpaceship()
{
    glm::u32 id = addEntity();
    
    if (id == CST::MAX_ENTITIES)
    {
        return;
    }
    
    m_spaceshipId = id;
    
    m_entities[id].components = RENDER_COMPONENT;
    
    resetSpaceship();

}

void CPlaySpace::addUfo()
{

}

void CPlaySpace::addBullet()
{

}

void CPlaySpace::prepareLevel(const glm::u32& level)
{
    assert(level <= 200);
    
    removeAllEntities();
    
    addSpaceship();
    
    glm::u32 numAsteroids = 4 + level;
    
    if (numAsteroids > 13) {
        numAsteroids = 13;
    }
    
    for (glm::u32 i = 0; i < numAsteroids; ++i) {
        addAsteroid();
    }

}