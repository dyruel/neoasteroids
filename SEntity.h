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

#ifndef SENTITY_H
#define SENTITY_H

#include "Common.h"

typedef enum
{
    NULL_COMPONENT          = 0,
    RENDER_COMPONENT        = 1 << 0,
    POSITION_COMPONENT      = 1 << 1,
    MOVE_COMPONENT          = 1 << 2,
    COLLIDABLE_COMPONENT    = 1 << 3,
    PLAYER_COMPONENT        = 1 << 4,
    INPUT_COMPONENT         = 1 << 5,
    TRANSITION_COMPONENT    = 1 << 6,
    ALL_COMPONENT           = ~0
} ComponentId;

struct SEntity
{
    glm::u32       components;
    
    // Render Component
    glm::u8        texName[64];
    glm::u32       texId;
    
    // Position component
    glm::vec3      position;
    
    // Move component
    glm::vec3      velocity;
    glm::vec3      accel;
    glm::f32       angle;
    
    // Collidable component
    glm::u8        group;       // Only entities of different groups can collide
    glm::vec2      rect[4];
    
    // Player Component
    glm::u32       lives;
    glm::u32       score;
    
    // Input Component
    glm::u32       mapSize;
    glm::u32       ButtonId[CST::MAX_INPUT_MAP];
    glm::u32       ActionId[CST::MAX_INPUT_MAP];
    
    // Transition component
    void*          targetGameState;
};



#endif
