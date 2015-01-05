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

#include "CAsteroid.h"


void CAsteroid::init()
{
    m_size = AST_LARGE;
    m_position.x = rand() / RAND_MAX;
    m_position.y = rand() / RAND_MAX;
}

void CAsteroid::update(const glm::u32 &delta)
{
    
}

void CAsteroid::display()
{
    
}

void CAsteroid::setSize(const EASTEROID_SIZE& size)
{
    m_size = size;
}