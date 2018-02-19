//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Log.h                                                         //
//  Project   : Cooper                                                        //
//  Date      : Nov 17, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

// std
#include <string>

namespace Cooper {

//class-like namespace
namespace Log {

    //------------------------------------------------------------------------//
    // Enum / Constants / Typedefs                                            //
    //------------------------------------------------------------------------//
    enum {
        LOG_LEVEL_NONE    = 0,
        LOG_LEVEL_DEBUG   = 1 << 0,
        LOG_LEVEL_INFO    = 1 << 1,
        LOG_LEVEL_WARN    = 1 << 2,
        LOG_LEVEL_ERROR   = 1 << 3,
        LOG_LEVEL_VERBOSE = LOG_LEVEL_DEBUG |
                            LOG_LEVEL_INFO  |
                            LOG_LEVEL_WARN  |
                            LOG_LEVEL_ERROR
    };

    typedef unsigned int LogLevel;


    //------------------------------------------------------------------------//
    // Lifecycle Functions                                                    //
    //------------------------------------------------------------------------//
    void Init    ();
    void Shutdown();

    bool Initialized();


    //------------------------------------------------------------------------//
    // Set / Get the Current LogLevel                                         //
    //------------------------------------------------------------------------//
    void     SetLogLevel(LogLevel level = LOG_LEVEL_VERBOSE);
    LogLevel GetLogLevel();


    //------------------------------------------------------------------------//
    // Log Functions                                                          //
    //------------------------------------------------------------------------//
    void D(std::string msg, ...);
    void I(std::string msg, ...);
    void W(std::string msg, ...);
    void E(std::string msg, ...);

} // namespace Log
} // namespace Cooper
