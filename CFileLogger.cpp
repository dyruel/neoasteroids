//
//  CFileLogger.cpp
//  NeoAsteroids
//
//  Created by Morgan on 30/12/14.
//  Copyright (c) 2014 Morgan Chopin. All rights reserved.
//

#include "CFileLogger.h"

CFileLogger* CFileLogger::m_instance = nullptr;
std::ofstream CFileLogger::m_file("log.txt");

void CFileLogger::logFormat( const c8 * format, ...)
{
    char buf[256];
    
    va_list args;
    va_start (args, format);
    vsprintf (buf, format, args);
    va_end (args);
    
    m_file << buf;
}

void CFileLogger::log( const c8* msg )
{
    m_file << msg;
}
