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

#ifndef CWORLD_H
#define CWORLD_H

#include <vector>

#include "CFileLogger.h"
#include "Components.h"
#include "ISystem.h"

class CWorld
{
public:
    CWorld();
    virtual ~CWorld();
    
    // Systems management
    void addSystem(std::unique_ptr<ISystem>& system);
    
    void broadcast(const glm::i32& msg);
    
    void update();
    
    // Entities management
    constexpr static const glm::u32 MAX_ENTITIES = 100;
    
    glm::u32    addEntity       ();
    
    void        removeEntity    (const glm::u32& id);
    
    SComponentsContainer*   getComponentsContainers()
    {
        return m_entities;
    }
    
    glm::u32    addAsteroid     ();
    glm::u32    addSpaceship    ();
    glm::u32    addUfo          ();
    glm::u32    addBullet       ();
    
private:
    SComponentsContainer                    m_entities[MAX_ENTITIES];
    std::vector<std::unique_ptr<ISystem>>   m_systems;
};

#endif
