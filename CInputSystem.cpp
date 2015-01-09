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

#include "CInputSystem.h"

bool CInputSystem::init()
{
    return true;
}

bool CInputSystem::shutdown()
{
    return true;
}


void CInputSystem::receive(const CMessage& msg)
{
    
}

void CInputSystem::run()
{
    CMessage  msg;
    SDL_Event event;
    bool is_pressed = false;
    
    msg.setSender(PE::INPUT_SYSTEM);
    
    SDL_PollEvent( &event );
    
    if( event.type == SDL_KEYDOWN )
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_LEFT:     break;
            case SDLK_RIGHT:    break;
            case SDLK_UP:       break;
            case SDLK_DOWN:     break;
            case SDLK_SPACE:    break;
            case SDLK_ESCAPE:
                msg.setReceivers(PE::ALL_SYSTEM);
                msg.setMessageIds(PE::QUIT_MESSAGE);
                m_messageHandler->post(msg);
            break;
                
            default:
                break;
        }
    }
    else if ( event.type == SDL_KEYUP )
    {
        is_pressed = false;
    }
    else
    {
        return;
    }
    

    
    
}

