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

#include "CPhysicsProcessor.h"

bool CPhysicsProcessor::init()
{
    return true;
}

bool CPhysicsProcessor::shutdown()
{
    return true;
}

/*
void CPhysicsProcessor::receive(const CMessage& msg)
{
    if (msg.getReceivers() & PE::PHYSICS_LISTENER)
    {
        if (msg.getMessageIds() & PE::ENTITIES_MESSAGE)
        {
            attachEntities((SEntity*) msg.getData());
        }
    }
}
*/

void CPhysicsProcessor::process(const CSpace* space)
{
    /*
    if(m_entities == nullptr)
    {
        return;
    }
    
    for (glm::u32 id = 0; id < PE::MAX_ENTITIES; ++id)
    {
        if (m_entities[id].systemIds & PE::LOGIC_SYSTEM)
        {
            switch (m_entities[id].type) {
                    
                case PE::SPACESHIP_ENTITY:
                    

                    
                    m_entities[id].velocity += ( m_entities[id].accel * PE::DELTA_TIME );
                    m_entities[id].position += ( m_entities[id].velocity * PE::DELTA_TIME );
                    
                    if ( m_entities[id].position.x > 1.0f )
                    {
                        m_entities[id].position.x = - 1.0f;
                    }
                    
                    if ( m_entities[id].position.y > 1.0f )
                    {
                        m_entities[id].position.y = - 1.0f;
                    }
                    
                    if ( m_entities[id].position.x < - 1.0f )
                    {
                        m_entities[id].position.x =  1.0f;
                    }
                    
                    if ( m_entities[id].position.y < - 1.0f )
                    {
                        m_entities[id].position.y = 1.0f;
                    }
                    break;
                    
                    
                case PE::ASTEROID_ENTITY:
                    
                    m_entities[id].velocity += ( m_entities[id].accel * PE::DELTA_TIME );
                    m_entities[id].position += ( m_entities[id].velocity * PE::DELTA_TIME );
                    
                    if ( m_entities[id].position.x > 1.0f )
                    {
                        m_entities[id].position.x = - 1.0f;
                    }
                    
                    if ( m_entities[id].position.y > 1.0f )
                    {
                        m_entities[id].position.y = - 1.0f;
                    }
                    
                    if ( m_entities[id].position.x < - 1.0f )
                    {
                        m_entities[id].position.x =  1.0f;
                    }
                    
                    if ( m_entities[id].position.y < - 1.0f )
                    {
                        m_entities[id].position.y = 1.0f;
                    }
                    break;
                    
                    
                    
                    
                default:
                    break;
            }
            
            
            
        }
        
    }
    */
}