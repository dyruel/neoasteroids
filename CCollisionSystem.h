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

#ifndef CCOLLISIONSYSTEM_H
#define CCOLLISIONSYSTEM_H

#include "ISystem.h"

class CCollisionSystem : public ISystem
{
    
public:
    
    CCollisionSystem() {};
    virtual ~CCollisionSystem() {};
    
    // ISystem specific methods
    bool    init();
    
    bool    shutdown();
    
    void    run();
    
    void    receive(const CMessage& msg);
    
private:
    
};
#endif
