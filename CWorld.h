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
#include "CMemory.h"

class CWorld
{
public:
    CWorld();
    virtual ~CWorld();
    
    void init(const glm::u32& numEntities);
    
    void shutdown();
    
    // Systems management
    template <class T>
    void addSystem()
    {
        assert(system != nullptr);
        
        std::unique_ptr<ISystem> system(new T());
        
        system->init(this);
        
        m_systems.push_back(std::move(system));
    }
    
    void broadcast(const glm::i32& msg);
    
    void update(const glm::u32& delta);
    
    // Entities management    
    glm::u32    addEntity       ();
    
    void        removeEntity    (const glm::u32& id);
    
    
    const glm::u32& getNumEntities()
    {
        return m_numEntities;
    }
    
    SComponentsContainer*   getComponentsContainers()
    {
        return m_entities;
    }

    /*
    glm::u32    addAsteroid     ();
    glm::u32    addSpaceship    ();
    glm::u32    addUfo          ();
    glm::u32    addBullet       ();
    */
private:
    glm::u32                                m_numEntities;
    SComponentsContainer*                   m_entities;
    std::vector<std::unique_ptr<ISystem>>   m_systems; // TODO: Priority queue?
};

#endif
