//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Assert.h                                                      //
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
// This will enable the Assertions when the COOPER_DEBUG is defined, but will
// turn the calls into a no-op when isn't.
// So we can spread a lot of assertions on the code to make it more robust and
// easy to develop and maintain and yet have the same performance when the
// code is built to release.
//
// Notice that this is differently from COOPER_VERIFY, which will stay even
// in release builds.
#ifdef COOPER_DEBUG

    #define COOPER_ASSERT(_cond_, _msg_, ...)          \
        ((_cond_))                                     \
         ? (void) 0 /* No-Op */                        \
         : Cooper::Private::_cooper_assert_print_args( \
                #_cond_,                               \
                __FILE__,                              \
                __LINE__,                              \
                __func__,                              \
                (_msg_),                               \
                ##__VA_ARGS__                          \
          )

//------------------------------------------------------------------------------
// Make the assertions a no-op when COOPER_DEBUG isn't defined.
// Fun note:
//   You can check that it's really a no-op here (https://godbolt.org/g/7zAy7Z)
#else // !COOPER_DEBUG

    #define COOPER_ASSERT(_cond_, _msg_, ...) do {} while(0)

#endif // COOPER_DEBUG
