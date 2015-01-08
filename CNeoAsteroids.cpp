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

    return true;
}

bool CNeoAsteroids::shutdown()
{
    removeAllStates();
    return true;
}

void CNeoAsteroids::run()
{
    glm::u32 lastTime = CUtils::getTime();
    
    while (m_running) {
        
        glm::u32 presentTime = CUtils::getTime();
        
        while (lastTime + PE::DELTA_TIME <= presentTime) {
            
            if(hasStates())
            {
                m_states[m_currentState]->update(PE::DELTA_TIME);
            }
            
            lastTime += PE::DELTA_TIME;
        }
        
        if(hasStates())
        {
            currentState()->display();
        }
        
    }

}

void CNeoAsteroids::quit()
{
    m_running = false;
}

bool CNeoAsteroids::running()
{
    return m_running;
}

void CNeoAsteroids::changeState(IGameState* state)
{
    if ( hasStates() )
    {
        m_states[m_currentState]->shutdown();
    }
    else
    {
        ++m_currentState;
    }
    
    m_states[m_currentState] = state;
    state->init(this);
}

void CNeoAsteroids::pushState(IGameState* state)
{
    assert( (m_currentState + 1 < PE::MAX_GAME_STATES) && (state != nullptr) );
    
    if ( hasStates() )
    {
        m_states[m_currentState]->pause();
    }
    
    ++m_currentState;
    m_states[m_currentState] = state;
    state->init(this);
}

void CNeoAsteroids::popState()
{
    if ( hasStates() )
    {
        m_states[m_currentState]->shutdown();
        --m_currentState;
    }
    
    if ( hasStates() )
    {
        m_states[m_currentState]->resume();
    }
}

IGameState* CNeoAsteroids::currentState()
{
    return m_states[m_currentState];
}

bool CNeoAsteroids::hasStates()
{
    return m_currentState >= 0;
}

void CNeoAsteroids::removeAllStates()
{
    while ( m_currentState >= 0 ) {
        m_states[m_currentState]->shutdown();
        --m_currentState;
    }
}
