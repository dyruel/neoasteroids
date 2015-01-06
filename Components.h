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

#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <glm/common.hpp>

typedef enum
{
    COMPONENT_NONE      = 0,
    COMPONENT_POSITION   = 1 << 0,
    COMPONENT_VELOCITY   = 1 << 1,
    COMPONENT_GEOMETRY  = 1 << 2,
} EComponentId;


class CGeometryComponent
{
public:
    CGeometryComponent()
    : m_numIndices(0), m_numVertices(0) {};
    ~CGeometryComponent() {};
    
    constexpr static const glm::u32 MAX_VERTICES    = 100;
    constexpr static const glm::u32 MAX_INDICES     = 100;
    
    glm::u32    m_numVertices;
    glm::vec4   m_vertices[MAX_VERTICES];
    
    glm::u32    m_numIndices;
    glm::f32    m_indices[MAX_INDICES];

};


class CPositionComponent
{
public:
    CPositionComponent()  {};
    ~CPositionComponent() {};
    
    glm::vec4 m_position;
};

class CVelocityComponent
{
public:
    CVelocityComponent()  {};
    ~CVelocityComponent() {};
    
    glm::vec4 m_direction;
    glm::f32  m_speed;
};




#endif
