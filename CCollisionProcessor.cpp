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

#include "CCollisionProcessor.h"

bool CCollisionProcessor::init()
{
    return true;
}

bool CCollisionProcessor::shutdown()
{
    return true;
}

/*
void CCollisionProcessor::receive(const CMessage& msg)
{
    if (msg.getReceivers() & PE::COLLISION_LISTENER)
    {
        if (msg.getMessageIds() & PE::ENTITIES_MESSAGE)
        {
            attachEntities((SEntity*) msg.getData());
        }
    }
}
*/
void CCollisionProcessor::process(CSpace* space)
{
    /*
    if(m_entities == nullptr)
    {
        return;
    }
    
    for (glm::u32 id = 0; id < PE::MAX_ENTITIES; ++id)
    {
        if (m_entities[id].systemIds & PE::COLLISION_SYSTEM)
        {

            
        }
        
    }
    */
}

