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

bool CInputSystem::init(SEntityComponents* entities)
{
    return true;
}

bool CInputSystem::shutdown()
{
    return true;
}


void CInputSystem::receive(const glm::i32& msg)
{
    
}

void CInputSystem::update(const glm::u32& delta)
{
    SDL_Event event;
    bool is_pressed = false;
    
    SDL_PollEvent( &event );
    
    if( event.type == SDL_KEYDOWN )
    {
        is_pressed = true;
    }
    else if ( event.type == SDL_KEYUP )
    {
        is_pressed = false;
    }
    else
    {
        return;
    }
    /*
    switch( event.key.keysym.sym )
    {
        case SDLK_LEFT:     m_keys[KEY_LEFT]    = is_pressed; break;
        case SDLK_RIGHT:    m_keys[KEY_RIGHT]   = is_pressed; break;
        case SDLK_UP:       m_keys[KEY_UP]      = is_pressed; break;
        case SDLK_DOWN:     m_keys[KEY_DOWN]    = is_pressed; break;
        case SDLK_SPACE:    m_keys[KEY_SPACE]   = is_pressed; break;
            
        default:
            break;
    }*/
}