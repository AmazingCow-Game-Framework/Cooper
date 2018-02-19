//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Log.cpp                                                       //
//  Project   : Cooper                                                        //
//  Date      : Nov 17, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

//Header
#include "include/Log/Log.h"
//Cooper
#include "include/Macros/Macros.h"
//Cooper - Private
#include "include/Macros/private/MacrosHelpers.h"

//Usings
using namespace Cooper;


//----------------------------------------------------------------------------//
// MACROS XXX                                                                 //
//----------------------------------------------------------------------------//
// An ugly, nasty macro to save us a lot of typing.
//   I really think that macros are great in this use case.
#define _LOG_FUNC_GUTS(_type_, _output_)                       \
    COOPER_ASSERT(m_initialized, "Log isn't initialized.");    \
                                                               \
    if(!(m_logLevel & (_type_)))                               \
        return;                                                \
                                                               \
    va_list args;                                              \
    va_start(args, msg);                                       \
                                                               \
    /* Forward the '...' to vformat */                         \
    auto buffer = Cooper::Private::vformat(msg.c_str(), args); \
                                                               \
    va_end(args);                                              \
                                                               \
    fprintf(stderr, (_output_), buffer.c_str());


//----------------------------------------------------------------------------//
// Variables                                                                  //
//----------------------------------------------------------------------------//
namespace {
    bool           m_initialized = false;
    Log::LogLevel  m_logLevel;
}


//----------------------------------------------------------------------------//
// Lifecycle Functions                                                        //
//----------------------------------------------------------------------------//
void Log::Init()
{
    COOPER_ASSERT(!m_initialized, "Log is already initialized.");

    m_logLevel    = LOG_LEVEL_VERBOSE;
    m_initialized = true;

    //COWTODO(n2omatt): When we gonna log to files open it here.
}

void Log::Shutdown()
{
    COOPER_ASSERT(m_initialized, "Log isn't initialized.");

    m_initialized = false;

    //COWTODO(n2omatt): When we gonna log to files close it here.
}

bool Log::Initialized()
{
    return m_initialized;
}


//----------------------------------------------------------------------------//
// Set / Get the current LogLevel                                             //
//----------------------------------------------------------------------------//
void Log::SetLogLevel(LogLevel level /* = LOG_LEVEL_VERBOSE */)
{
    COOPER_ASSERT(m_initialized, "Log isn't initialized.");
    m_logLevel = level;
}

Log::LogLevel Log::GetLogLevel()
{
    COOPER_ASSERT(m_initialized, "Log isn't initialized.");
    return m_logLevel;
}


//----------------------------------------------------------------------------//
// Log Functions                                                              //
//----------------------------------------------------------------------------//
void Log::D(std::string msg, ...)
{
    _LOG_FUNC_GUTS(LOG_LEVEL_DEBUG, "[DEBUG]: %s\n");
}

void Log::I(std::string msg, ...)
{
    _LOG_FUNC_GUTS(LOG_LEVEL_INFO, "[INFO]: %s\n");
}

void Log::W(std::string msg, ...)
{
    _LOG_FUNC_GUTS(LOG_LEVEL_WARN, "[WARNING]: %s\n");
}

void Log::E(std::string msg, ...)
{
    _LOG_FUNC_GUTS(LOG_LEVEL_ERROR, "[ERROR]: %s\n");
}
