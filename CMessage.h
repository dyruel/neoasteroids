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
    
    CMessage() : m_data(nullptr) {};
    virtual ~CMessage(){};
    
    void setSender(const PE::ListenerId& systemId)
    {
        m_senderId = systemId;
    }
    
    const PE::ListenerId& getSender() const
    {
        return m_senderId;
    }
    
    void setReceivers(const PE::ListenerId& receiverIds)
    {
        m_receiverIds = receiverIds;
    }
    
    const PE::ListenerId& getReceivers() const
    {
        return m_receiverIds;
    }
    
    void  setMessageIds(const PE::MessageId& messageIds)
    {
        m_messageIds = messageIds;
    }
    
    void  setData(void* data)
    {
        m_data = data;
    }
    
    const void* getData() const
    {
        return m_data;
    }
    
    const PE::MessageId&  getMessageIds() const
    {
        return m_messageIds;
    }
    
protected:
    
    PE::ListenerId    m_senderId;
    
    PE::ListenerId    m_receiverIds;
    
    PE::MessageId   m_messageIds;
    
    void*           m_data;
    
};

#endif
