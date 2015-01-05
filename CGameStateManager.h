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

#ifndef CGAMESTATEMANAGER_H
#define CGAMESTATEMANAGER_H

#include <glm/common.hpp>
#include <vector>

//#include "IGameState.h"


class CGameStateManager
{
public:
    
    class IGameState
    {
         friend class CGameStateManager;
    public:
        IGameState() : m_gameStateManager(nullptr) {}
        ~IGameState() {}
        
        virtual void init()     = 0;
        virtual void pause()    = 0;
        virtual void resume()   = 0;
        virtual void shutdown() = 0;
        
        virtual void display() = 0;
        virtual void update(const glm::u32& delta) = 0;
        
    protected:
        CGameStateManager* m_gameStateManager;
    };
    
    CGameStateManager() {}
    virtual ~CGameStateManager() {}
    
    void change(IGameState* state);
    
    void push(IGameState* state);
    
    void pop();
    
    IGameState* current();
    
    bool empty();
    
    void clear();
    
private:

    std::vector<IGameState*> m_gameStates;
    
};

#endif
