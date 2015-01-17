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
//    glm::u32 i;
    
    m_level = 1;
    m_lives = 3;
    m_score = 0;
    
    m_spaceshipId = 0;
    
    CMessage msg;
    
    msg.setReceivers(PE::ALL_LISTENER);
    msg.setSender(PE::LOGIC_LISTENER);
    
    msg.setMessageIds(PE::ENTITIES_MESSAGE);
    
    msg.setData(m_entities);
    
    m_logicSystem->getMessageHandler()->post(msg);
    
    prepareLevel(m_level);
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

void CPlayGameState::update()
{
    
    if (m_commandsStatus & PE::A_COMMAND)
    {
        addBullet();
    }
    
    for (glm::u32 id = 0; id < PE::MAX_ENTITIES; ++id)
    {
        if (m_entities[id].systemIds & PE::LOGIC_SYSTEM)
        {
            switch (m_entities[id].type) {
                    
                case PE::SPACESHIP_ENTITY:
                    if (m_commandsStatus & PE::RIGHT_COMMAND)
                    {
                        m_entities[id].angle -= 5.f * PE::DELTA_TIME;
                    }
                    else if (m_commandsStatus & PE::LEFT_COMMAND)
                    {
                        m_entities[id].angle += 5.f * PE::DELTA_TIME;
                    }
                    
                    if (m_commandsStatus & PE::UP_COMMAND)
                    {
                        m_entities[id].accel.x = cosf( m_entities[id].angle );
                        m_entities[id].accel.y = sinf( m_entities[id].angle );
                    }
                    else
                    {
                        m_entities[id].accel.x = 0;
                        m_entities[id].accel.y = 0;
                    }
                    
                default:
                    break;
            }
        }
    }
}

void CPlayGameState::receive(const CMessage& msg)
{

    if (msg.getMessageIds() & PE::COMMAND_MESSAGE)
    {
        m_commandsStatus = *((glm::u32*) msg.getData());
    }

}


glm::u32 CPlayGameState::addEntity()
{
    assert(m_entities != nullptr);
    
    for (glm::u32 id = 0; id < PE::MAX_ENTITIES; ++id)
    {
        if(m_entities[id].systemIds == PE::NULL_SYSTEM)
        {
            return id;
        }
    }
    
    CFileLogger::log( "No more entities left.\n");

    return PE::MAX_ENTITIES;
}

void CPlayGameState::removeEntity(const glm::u32& id)
{
    /*
    assert(id < PE::MAX_ENTITIES && m_entities != nullptr);
    m_entities[id].mask = NULL_SYSTEM;*/
}

void CPlayGameState::removeAllEntities()
{
    for (glm::u32 id = 0; id < PE::MAX_ENTITIES; ++id)
    {
        m_entities[id].systemIds = PE::NULL_SYSTEM;
    }
}

void CPlayGameState::resetSpaceship()
{
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
    m_entities[m_spaceshipId].angle = PE::PI / 2;
}


void CPlayGameState::addAsteroid()
{
    glm::u32 id = addEntity();
    
    if (id == PE::MAX_ENTITIES)
    {
        return;
    }
    
    m_entities[id].systemIds = PE::GRAPHICS_SYSTEM | PE::LOGIC_SYSTEM;
    
    m_entities[id].type = PE::ASTEROID_ENTITY;
    
    m_entities[id].mesh = PE::ASTEROID1_MESH;
    
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
    
    
    m_entities[id].angle = 2 * PE::PI * CUtils::getRandomNumber();
    
    m_entities[id].velocity.x = cosf( m_entities[id].angle );
    m_entities[id].velocity.y = sinf( m_entities[id].angle );
    
    m_entities[id].velocity *= 0.5f;

}


void CPlayGameState::addSpaceship()
{
    glm::u32 id = addEntity();
    
    if (id == PE::MAX_ENTITIES)
    {
        return;
    }
    
    m_spaceshipId = id;
    
    m_entities[id].systemIds = PE::GRAPHICS_SYSTEM | PE::LOGIC_SYSTEM;
    
    m_entities[id].type = PE::SPACESHIP_ENTITY;
    m_entities[id].mesh = PE::SPACESHIP_MESH;
    
    resetSpaceship();

}

void CPlayGameState::addUfo()
{

}

void CPlayGameState::addBullet()
{

}

void CPlayGameState::prepareLevel(const glm::u32& level)
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