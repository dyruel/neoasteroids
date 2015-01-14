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
    
    for (glm::u32 id = 0; id < PE::MAX_ENTITIES; ++id)
    {
        if (m_entities[id].systemIds & PE::GRAPHICS_SYSTEM)
        {
            //SEntity e = m_entities[id];
            
        }
        
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
    
    m_entities[m_spaceshipId].m_speed = .0f;
}


void CPlayGameState::addAsteroid()
{
    glm::u32 id = addEntity();
    
    if (id == PE::MAX_ENTITIES)
    {
        return;
    }
    
    m_entities[id].systemIds = PE::GRAPHICS_SYSTEM;
    
    m_entities[id].type = PE::ASTEROID_ENTITY;
    m_entities[id].mesh = PE::ASTEROID1_MESH;
    
    m_entities[id].m_speed = .5f;
    
    m_entities[id].position.x = .0f;
    m_entities[id].position.y = .0f;
    m_entities[id].position.z = .0f;
    
    /*
    m_entities[id].geometry.m_numVertices = 4;
    m_entities[id].geometry.m_vertices[0].x = 0.f; m_entities[id].geometry.m_vertices[0].y = 0.f;
    m_entities[id].geometry.m_vertices[1].x = 0.f; m_entities[id].geometry.m_vertices[1].y = 1.f;
    m_entities[id].geometry.m_vertices[2].x = 1.f; m_entities[id].geometry.m_vertices[2].y = 1.f;
    m_entities[id].geometry.m_vertices[3].x = 1.f; m_entities[id].geometry.m_vertices[3].y = 0.f;
    
    m_entities[id].geometry.m_numIndices = 4;
    m_entities[id].geometry.m_indices[0] = 0;
    m_entities[id].geometry.m_indices[1] = 1;
    m_entities[id].geometry.m_indices[2] = 2;
    m_entities[id].geometry.m_indices[3] = 3;
    */
}


void CPlayGameState::addSpaceship()
{
    glm::u32 id = addEntity();
    
    if (id == PE::MAX_ENTITIES)
    {
        return;
    }
    
    m_spaceshipId = id;
    
    m_entities[id].systemIds = PE::GRAPHICS_SYSTEM;
    
    m_entities[id].type = PE::SPACESHIP_ENTITY;
    m_entities[id].mesh = PE::SPACESHIP_MESH;
    
    resetSpaceship();
    
    /*
    m_entities[id].geometry.m_numVertices = 3;
    m_entities[id].geometry.m_vertices[0].x = 0.f; m_entities[id].geometry.m_vertices[0].y = 0.f;
    m_entities[id].geometry.m_vertices[1].x = 1.f; m_entities[id].geometry.m_vertices[1].y = 0.f;
    m_entities[id].geometry.m_vertices[2].x = .5f; m_entities[id].geometry.m_vertices[2].y = 1.f;
    
    m_entities[id].geometry.m_numIndices = 3;
    m_entities[id].geometry.m_indices[0] = 0;
    m_entities[id].geometry.m_indices[1] = 1;
    m_entities[id].geometry.m_indices[2] = 2;
    */
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