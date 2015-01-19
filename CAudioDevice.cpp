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

#include "CAudioDevice.h"

bool CAudioDevice::init()
{
    if( SDL_InitSubSystem(SDL_INIT_AUDIO) < 0 )
    {
        CFileLogger::logFormat( "SDL audio could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        CFileLogger::logFormat( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }
    
/*    
    m_menuMusic = Mix_LoadMUS( "menu.ogg" );
    if( m_menuMusic == nullptr )
    {
        CFileLogger::logFormat( "Failed to load menu music! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }

    if( Mix_PlayingMusic() == 0 )
    {
        Mix_PlayMusic( m_menuMusic, -1 );
    }
*/    
    
    return true;
}

bool CAudioDevice::shutdown()
{
//    Mix_FreeMusic( m_menuMusic );
    Mix_Quit();
    return true;
}


CSound CAudioDevice::loadSound(const char *file) const
{
    CSound sound;
    
    sound.m_sound = Mix_LoadWAV( file );
    
    if( sound.m_sound == nullptr )
    {
        CFileLogger::logFormat( "Failed to load sound file %s! SDL_mixer Error: %s\n", file , Mix_GetError() );
    }
    
    return sound;
}


void CAudioDevice::freeSound(CSound* sound) const
{
    if ( sound )
    {
        Mix_FreeChunk( sound->m_sound );
    }
}


CMusic CAudioDevice::loadMusic(const char *file) const
{
    CMusic music;
    
    music.m_music = Mix_LoadMUS( file );
    
    if( music.m_music == nullptr )
    {
        CFileLogger::logFormat( "Failed to load music file %s! SDL_mixer Error: %s\n", file , Mix_GetError() );
    }
    
    return music;
}


void CAudioDevice::freeMusic(CMusic* music) const
{
    if ( music )
    {
        Mix_FreeMusic( music->m_music );
    }
}
