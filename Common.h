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

namespace PE
{
    
    constexpr const glm::u32   MAX_GAME_STATES = 3;
    
    constexpr const glm::u32   MAX_SYSTEMS     = 3;
    
    constexpr const glm::u32   MAX_LISTENERS   = 4;
    
    constexpr const glm::u32   DELTA_TIME      = 10; // in ms

    constexpr const glm::u32   MAX_ENTITIES    = 20;

    constexpr const glm::u32   MAX_VERTICES    = 10;
    
    constexpr const glm::u32   MAX_INDICES     = 10;
    
    typedef enum
    {
        NULL_LISTENER         = 0,
        GRAPHICS_LISTENER     = 1 << 0,
        INPUT_LISTENER        = 1 << 1,
        LOGIC_LISTENER        = 1 << 2,
        ALL_LISTENER          = ~0
    } ListenerId;
    
    typedef enum
    {
        NULL_SYSTEM         = 0,
        GRAPHICS_SYSTEM     = 1 << 0,
        INPUT_SYSTEM        = 1 << 1,
        LOGIC_SYSTEM        = 1 << 2,
        ALL_SYSTEM          = ~0
    } SystemId;
    
    typedef enum
    {
        NULL_MESSAGE         = 0,
        QUIT_MESSAGE         = 1 << 0,
        ENTITIES_MESSAGE     = 1 << 1,
        COMMAND_MESSAGE      = 1 << 2,
        ALL_MESSAGE          = ~0
    } MessageId;
    
    
    typedef enum
    {
        ASTEROID_ENTITY            = 0,
        SPACESHIP_ENTITY,
        DOT_ENTITY,
        UFO_ENTITY,
        NUM_ENTITYTYPE
    } EntityType;
    
    typedef enum
    {
        NO_MESH             = -1,
        ASTEROID1_MESH,
        SPACESHIP_MESH,
        UFO_MESH,
        NUM_MESH
    } Mesh;
    
    typedef enum
    {
        NULL_COMMAND    = 0,
        UP_COMMAND      = 1 << 0,
        DOWN_COMMAND    = 1 << 1,
        LEFT_COMMAND    = 1 << 2,
        RIGHT_COMMAND   = 1 << 3,
        X_COMMAND       = 1 << 4,
        O_COMMAND       = 1 << 5,
        T_COMMAND       = 1 << 6,
        S_COMMAND       = 1 << 7
    } CommandId;
}



#endif
