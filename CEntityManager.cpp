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

#include "CEntityManager.h"

CEntityManager::CEntityManager()
{
    for (glm::u32 id = 0; id < MAX_ENTITIES; ++id) {
        mask[id] = COMPONENT_NONE;
    }
}

CEntityManager::~CEntityManager()
{
    
}

void CEntityManager::display()
{
    for (glm::u32 id = 0; id < MAX_ENTITIES; ++id)
    {
        if (mask[id] & (COMPONENT_GEOMETRY | COMPONENT_POSITION)) {
            
        }
    }
}

glm::u32 CEntityManager::addEntity()
{
    for (glm::u32 id = 0; id < MAX_ENTITIES; ++id)
    {
        if(mask[id] == COMPONENT_NONE)
        {
            return id;
        }
    }
    
    CFileLogger::log( "No more entities left.\n");
    
    return MAX_ENTITIES;
}

void CEntityManager::removeEntity(const glm::u32& id)
{
    assert(id < MAX_ENTITIES);
    mask[id] = COMPONENT_NONE;
}


glm::u32 CEntityManager::addAsteroid()
{
    glm::u32 id = addEntity();
    
    if (id == MAX_ENTITIES) {
        return MAX_ENTITIES;
    }
    
    mask[id] = COMPONENT_POSITION | COMPONENT_VELOCITY | COMPONENT_GEOMETRY;
    
    velocity[id].m_speed = .5f;
    
    geometry[id].m_numVertices = 4;
    geometry[id].m_vertices[0].x = 0.f; geometry[id].m_vertices[0].y = 0.f;
    geometry[id].m_vertices[1].x = 0.f; geometry[id].m_vertices[1].y = 1.f;
    geometry[id].m_vertices[2].x = 1.f; geometry[id].m_vertices[2].y = 1.f;
    geometry[id].m_vertices[3].x = 1.f; geometry[id].m_vertices[3].y = 0.f;
    
    geometry[id].m_numIndices = 4;
    geometry[id].m_indices[0] = 0;
    geometry[id].m_indices[1] = 1;
    geometry[id].m_indices[2] = 2;
    geometry[id].m_indices[3] = 3;

    return id;
}

glm::u32 CEntityManager::addSpaceship()
{
    return MAX_ENTITIES;
}

glm::u32 CEntityManager::addUfo()
{
    return MAX_ENTITIES;
}

glm::u32 CEntityManager::addBullet()
{
    return MAX_ENTITIES;
}




