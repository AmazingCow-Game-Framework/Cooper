//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Verify.h                                                      //
//  Project   : Cooper                                                        //
//  Date      : Nov 17, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

// Headers
#include "include/Macros/private/MacrosHelpers.h"

//----------------------------------------------------------------------------//
// Macros                                                                     //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// This is like COOPER_ASSERT but stays on the code even in release builds.
#define COOPER_VERIFY(_cond_, _msg_, ...)          \
    ((_cond_))                                     \
     ? (void) 0 /* No-Op */                        \
     : Cooper::Private::_cooper_verify_print_args( \
            #_cond_,                               \
            __FILE__,                              \
            __LINE__,                              \
            __func__,                              \
            (_msg_),                               \
            ##__VA_ARGS__                          \
      )
