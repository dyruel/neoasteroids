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

#include "CNeoAsteroids.h"

bool CNeoAsteroids::init(int& argc, char** argv)
{

    // Init game engine and load assets
    m_engine.init();
    
    m_assets.loadAssets();
    
    // Init processors
    m_graphicsProcessor.init();
    
    m_collisionProcessor.init();
    
    m_physicsProcessor.init();
    
    m_inputProcessor.init();
    
    m_transitionProcessor.init();
    
    // Init game
    m_gameStateManager.init();
    
    m_transitionProcessor.registerReceiver( &m_gameStateManager );
    
    m_gameStateManager.changeState( &CIntroGameState::instance() );
    
    CUtils::initRandom();
    
    return true;
}

void CNeoAsteroids::shutdown()
{
    m_gameStateManager.shutdown();
    
    m_physicsProcessor.shutdown();
    m_collisionProcessor.shutdown();
    m_graphicsProcessor.shutdown();
    m_inputProcessor.shutdown();
    m_transitionProcessor.shutdown();
    
    m_assets.freeAssets();
    
    m_engine.shutdown();
    
}

void CNeoAsteroids::run()
{
    glm::f32 lastTime = CUtils::getTime();
    glm::f32 presentTime = 0.f;
    const glm::f32 deltaTimeMs = CST::DELTA_TIME * 1000.f;
    CSpace* currentSpace;

    while (m_gameStateManager.hasStates())
    {
        presentTime = CUtils::getTime();
        currentSpace = m_gameStateManager.currentState()->getSpace();
        
        while (lastTime + deltaTimeMs <= presentTime)
        {
            m_physicsProcessor.process( currentSpace, &m_assets, &m_engine );
            
            m_collisionProcessor.process( currentSpace, &m_assets, &m_engine );
            
            m_inputProcessor.process( currentSpace, &m_assets, &m_engine );
            
            m_transitionProcessor.process( currentSpace, &m_assets, &m_engine );
            
            lastTime += deltaTimeMs;
        }

        m_graphicsProcessor.process( currentSpace, &m_assets, &m_engine );
    }

}

