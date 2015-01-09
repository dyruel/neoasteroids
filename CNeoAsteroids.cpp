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
    m_inputSystem.init();
    m_inputSystem.attachMessageHandler(&m_messageHandler);
    
    m_logicSystem.init();
    m_logicSystem.attachMessageHandler(&m_messageHandler);
    
    m_graphicsSystem.init();
    m_graphicsSystem.attachMessageHandler(&m_messageHandler);
    
    m_messageHandler.attachListener(&m_inputSystem);
    m_messageHandler.attachListener(&m_logicSystem);
    m_messageHandler.attachListener(&m_graphicsSystem);
    m_messageHandler.attachListener(this);
    
    return true;
}

void CNeoAsteroids::shutdown()
{
    m_inputSystem.shutdown();
    m_logicSystem.shutdown();
    m_graphicsSystem.shutdown();
}

void CNeoAsteroids::run()
{
    
    while (m_running)
    {
        m_inputSystem.run();
        m_logicSystem.run();
        m_graphicsSystem.run();
    }

}

void CNeoAsteroids::receive(const CMessage& msg)
{
    if (msg.getMessageIds() & PE::QUIT_MESSAGE) {
        m_running = 0;
    }
}