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

#ifndef CENGINE_H
#define CENGINE_H

#include "CAudioDevice.h"

#include "CVideoDevice.h"

class CEngine
{
    
public:
    
    CEngine() {};
    virtual ~CEngine() {};
    
    bool    init();
    
    bool    shutdown();
    
    CAudioDevice* getAudioDevice()
    {
        return &m_audioDevice;
    }
    
    CVideoDevice* getVideoDevice()
    {
        return &m_videoDevice;
    }
    
private:

    CAudioDevice m_audioDevice;
    
    CVideoDevice m_videoDevice;
    
};
#endif
