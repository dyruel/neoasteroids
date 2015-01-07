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

#include "CWorld.h"

CWorld::CWorld()
{
    for (glm::u32 id = 0; id < MAX_ENTITIES; ++id)
    {
        m_entities[id].mask = COMPONENT_NONE;
    }
}

CWorld::~CWorld()
{
    
}

void CWorld::addSystem(std::unique_ptr<ISystem>& system)
{
    assert(system != nullptr);
    
    system->init(this);
    
    m_systems.push_back(std::move(system));
}

void CWorld::broadcast(const glm::i32& msg)
{
    for(auto & system : m_systems)
    {
        system->receive(msg);
    }
}

void CWorld::update()
{
    for(auto & system : m_systems)
    {
        system->update();
    }
}

glm::u32 CWorld::addEntity()
{
    for (glm::u32 id = 0; id < MAX_ENTITIES; ++id)
    {
        if(m_entities[id].mask == COMPONENT_NONE)
        {
            return id;
        }
    }
    
    CFileLogger::log( "No more entities left.\n");
    
    return MAX_ENTITIES;
}

void CWorld::removeEntity(const glm::u32& id)
{
    assert(id < MAX_ENTITIES);
    m_entities[id].mask = COMPONENT_NONE;
}


glm::u32 CWorld::addAsteroid()
{
    glm::u32 id = addEntity();
    
    if (id == MAX_ENTITIES) {
        return MAX_ENTITIES;
    }
    
    m_entities[id].mask = COMPONENT_POSITION | COMPONENT_VELOCITY | COMPONENT_GEOMETRY;
    
    m_entities[id].velocity.m_speed = .5f;
    
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

    return id;
}

glm::u32 CWorld::addSpaceship()
{
    return MAX_ENTITIES;
}

glm::u32 CWorld::addUfo()
{
    return MAX_ENTITIES;
}

glm::u32 CWorld::addBullet()
{
    return MAX_ENTITIES;
}




