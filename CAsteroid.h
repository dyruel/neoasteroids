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

#ifndef CASTEROID_H
#define CASTEROID_H

#include "IEntity.h"

enum EASTEROID_SIZE
{
    AST_LARGE = 0,
    AST_MEDIUM,
    AST_SMALL,
    AST_SIZE_COUNT
};

class CAsteroid : public IEntity
{
    
public:
    CAsteroid() {}
    ~CAsteroid() {}
    
    void init();
    
    void update(const glm::u32& delta);
    
    void display();
    
    void setSize(const EASTEROID_SIZE& size);
    
private:
    
    EASTEROID_SIZE m_size;
};

#endif
