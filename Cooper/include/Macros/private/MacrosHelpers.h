//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : MacrosHelpers.h                                               //
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

// std
#include <cstdarg>
#include <string>

namespace Cooper { namespace Private {

//----------------------------------------------------------------------------//
// Var args                                                                   //
//----------------------------------------------------------------------------//
std::string vformat(const char *fmt, std::va_list list);


//----------------------------------------------------------------------------//
// Assert                                                                     //
//----------------------------------------------------------------------------//
void _cooper_assert_print_args(
    const    char   *expr,
    const    char   *file,
    unsigned int     line,
    const    char   *func,
    const    char   *msg,
    ...);


//----------------------------------------------------------------------------//
// Verify                                                                     //
//----------------------------------------------------------------------------//
void _cooper_verify_print_args(
    const    char   *expr,
    const    char   *file,
    unsigned int     line,
    const    char   *func,
    const    char   *msg,
    ...);

} // namespace Private
} // namespace Cooper
