//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Rect.h                                                        //
//  Project   : Cooper                                                        //
//  Date      : Nov 10, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//---------------------------------------------------------------------------~//

#pragma once
// std
#include <cmath>
// SDL
#include <SDL.h>
// Cooper
#include "include/Math/Vec2.h"

namespace Cooper { namespace Math {

//----------------------------------------------------------------------------//
// Constants                                                                  //
//----------------------------------------------------------------------------//
constexpr SDL_Rect RectZero = {0, 0, 0, 0};


//----------------------------------------------------------------------------//
// Helper Functions                                                           //
//----------------------------------------------------------------------------//
constexpr inline SDL_Rect MakeRect(float x, float y, float w, float h) noexcept
{
    return SDL_Rect{ int(x), int(y), int(w), int(h) };
}

constexpr inline SDL_Rect MakeRect(int x, int y, int w, int h) noexcept
{
    return SDL_Rect{ x, y, w, h };
}

constexpr inline SDL_Rect MakeRect(const Vec2 &pos, const Vec2 &size) noexcept
{
    return SDL_Rect{ int(pos.x), int(pos.y), int(size.x), int(size.y) };
}

} // namespace Math
} // namespace Cooper
