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

#ifndef SENTITYCOMPONENTS_H
#define SENTITYCOMPONENTS_H

#include "Common.h"

struct SGeometryComponent
{
    glm::u32    m_numVertices;
    glm::vec4   m_vertices[PE::MAX_VERTICES];
    
    glm::u32    m_numIndices;
    glm::u32    m_indices[PE::MAX_INDICES];

};

struct SPositionComponent
{
    glm::vec4 m_position;
};

struct SVelocityComponent
{
    glm::vec4 m_direction;
    glm::f32  m_speed;
};


struct SEntityComponents
{
    glm::u32 mask;
    
    SPositionComponent position;
    SVelocityComponent velocity;
    SGeometryComponent geometry;
};


#endif
