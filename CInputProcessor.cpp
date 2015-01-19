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

#include "CInputProcessor.h"

bool CInputProcessor::init()
{
    return true;
}

bool CInputProcessor::shutdown()
{
    return true;
}

void CInputProcessor::process(const IProcessible* processible)
{
/*
    for (glm::u32 id = 0; id < PE::MAX_ENTITIES; ++id)
    {
        if (m_entities[id].systemIds & PE::LOGIC_SYSTEM)
        {
            switch (m_entities[id].type) {
                    
                case PE::SPACESHIP_ENTITY:
                    if (m_commandsStatus & PE::RIGHT_COMMAND)
                    {
                        m_entities[id].angle -= 5.f * PE::DELTA_TIME;
                    }
                    else if (m_commandsStatus & PE::LEFT_COMMAND)
                    {
                        m_entities[id].angle += 5.f * PE::DELTA_TIME;
                    }
                    
                    if (m_commandsStatus & PE::UP_COMMAND)
                    {
                        m_entities[id].accel.x = cosf( m_entities[id].angle );
                        m_entities[id].accel.y = sinf( m_entities[id].angle );
                    }
                    else
                    {
                        m_entities[id].accel.x = 0;
                        m_entities[id].accel.y = 0;
                    }
                    
                default:
                    break;
            }
        }
    }
    */
}


void CInputProcessor::updateButtonStatus()
{
    SDL_Event event;
    
    SDL_PollEvent( &event );
    
    if( event.type != SDL_KEYDOWN  && event.type != SDL_KEYUP)
    {
        return;
    }
    
    bool is_pressed = event.type == SDL_KEYDOWN ? true : false;
    
    PE::ButtonId buttonId = PE::NULL_BUTTON;
    
    switch( event.key.keysym.sym )
    {
        case SDLK_LEFT:  buttonId = PE::LEFT_BUTTON;   break;
        case SDLK_RIGHT: buttonId = PE::RIGHT_BUTTON;  break;
        case SDLK_UP:    buttonId = PE::UP_BUTTON;     break;
        case SDLK_DOWN:  buttonId = PE::DOWN_BUTTON;   break;
        case SDLK_SPACE: buttonId = PE::A_BUTTON;      break;
        
            
        default:
            return;
            break;
    }
    
    if (is_pressed)
    {
        if ((m_buttonsStatus | buttonId) == m_buttonsStatus)
        {
            return;
        }
        
        m_buttonsStatus |= buttonId;
    }
    else
    {
        if ((m_buttonsStatus & (~buttonId)) == m_buttonsStatus)
        {
            return;
        }
        
        m_buttonsStatus &= (~buttonId);
    }
}

