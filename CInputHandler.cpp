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

#include "CInputHandler.h"

bool CInputHandler::init()
{
    return true;
}

bool CInputHandler::shutdown()
{
    return true;
}


void CInputHandler::run()
{
    CMessage  msg;
    SDL_Event event;
    
    msg.setSender(PE::INPUT_LISTENER);
    
    SDL_PollEvent( &event );
    
    if( event.type != SDL_KEYDOWN  && event.type != SDL_KEYUP)
    {
        return;
    }
    
    bool is_pressed = event.type == SDL_KEYDOWN ? true : false;
    
    // BEGIN : TO BE REMOVED
    if (is_pressed && event.key.keysym.sym == SDLK_q)
    {
        msg.setReceivers(PE::ALL_LISTENER);
        msg.setMessageIds(PE::QUIT_MESSAGE);
        post(msg);
        return;
    }
    // END
    
    msg.setReceivers(PE::LOGIC_LISTENER);
    
    PE::CommandId commandId = PE::NULL_COMMAND;
    
    switch( event.key.keysym.sym )
    {
        case SDLK_LEFT:  commandId = PE::LEFT_COMMAND;   break;
        case SDLK_RIGHT: commandId = PE::RIGHT_COMMAND;  break;
        case SDLK_UP:    commandId = PE::UP_COMMAND;     break;
        case SDLK_DOWN:  commandId = PE::DOWN_COMMAND;   break;
        case SDLK_SPACE: commandId = PE::A_COMMAND;      break;
            
        default:
            return;
            break;
    }
    
    if (is_pressed)
    {
        if ((m_commandsStatus | commandId) == m_commandsStatus)
        {
            return;
        }
        
        m_commandsStatus |= commandId;
    }
    else
    {
        if ((m_commandsStatus & (~commandId)) == m_commandsStatus)
        {
            return;
        }
        
        m_commandsStatus &= (~commandId);
    }
    
    msg.setMessageIds(PE::COMMAND_MESSAGE);
     
    msg.setData(&m_commandsStatus);
     
    post(msg);
}

