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
    for (glm::u32 i = 0; i < MAX_ENTITIES; ++i) {
        mask[i] = COMPONENT_NONE;
    }
}

CWorld::~CWorld()
{
    
}

glm::u32 CWorld::addEntity()
{
    for (glm::u32 i = 0; i < MAX_ENTITIES; ++i)
    {
        if(mask[i] == COMPONENT_NONE)
        {
            return i;
        }
    }
    
    CFileLogger::log( "No more entities left.\n");
    
    return MAX_ENTITIES;
}

void CWorld::removeEntity(const glm::u32& id)
{
    assert(id < MAX_ENTITIES);
    mask[id] = COMPONENT_NONE;
}
