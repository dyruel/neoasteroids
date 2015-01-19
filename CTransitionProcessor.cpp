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

#include "CTransitionProcessor.h"

bool CTransitionProcessor::init()
{
    return true;
}

bool CTransitionProcessor::shutdown()
{
    return true;
}

void CTransitionProcessor::process(CSpace* space)
{
    SEntity* entities = space->getEntities();
    
    for (glm::u32 id = 0; id < CST::MAX_ENTITIES; ++id)
    {
        if (entities[id].components & TRANSITION_COMPONENT)
        {
            void* ptr = entities[id].targetGameState;
            
            space->removeEntity(id);
            
            post( CMessage( CHANGE_STATE_MSG, ptr ) );
        }
        
    }
}