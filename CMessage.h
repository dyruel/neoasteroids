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

typedef enum
{
    EMPTY_MSG            = 0,
    QUIT_MESSAGE,
    ENTITIES_MESSAGE,
    COMMAND_MESSAGE,
    CHANGE_STATE_MSG,
    PUSH_STATE_MSG,
} MessageId;

class CMessage
{
public:
    
    CMessage() : m_data(nullptr), m_messageId(EMPTY_MSG) {};
    CMessage(const MessageId& messageId, void* data)
    : m_data(data), m_messageId(messageId) {};
    CMessage(const MessageId& messageId)
    : m_data(nullptr), m_messageId(messageId) {};
    virtual ~CMessage(){};

    const MessageId&  getMessageId() const
    {
        return m_messageId;
    }
    
    void  setMessageIds(const MessageId& messageId)
    {
        m_messageId = messageId;
    }
    
    void  setData(void* data)
    {
        m_data = data;
    }
    
    const void* getData() const
    {
        return m_data;
    }
    
protected:
    
    MessageId   m_messageId;
    
    void*       m_data;
    
};

#endif
