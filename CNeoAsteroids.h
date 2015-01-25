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

#include "CSpaceManager.h"

#include "CGraphicsProcessor.h"
#include "CCollisionProcessor.h"
#include "CPhysicsProcessor.h"
#include "CInputProcessor.h"
#include "CTransitionProcessor.h"

#include "CUtils.h"

#include "CAssets.h"
#include "CEngine.h"

class CNeoAsteroids
{
public:
    
    CNeoAsteroids()
    : m_assets(&m_engine) {}
    virtual ~CNeoAsteroids() {}
        
    bool init(int& argc, char** argv);
    
    void shutdown();

    void run();
    
private:
    
    // Processors
    CGraphicsProcessor     m_graphicsProcessor;
    CCollisionProcessor    m_collisionProcessor;
    CPhysicsProcessor      m_physicsProcessor;
    CInputProcessor        m_inputProcessor;
//    CTransitionProcessor   m_transitionProcessor;
    
    // Game state manager
    CSpaceManager      m_spaceManager;
    
    // Game assets
    CAssets                m_assets;
    
    // Game engine
    CEngine                m_engine;
};

#endif
