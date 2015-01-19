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

//#include "CGameStateManager.h"
//#include "SEntity.h"
//#include "CMessageHandler.h"

#include "IGameState.h"

#include "CFileLogger.h"
#include "CUtils.h"


class CPlayGameState : public IGameState
{
public:
    
    void init();
    void pause();
    void resume();
    void shutdown();
    void update();
    void receive(const CMessage& msg);
    
    static CPlayGameState& instance()
    {
        return m_playGameState;
    }
    
private:
    CPlayGameState() {}

        
    glm::u32    m_level;
    glm::u32    m_lastTime;
    glm::u32    m_commandsStatus;
    
    // Player infos
    glm::u32    m_lives;
    glm::u32    m_score;
    
    // Game entities
    glm::u32    m_spaceshipId;
    

    
    //
    static CPlayGameState   m_playGameState;
    
    // Private methods
    void        prepareLevel(const glm::u32& level);
    
    glm::u32    addEntity       ();
    
    void        removeEntity    (const glm::u32& id);
    
    void        removeAllEntities();
    
    void        resetSpaceship  ();
    
    void        addAsteroid     ();
    
    void        addSpaceship    ();
    
    void        addUfo          ();
    
    void        addBullet       ();
};

#endif
