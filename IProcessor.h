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

#ifndef IPROCESSOR_H
#define IPROCESSOR_H

#include "CAssets.h"
#include "CEngine.h"

#include "CGameStateManager.h"

#include "CMessenger.h"

class IProcessor : public CMessenger
{
    
public:
    
    IProcessor() {};
    virtual ~IProcessor() {};
    
    virtual bool init()     = 0;
    
    virtual bool shutdown() = 0;
    
    virtual void process(CSpace* space, CAssets* assets, CEngine* engine)  = 0;
};

#endif
