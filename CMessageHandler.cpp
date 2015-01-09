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

#include "CMessageHandler.h"


void CMessageHandler::attachListener(IListener* listener)
{
    assert(m_numListeners < PE::MAX_LISTENERS);
    m_listeners[m_numListeners] = listener;
    ++m_numListeners;
}

void CMessageHandler::post(const CMessage& msg) const
{
    for (glm::u32 i = 0; i < m_numListeners; ++i)
    {
        m_listeners[i]->receive(msg);
    }
}