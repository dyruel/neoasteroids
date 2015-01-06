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
    
//    srand(time(0));
    
    m_videoDevice = new COGLVideoDevice();
    
    if( !m_videoDevice )
    {
        return false;
    }
    
    m_videoDevice->init();
    
    m_lastTime = CSystem::getTime();

    return true;
}

bool CNeoAsteroids::shutdown()
{
    
    if( m_videoDevice )
    {
        m_videoDevice->shutdown();
        delete m_videoDevice;
    }
    
    
    return true;
}

void CNeoAsteroids::update()
{
    glm::u32 presentTime = CSystem::getTime();
    
    while (m_lastTime + m_deltaTime <= presentTime) {
        
        if(hasStates())
        {
            currentState()->update(m_deltaTime);
        }
        
        m_lastTime += m_deltaTime;
    }
    
}

void CNeoAsteroids::display()
{
    if(hasStates())
    {
        currentState()->display();
    }
}