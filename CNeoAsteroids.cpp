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
    /*
    m_messageHandler.attachListener(this);
    m_messageHandler.attachListener(&m_inputSystem);
    m_messageHandler.attachListener(&m_graphicsSystem);
    m_messageHandler.attachListener(&m_logicSystem);
    m_messageHandler.attachListener(&m_audioSystem);
    m_messageHandler.attachListener(&m_collisionSystem);
    m_messageHandler.attachListener(&m_physicsSystem);
    */

    m_graphicsProcessor.attachEntities(m_entities);
    m_graphicsProcessor.init();
    
//    m_inputSystem.attachMessageHandler(&m_messageHandler);
//    m_inputSystem.init();
    
//    m_audioSystem.attachMessageHandler(&m_messageHandler);
//    m_audioSystem.init();
    
    m_collisionProcessor.attachEntities(m_entities);
    m_collisionProcessor.init();
    
    m_physicsProcessor.attachEntities(m_entities);
    m_physicsProcessor.init();
    
    m_inputHandler.attachListener(&m_logicProcessor);
    
    m_logicProcessor.attachEntities(m_entities);
    m_logicProcessor.init();
    

    CUtils::initRandom();

    return true;
}

void CNeoAsteroids::shutdown()
{
    m_logicSystem.shutdown();
    m_physicsSystem.shutdown();
    m_collisionSystem.shutdown();
    m_audioSystem.shutdown();
    m_inputSystem.shutdown();
    m_graphicsSystem.shutdown();
}

void CNeoAsteroids::run()
{
    glm::f32 lastTime = CUtils::getTime();
    const glm::f32 deltaTimeMs = PE::DELTA_TIME * 1000.f;

    while (m_running)
    {
        glm::f32 presentTime = CUtils::getTime();
        
//        std::cout << presentTime - lastTime << std::endl;
        
        while (lastTime + deltaTimeMs <= presentTime)
        {
            m_inputSystem.run();
            m_collisionSystem.run();
            m_audioSystem.run();
            m_logicSystem.run();
            
            lastTime += deltaTimeMs;
        }

        m_graphicsSystem.run();
    }

}

void CNeoAsteroids::receive(const CMessage& msg)
{
    if (msg.getMessageIds() & PE::QUIT_MESSAGE) {
        m_running = 0;
    }
}