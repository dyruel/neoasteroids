//
//  IGameEngine.cpp
//  NeoAsteroids
//
//  Created by Morgan on 05/01/15.
//  Copyright (c) 2015 Morgan Chopin. All rights reserved.
//

#include "IGameEngine.h"


void IGameEngine::quit()
{
    m_running = false;
}

bool IGameEngine::running()
{
    return m_running;
}


IVideoDevice* IGameEngine::getVideoDevice()
{
    return m_videoDevice;
}

void IGameEngine::changeState(IGameState* state)
{
    if ( !m_gameStates.empty() )
    {
        m_gameStates.back()->shutdown();
        m_gameStates.pop_back();
    }
    
    m_gameStates.push_back(state);
    m_gameStates.back()->init();
    
    state->m_gameEngine = this;
}

void IGameEngine::pushState(IGameState* state)
{
    if ( !m_gameStates.empty() )
    {
        m_gameStates.back()->pause();
    }
    
    m_gameStates.push_back(state);
    m_gameStates.back()->init();
    
    state->m_gameEngine = this;
}

void IGameEngine::popState()
{
    if ( !m_gameStates.empty() )
    {
        m_gameStates.back()->shutdown();
        m_gameStates.pop_back();
    }
    
    if ( !m_gameStates.empty() )
    {
        m_gameStates.back()->resume();
    }
}

IGameState* IGameEngine::currentState()
{
    return m_gameStates.back();
}

bool IGameEngine::hasStates()
{
    return !m_gameStates.empty();
}

void IGameEngine::removeAllStates()
{
    while ( !m_gameStates.empty() ) {
        m_gameStates.back()->shutdown();
        m_gameStates.pop_back();
    }
}
