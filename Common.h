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

#ifndef COMMON_H
#define COMMON_H

#include <glm/common.hpp>
#include <iostream>

// Constants list
namespace CST
{
     const glm::u32   MAX_GAME_SPACES = 3;
    
     const glm::u32   MAX_SYSTEMS     = 3;
    
     const glm::u32   MAX_RECEIVERS   = 7;
    
     const glm::f32   DELTA_TIME      = .01f; // in s

     const glm::u32   MAX_ENTITIES    = 20;

     const glm::u32   MAX_VERTICES    = 10;
    
     const glm::u32   MAX_INDICES     = 10;
    
     const glm::u32   MAX_INPUT_MAP   = 10;
    
     const glm::f64   PI = 3.1415926535897932384626433832795f;
    
     const glm::f64   TO_RADS = PI / 180.0;
}
/*
    typedef enum
    {
        NULL_LISTENER         = 0,
        GRAPHICS_LISTENER     = 1 << 0,
        INPUT_LISTENER        = 1 << 1,
        LOGIC_LISTENER        = 1 << 2,
        COLLISION_LISTENER    = 1 << 3,
        AUDIO_LISTENER        = 1 << 4,
        PHYSICS_LISTENER      = 1 << 5,
        ALL_LISTENER          = ~0
    } ListenerId;
    
    typedef enum
    {
        NULL_SYSTEM         = 0,
        GRAPHICS_SYSTEM     = 1 << 0,
        INPUT_SYSTEM        = 1 << 1,
        LOGIC_SYSTEM        = 1 << 2,
        COLLISION_SYSTEM    = 1 << 3,
        AUDIO_SYSTEM        = 1 << 4,
        PHYSICS_SYSTEM      = 1 << 5,
        ALL_SYSTEM          = ~0
    } SystemId;
*/    

    
/*
    typedef enum
    {
        ASTEROID_ENTITY            = 0,
        SPACESHIP_ENTITY,
        BULLET_ENTITY,
        UFO_ENTITY,
        NUM_ENTITYTYPE
    } EntityType;
    
    typedef enum
    {
        NO_MESH             = -1,
        ASTEROID1_MESH,
        SPACESHIP_MESH,
        UFO_MESH,
        BULLET_MESH,
        NUM_MESH
    } Mesh;
*/
    typedef enum
    {
        NULL_BUTTON    = 0,
        UP_BUTTON      = 1 << 0,
        DOWN_BUTTON    = 1 << 1,
        LEFT_BUTTON    = 1 << 2,
        RIGHT_BUTTON   = 1 << 3,
        A_BUTTON       = 1 << 4,
        B_BUTTON       = 1 << 5,
        C_BUTTON       = 1 << 6,
        D_BUTTON       = 1 << 7,
        START_BUTTON   = 1 << 8,
        SELECT_BUTTON  = 1 << 9,
    } ButtonId;
    
    typedef enum
    {
        NULL_ACTION         = 0,
        TURN_LEFT_ACTION    = 1 << 0,
        TURN_RIGHT_ACTION   = 1 << 1,
        MOVE_ACTION         = 1 << 2,
        FIRE_ACTION         = 1 << 3,
        PAUSE_ACTION        = 1 << 4
    } ActionId;




#endif
