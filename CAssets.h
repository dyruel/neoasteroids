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

#ifndef CASSETS_H
#define CASSETS_H

#include "CEngine.h"

#include "CTexture.h"
#include "CSound.h"
#include "CMusic.h"

class CAssets
{
    
public:
    
    CAssets(CEngine* engine)
    : m_engine(engine) {};
    virtual ~CAssets() {};
    
    bool    loadAssets();
    
    void    freeAssets();
    
    CTexture* getSpaceShip();
    
    CTexture* getBullet();
    
    CTexture* getAsteroid();
    
    CTexture* getUfo();
    
    CSound*   getExplosion();
    
    CSound*   getShot();
    
    CMusic*   getMusic();
    
private:
    
    CEngine*    m_engine;
    
    CTexture    m_spaceShip;
    CTexture    m_bullet;
    CTexture    m_asteroid;
    CTexture    m_ufo;
    
    CSound      m_explosion;
    CSound      m_shot;
    
    CMusic      m_music;

};

#endif
