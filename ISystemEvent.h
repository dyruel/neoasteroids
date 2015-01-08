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

#ifndef CSYSTEMEVENT_H
#define CSYSTEMEVENT_H

class ISystemEvent
{
public:
    
    ISystemEvent(){};
    virtual ~ISystemEvent(){};
    
    void setReceivers(const glm::u32& receiverIds)
    {
        m_receiverIds = receiverIds;
    }
    
protected:
    
    glm::u32 m_receiverIds;
    
};

#endif
