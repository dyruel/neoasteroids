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

#ifndef IVIDEODEVICE_H
#define IVIDEODEVICE_H

#include <glm/common.hpp>

typedef enum
{
    INDEX_BUFFER       = 0,
    VERTEX_BUFFER      = 1,
} EBufferType;

class IVideoDevice {
    
public:
    IVideoDevice() {};
    virtual ~IVideoDevice() {};
    
    virtual bool init       () = 0;
    virtual bool shutdown   () = 0;
    
    virtual void beginFrame () const = 0;
    virtual void endFrame   () const = 0;
    
    // Shaders management
    
    virtual glm::u32    createProgram   (const char *vertexShader, const char *fragmentShader) = 0;
    virtual void        useProgram      (const glm::u32& programId) const = 0;
    
    // Buffers management
    
//    virtual glm::u32    createBuffer    (const glm::u64& size, const EBufferType& type) = 0;
//    virtual void        fillBuffer      (const glm::u32& id, const void* data) = 0;
};

#endif
