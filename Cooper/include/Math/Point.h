//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Point.h                                                       //
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

//std
#include <cmath>
//SDL
#include <SDL.h>
//Cooper
#include "include/Math/Vec2.h"

namespace Cooper { namespace Math {

//----------------------------------------------------------------------------//
// Helper Functions                                                           //
//----------------------------------------------------------------------------//
constexpr inline SDL_Point MakePoint(float x, float y) noexcept
{
    return SDL_Point{ int(x), int(y) };
}

constexpr inline SDL_Point MakePoint(int x, int y) noexcept
{
    return SDL_Point{ x, y };
}

constexpr inline SDL_Point MakePoint(const Vec2 &v) noexcept
{
    return SDL_Point{ int(v.x), int(v.y) };
}

} // namespace Math
} // namespace Cooper
