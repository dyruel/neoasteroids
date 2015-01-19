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

#include "CSpace.h"


SEntity* CSpace::getEntities()
{
    return m_entities;
}

glm::u32 CSpace::addEntity()
{
    for (glm::u32 id = 0; id < CST::MAX_ENTITIES; ++id)
    {
        if(m_entities[id].components == NULL_COMPONENT)
        {
            return id;
        }
    }
    
    //        CFileLogger::log( "No more entities left.\n");
    
    return CST::MAX_ENTITIES;
}

void CSpace::removeEntity(const glm::u32& id)
{
    assert(id < CST::MAX_ENTITIES && m_entities != nullptr);
    
    m_entities[id].components = NULL_COMPONENT;
}

void CSpace::removeAllEntities()
{
    for (glm::u32 id = 0; id < CST::MAX_ENTITIES; ++id)
    {
        m_entities[id].components = NULL_COMPONENT;
    }
}