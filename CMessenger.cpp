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

#include "CMessenger.h"


void CMessenger::registerReceiver(IReceiver* receiver)
{
    assert(m_numReceivers < PE::MAX_RECEIVERS);
    m_receivers[m_numReceivers] = receiver;
    ++m_numReceivers;
}

void CMessenger::post(const CMessage& msg) const
{
    for (glm::u32 i = 0; i < m_numReceivers; ++i)
    {
        m_receivers[i]->receive(msg);
    }
}