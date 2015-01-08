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

#ifndef ISYSTEMS_H
#define ISYSTEMS_H

#include "SEntityComponents.h"

class ISystem
{
    
public:
    ISystem() {};
    virtual ~ISystem() {};
    
    virtual bool init(SEntityComponents*) = 0;
    
    virtual bool shutdown() = 0;
    
    virtual void update(const glm::u32& delta) = 0;
    
    virtual void receive(const glm::i32& msg) = 0;
    
};

#endif
