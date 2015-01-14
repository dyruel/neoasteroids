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

#ifndef CINTROGAMESTATE_H
#define CINTROGAMESTATE_H

#include <iostream>

#include "CLogicSystem.h"

#include "CMenuGameState.h"


class CIntroGameState : public IGameState
{
public:
    void init();
    void pause();
    void resume();
    void shutdown();
    void update();
    
    static CIntroGameState& instance()
    {
        return m_introGameState;
    }
    
private:
    CIntroGameState() {};
    
    static CIntroGameState m_introGameState;
};

#endif
