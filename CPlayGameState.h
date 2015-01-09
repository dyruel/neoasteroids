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

#include <iostream>

//#include "CNeoAsteroids.h"

//#include "CGraphicsSystem.h"
//#include "CInputSystem.h"

#include "CLogicSystem.h"
#include "SEntity.h"
#include "CMessageHandler.h"


class CPlayGameState : public IGameState
{
public:
    
    void init();
    void pause();
    void resume();
    void shutdown();
    void update();
    
    static CPlayGameState& instance()
    {
        return m_playGameState;
    }
    
private:
    CPlayGameState() {}

        
    glm::u32    m_level;
    glm::u32    m_lastTime;
    
    // Player infos
    glm::u32    m_lives;
    glm::u32    m_score;
    
    // Game entities
    SEntity     m_entities;
//    glm::u32                m_numEntities;
//    SEntityComponents       m_entities[PE::MAX_ENTITIES];
    

    
    //
    static CPlayGameState   m_playGameState;
    
    // Private methods
    void        nextLevel();
    
    void        broadcast(const glm::i32& msg);
    
    glm::u32    addEntity       ();
    
    void        removeEntity    (const glm::u32& id);
    
    glm::u32    addAsteroid     ();
    
    glm::u32    addSpaceship    ();
    
    glm::u32    addUfo          ();
    
    glm::u32    addBullet       ();
};

#endif
