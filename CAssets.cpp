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

#include "CAssets.h"

bool CAssets::loadAssets()
{
    const CAudioDevice* audioDevice = m_engine->getAudioDevice();
    
    m_explosion = audioDevice->loadSound("explosion.wav");
    m_shot = audioDevice->loadSound("shot.wav");
    m_music = audioDevice->loadMusic("music.ogg");
    
    const CVideoDevice* videoDevice = m_engine->getVideoDevice();
    
    m_spaceShip = videoDevice->loadTexture("spaceship.png");
    m_asteroid  = videoDevice->loadTexture("asteroid.png");
    m_bullet    = videoDevice->loadTexture("bullet.png");
    
    return true;
}

void CAssets::freeAssets()
{
    const CAudioDevice* audioDevice = m_engine->getAudioDevice();
    
    audioDevice->freeMusic( &m_music );
    audioDevice->freeSound( &m_shot );
    audioDevice->freeSound( &m_explosion );
    
    const CVideoDevice* videoDevice = m_engine->getVideoDevice();
    
    videoDevice->freeTexture( &m_spaceShip );
    videoDevice->freeTexture( &m_asteroid );
    videoDevice->freeTexture( &m_bullet );
}

CTexture* CAssets::getSpaceShip()
{
    return &m_spaceShip;
}

CTexture* CAssets::getBullet()
{
    return &m_bullet;
}

CTexture* CAssets::getAsteroid()
{
    return &m_asteroid;
}

CTexture* CAssets::getUfo()
{
    return &m_ufo;
}

CSound* CAssets::getExplosion()
{
    return &m_explosion;
}

CSound* CAssets::getShot()
{
    return &m_shot;
}

CMusic* CAssets::getMusic()
{
    return &m_music;
}
