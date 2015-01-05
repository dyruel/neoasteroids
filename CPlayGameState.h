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

#ifndef CPLAYGAMESTATE_H
#define CPLAYGAMESTATE_H

//#include "IGameState.h"
#include <iostream>



#include "CAsteroid.h"
#include "CUFO.h"
#include "CSpaceship.h"


#include "CSDLInputDevice.h"
#include "CGameStateManager.h"
//#include "Types.h"

class CPlayGameState : public CGameStateManager::IGameState
{
public:
    
    void init();
    void pause();
    void resume();
    void shutdown();
    
    void display();
    void update(const glm::u32& delta);
    
    void nextLevel();
    
    static CPlayGameState& instance()
    {
        return m_playGameState;
    }
    
private:
    CPlayGameState(){}
    
    constexpr static const glm::f32 m_deltaTime = 10.f;
    
    glm::u32    m_level;
    glm::u32    m_lastTime;
    
    // Player infos
    glm::u32    m_lives;
    glm::u32    m_score;
    
    // Game entities
    constexpr static const glm::u32 MAX_ASTEROIDS = 100;
    CAsteroid m_asteroids[MAX_ASTEROIDS];
    glm::u32 m_numAsteroids;
    
    CSpaceship m_spaceship;
    
    CUFO m_ufo;
    
    //
    static CPlayGameState m_playGameState;
};

#endif
