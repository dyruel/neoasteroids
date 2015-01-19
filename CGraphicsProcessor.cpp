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

#include "CGraphicsProcessor.h"


bool CGraphicsProcessor::init()
{

#if 0
    
    GLint vertexPositionAttrib = glGetAttribLocation ( m_basicProgram, "position") ;
    
    // Initialize VAOs/VBOs/IBOs
    
    glGenVertexArrays ( PE::NUM_MESH, m_vaos);
    glGenBuffers( PE::NUM_MESH, m_vbos );
    glGenBuffers( PE::NUM_MESH, m_ibos );
    

    // Asteroids VBOs/IBOs
    
    GLfloat asteroid1Vertices[] =
    {
        -0.1f, -0.1f, 0.0f,
        0.1f, -0.1f, 0.0f,
        0.1f,  0.1f, 0.0f,
        -0.1f,  0.1f, 0.0f,
    };
    GLuint asteroid1Indices[] = { 0, 1, 2, 3 };
    
    m_numIndices[PE::ASTEROID1_MESH] = 4;
    
    glBindBuffer( GL_ARRAY_BUFFER, m_vbos[PE::ASTEROID1_MESH]);
    glBufferData( GL_ARRAY_BUFFER, 12 * sizeof(GLfloat), asteroid1Vertices, GL_STATIC_DRAW );
    
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_ibos[PE::ASTEROID1_MESH] );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, m_numIndices[PE::ASTEROID1_MESH] * sizeof(GLuint), asteroid1Indices, GL_STATIC_DRAW );
    
    // VAO
    glBindVertexArray (m_vaos[PE::ASTEROID1_MESH]);
        glEnableVertexAttribArray (vertexPositionAttrib);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbos[PE::ASTEROID1_MESH]);
        glVertexAttribPointer (vertexPositionAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibos[PE::ASTEROID1_MESH]);
    glBindVertexArray (0);
    
    // Spaceship VBOs/IBOs
    GLfloat spaceshipVertices[] =
    {
        -0.05f, -0.1f, 0.0f,
        -0.05f, 0.1f, 0.0f,
        0.1f,  0.0f, 0.0f,
    };
    GLuint spaceshipIndices[] = { 0, 1, 2 };
    
    m_numIndices[PE::SPACESHIP_MESH] = 3;
    
    glBindBuffer( GL_ARRAY_BUFFER, m_vbos[PE::SPACESHIP_MESH]);
    glBufferData( GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), spaceshipVertices, GL_STATIC_DRAW );
    
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_ibos[PE::SPACESHIP_MESH] );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, m_numIndices[PE::SPACESHIP_MESH] * sizeof(GLuint), spaceshipIndices, GL_STATIC_DRAW );
    
    // VAO
    glBindVertexArray (m_vaos[PE::SPACESHIP_MESH]);
        glEnableVertexAttribArray (vertexPositionAttrib);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbos[PE::SPACESHIP_MESH]);
        glVertexAttribPointer (vertexPositionAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibos[PE::SPACESHIP_MESH]);
    glBindVertexArray (0);
    
    // UFO VBOs/IBOs
    GLfloat ufoVertices[] =
    {
        -0.1f, -0.1f, 0.0f,
        0.1f, -0.1f, 0.0f,
        0.0f,  0.1f, 0.0f,
    };
    GLuint ufoIndices[] = { 0, 1, 2 };
    
    m_numIndices[PE::UFO_MESH] = 3;
    
    glBindBuffer( GL_ARRAY_BUFFER, m_vbos[PE::UFO_MESH]);
    glBufferData( GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), ufoVertices, GL_STATIC_DRAW );
    
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_ibos[PE::UFO_MESH] );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, 3 * sizeof(GLuint), ufoIndices, GL_STATIC_DRAW );

    // VAO
    glBindVertexArray (m_vaos[PE::UFO_MESH]);
        glEnableVertexAttribArray (vertexPositionAttrib);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbos[PE::UFO_MESH]);
        glVertexAttribPointer (vertexPositionAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibos[PE::UFO_MESH]);
    glBindVertexArray (0);
#endif
    return true;
}

bool CGraphicsProcessor::shutdown()
{
#if 0
    glDeleteBuffers(PE::NUM_MESH, m_vbos);
//    glDeleteBuffers(PE::NUM_MESH, m_vbos);
#endif

    
    return true;
}




void CGraphicsProcessor::process(CSpace* space)
{
/*
    if(m_entities == nullptr)
    {
        return;
    }
*/
    
    
    for (glm::u32 id = 0; id < CST::MAX_ENTITIES; ++id)
    {
/*
        if (m_entities[id].systemIds & PE::GRAPHICS_SYSTEM)
        {
            glm::mat4 rotationMatrix;
            rotationMatrix = glm::rotate(rotationMatrix, m_entities[id].angle, glm::vec3(0.0f, 0.0f, 1.0f));
            
            glm::mat4 translationMatrix;
            translationMatrix = glm::translate(translationMatrix, m_entities[id].position);
            
            glm::mat4 modelMatrix = translationMatrix * rotationMatrix;
            
            glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));
            
            if(m_entities[id].mesh >= 0)
            {
                glBindVertexArray (m_vaos[m_entities[id].mesh]);
                glDrawElements (GL_LINE_LOOP, m_numIndices[m_entities[id].mesh], GL_UNSIGNED_INT, 0);
                glBindVertexArray (0);
            }

        }
*/
    }
    

}

/*
void CGraphicsProcessor::receive(const CMessage& msg)
{
    if (msg.getReceivers() & PE::GRAPHICS_LISTENER)
    {
        if (msg.getMessageIds() & PE::ENTITIES_MESSAGE)
        {
            attachEntities((SEntity*) msg.getData());
        }
    }
}
*/

