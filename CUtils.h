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

#ifndef CUTILS_H
#define CUTILS_H

#ifdef WIN32
#include <SDL.h>
#elif __APPLE__
#define GL3_PROTOTYPES 1
#include <SDL2/SDL.h>
#endif

#include <glm/common.hpp>
#include <cstdlib>
#include <ctime>


class CUtils 
{
public:
    static glm::u32 getTime();
    
    static void initRandom();
    
    static glm::f32 getRandomNumber();
    
};

#endif
