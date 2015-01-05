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

#ifndef CORTHOCAMERA_H
#define CORTHOCAMERA_H

#include "ICamera.h"

class COrthoCamera : public ICamera
{
    
public:
    COrthoCamera(const glm::f32& left, const glm::f32& right, const glm::f32& bottom, const glm::f32& top, const glm::f32& near, const glm::f32&  far)
     : m_left(left), m_right(right), m_bottom(bottom), m_top(top), m_near(near), m_far(far) {}
    virtual ~COrthoCamera() {};

    bool init();
    void update(const glm::u32& delta);
    
private:
    glm::f32 m_left, m_right, m_bottom, m_top, m_near, m_far;
};

#endif
