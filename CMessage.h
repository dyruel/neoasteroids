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

#ifndef CMESSAGE_H
#define CMESSAGE_H


class CMessage
{
public:
    
    CMessage(){};
    virtual ~CMessage(){};
    
    void setSender(const PE::SystemId& systemId)
    {
        m_senderId = systemId;
    }
    
    void setReceivers(const PE::SystemId& receiverIds)
    {
        m_receiverIds = receiverIds;
    }
    
    void  setMessageIds(const PE::MessageId& messageIds)
    {
        m_messageIds = messageIds;
    }
    
    const PE::MessageId&  getMessageIds() const
    {
        return m_messageIds;
    }
    
protected:
    
    PE::SystemId    m_senderId;
    
    PE::SystemId    m_receiverIds;
    
    PE::MessageId   m_messageIds;
    
};

#endif
