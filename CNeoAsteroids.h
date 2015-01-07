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

#ifndef CNEOASTEROIDS_H
#define CNEOASTEROIDS_H

#include <iostream>
#include <vector>
#include <glm/common.hpp>

#include "IGameEngine.h"
#include "CMemory.h"
#include "CUtils.h"

class CNeoAsteroids : public IGameEngine
{
 
public:
    CNeoAsteroids()
    : m_lastTime(0) {}
    ~CNeoAsteroids() {}

    bool init(int& argc, char** argv);
    bool shutdown();
    
    void update();
    void display();
    
private:

    constexpr static const glm::f32 m_deltaTime = 10.f;
    glm::u32    m_lastTime;
    
};

#endif
