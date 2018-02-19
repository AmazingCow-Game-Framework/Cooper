//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Timer.cpp                                                     //
//  Project   : Cooper                                                        //
//  Date      : Nov 17, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

// Header
#include "include/Timer/Timer.h"
// Cooper
#include "include/Macros/Macros.h"

// Usings
using namespace Cooper;


//----------------------------------------------------------------------------//
// CTOR / DTOR                                                                //
//----------------------------------------------------------------------------//
Timer::Timer() :
    m_startTime   (0),
    m_frequency   (SDL_GetPerformanceFrequency()), // COWTODO(n2omatt): Should this be static?
    m_deltaTime   (0),
    m_totalTime   (0),
    m_timeScale   (1),
    m_initialized (false)
{
    //Empty...
}


//----------------------------------------------------------------------------//
// Control Functions                                                          //
//----------------------------------------------------------------------------//
void Timer::Reset()
{
    m_startTime = SDL_GetPerformanceCounter();
    m_deltaTime = 0;
    m_totalTime = 0;

    m_initialized = true;
}

void Timer::Update()
{
    COOPER_ASSERT(m_initialized, "Timer isn't initialized - Call Reset().");
    Restart();
}

float Timer::Restart()
{
    auto current = SDL_GetPerformanceCounter();
    auto elapsed = current - m_startTime;
    m_startTime  = current;

    m_deltaTime  = float(elapsed) / float(m_frequency);
    m_totalTime += m_deltaTime;

    return m_deltaTime;
}
