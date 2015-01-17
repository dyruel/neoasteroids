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

#ifndef CNEOASTEROIDS_H
#define CNEOASTEROIDS_H

//#include "CMessageHandler.h"

#include "SEntity.h"

#include "CLogicProcessor.h"
#include "CGraphicsProcessor.h"
#include "CCollisionProcessor.h"
#include "CPhysicsProcessor.h"

#include "CInputHandler.h"
#include "CAudioHelper.h"

#include "CUtils.h"

class CNeoAsteroids : public IListener
{
public:
    
    CNeoAsteroids()
    : m_running(1) {}
    virtual ~CNeoAsteroids(){}
        
    bool init(int& argc, char** argv);
    
    void shutdown();

    void run();
    
    void receive(const CMessage& msg);
    
private:
    
    // Entities
    SEntity                m_entities[PE::MAX_ENTITIES];
    
    // Processors
    CLogicProcessor        m_logicProcessor;
    CGraphicsProcessor     m_graphicsProcessor;
    CCollisionProcessor    m_collisionProcessor;
    CPhysicsProcessor      m_physicsProcessor;
    
    // 
    CInputHandler          m_inputHandler;
    
    CAudioHelper           m_audioHelper;
    
    glm::u8                m_running;
};

#endif
