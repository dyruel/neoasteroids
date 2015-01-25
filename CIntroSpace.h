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

#ifndef CINTROSPACE_H
#define CINTROSPACE_H

#include "CSpace.h"
#include "CFileLogger.h"
#include "CUtils.h"


class CIntroSpace : public CSpace
{
public:
    void init();
    void pause();
    void resume();
    void shutdown();
//    void update();
//    void receive(const CMessage& msg);
	/*
    static CIntroGameState& instance()
    {
        return m_introGameState;
    }
    */
private:
  //  static CIntroGameState m_introGameState;
};

#endif
