//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : StringUtils.cpp                                               //
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
#include "include/String/StringUtils.h"
// Cooper
#include "include/Macros/private/MacrosHelpers.h"

// Usings
using namespace Cooper;


//----------------------------------------------------------------------------//
// Format Functions                                                           //
//----------------------------------------------------------------------------//
std::string StringUtils::Format(const char *pFormat, ...)
{
    va_list args;
    va_start(args, pFormat);

    //Forward the '...' to vFormat.
    auto ret = StringUtils::vFormat(pFormat, args);

    va_end(args);

    return ret;
}

std::string StringUtils::vFormat(const char *pFormat, std::va_list list)
{
    return Private::vformat(pFormat, list);
}
