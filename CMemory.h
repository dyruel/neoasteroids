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

#ifndef CMEMORY_H
#define CMEMORY_H

#include <cstdlib>
#include <cstring>

#include "CFileLogger.h"
#include "Types.h"

class CMemory
{

public:
    
    static void* allocate(const u64& size, c8 const * label);
    
    static void free(void* ptr);
    
    static void print();
    
    static void freeAll();
    
private:
    CMemory() {};
    CMemory(const CMemory&){};
    CMemory& operator=(const CMemory& ){ return *this;};
    
    typedef struct _SMemoryBlock
    {
        u64				id;
        void*           ptr;
        u64				size;
        c8 const*		label;
        struct _SMemoryBlock *prev, *next;
    } SMemoryBlock;
    
    static SMemoryBlock* m_headBlock;
    static s32 m_numBlocks;
    
    static s32 m_totalMemorySize;
    
    static void pushMemoryBlock(SMemoryBlock* block);
    static void popMemoryBlock(SMemoryBlock* block);
    static SMemoryBlock* getBlockFromPointer(void* ptr);
};

#endif
