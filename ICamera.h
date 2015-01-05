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

#ifndef ICAMERA_H
#define ICAMERA_H

#include <glm/vec3.hpp>
#include <glm/common.hpp>

class ICamera
{
    
protected:
//    glm::f32 m_fov, m_aspect, m_near, m_far;
    
    glm::vec3 m_position;
    glm::vec3 m_dir;
    glm::vec3 m_up;
    
public:
    ICamera(){}
//    ICamera(const glm::f32& fov, const glm::f32& aspect, const glm::f32& near, const glm::f32& far)
//    : m_fov(fov), m_far(far), m_aspect(aspect), m_near(near) {}
    virtual ~ICamera() {};
    
    virtual bool init() = 0;
    virtual void update(const glm::u32& delta) = 0;
    
    const glm::vec3& getPosition() const { return m_position; };
    void setPosition(const glm::vec3& pos) { m_position = pos; };
    
    const glm::vec3& getDir() const { return m_dir; };
    void setDir(const glm::vec3& dir) { m_dir = dir; };
    
    const glm::vec3& getUpVector() const { return m_up; };
    void setUpVector(const glm::vec3& up) { m_up = up; };
    
};

#endif
