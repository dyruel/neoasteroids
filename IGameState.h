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

#ifndef IGAMESTATE_H
#define IGAMESTATE_H

class CLogicProcessor;

class IGameState : public IListener
{
    
public:
    IGameState() {};
    virtual ~IGameState() {};
    
    virtual void init()     = 0;
    virtual void pause()    = 0;
    virtual void resume()   = 0;
    virtual void shutdown() = 0;
    virtual void update()   = 0;
    
    void attachLogicSystem(CLogicProcessor* logicProcessor)
    {
        m_logicProcessor = logicProcessor;
    }
    
protected:
    CLogicProcessor*  m_logicProcessor;

};

#endif
