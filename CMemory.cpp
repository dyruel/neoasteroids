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


#include "CMemory.h"

#define MEM_ID	0x12345678l

CMemory::SMemoryBlock* CMemory::m_headBlock = nullptr;
s32 CMemory::m_numBlocks = 0;
s32 CMemory::m_totalMemorySize = 0;


void* CMemory::allocate(const u64& size, c8 const * label)
{
    void* ptr = nullptr;
    SMemoryBlock* block = nullptr;
    
    ptr = std::malloc(size + sizeof(SMemoryBlock));
    if (ptr == nullptr) {
        CFileLogger::log("ERROR in CMemory::allocate -> Unable to allocate the memory block\n");
        return nullptr;
    }
    
    std::memset(ptr, 0, size + sizeof(SMemoryBlock));
    
    block = (SMemoryBlock*)ptr;
    block->id = MEM_ID;
    block->ptr = (u8*)ptr + sizeof(SMemoryBlock);
    block->size = size + sizeof(SMemoryBlock);
    block->label = label;
    
    CMemory::pushMemoryBlock(block);
    m_totalMemorySize += block->size;
    m_numBlocks++;
    
    return block->ptr;
}

void CMemory::free(void* ptr)
{
    SMemoryBlock *block = nullptr;
    
    block = CMemory::getBlockFromPointer(ptr);
    
    if (!block)
        return;
    
    CMemory::popMemoryBlock(block);
    m_totalMemorySize -= block->size;
    m_numBlocks--;
    
    std::free(block);
}

void CMemory::print()
{
    SMemoryBlock* block = nullptr;
    int i;
    
    CFileLogger::log("====== Memory Usage ======\n");
    CFileLogger::logFormat("total memory size: %d KB\n", m_totalMemorySize >> 10);
    CFileLogger::logFormat("total memory blocks: %d\n", m_numBlocks);
    
    i = 0;
    for (block = m_headBlock; block; block = block->next) {
        CFileLogger::logFormat("%6d, %p, %8d : %s\n", i, block->ptr, (int) block->size, block->label);
        i++;
    }
    CFileLogger::log("============\n");
}

void CMemory::freeAll()
{
    SMemoryBlock* block = nullptr;
    
    for (block = m_headBlock; block; block = m_headBlock) {
        CMemory::free(block->ptr);
    }
    
    m_totalMemorySize = 0;
}


void CMemory::pushMemoryBlock(SMemoryBlock* block)
{
    block->prev = nullptr;
    block->next = m_headBlock;
    if (m_headBlock) m_headBlock->prev = block;
    m_headBlock = block;
}

void CMemory::popMemoryBlock(SMemoryBlock* block)
{
    if (block->prev) block->prev->next = block->next;
    else m_headBlock = block->next;
    if (block->next) block->next->prev = block->prev;
}

CMemory::SMemoryBlock* CMemory::getBlockFromPointer(void* ptr)
{
    SMemoryBlock *block = nullptr;
    
    if (!ptr) {
        return nullptr;
    }
    
    block = (SMemoryBlock*)((u8*)ptr - sizeof(SMemoryBlock));
    
    if (block->id != MEM_ID) {
        CFileLogger::log("ERROR in CMemory::allocate -> invalid memory block\n");
    }
    
    if (block->ptr != ptr) {
        CFileLogger::log("ERROR in CMemory::allocate -> memory block pointer invalid\n");
    }
    
    return block;
}
