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

#ifndef IGAMEENGINE_H
#define IGAMEENGINE_H

#include <glm/common.hpp>
#include <vector>

#include "IVideoDevice.h"

class IGameEngine;

class IGameState
{
    friend class IGameEngine;
    
public:
    IGameState() : m_gameEngine(nullptr) {}
    ~IGameState() {}
    
    virtual void init()     = 0;
    virtual void pause()    = 0;
    virtual void resume()   = 0;
    virtual void shutdown() = 0;
    
    virtual void display() = 0;
    virtual void update(const glm::u32& delta) = 0;
    
protected:
    IGameEngine* m_gameEngine;
};

class IGameEngine
{
public:
    
    IGameEngine()
    : m_running(true), m_videoDevice(nullptr) {}
    virtual ~IGameEngine(){}
    
    // Main game engine methods
    
    virtual bool init(int& argc, char** argv) = 0;
    
    virtual bool shutdown() = 0;
    
    virtual void quit();
    
    virtual bool running();
    
    // Game states management
    
    void changeState(IGameState* state);
    
    void pushState(IGameState* state);
    
    void popState();
    
    IGameState* currentState();
    
    bool hasStates();
    
    void removeAllStates();
    
    // Getters
    
    IVideoDevice* getVideoDevice();
    
protected:
    bool m_running;
    
    IVideoDevice* m_videoDevice;
    
    std::vector<IGameState*> m_gameStates;
};

#endif
