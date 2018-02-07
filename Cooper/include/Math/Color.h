//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Color.h                                                       //
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
#include <cmath>
// SDL
#include <SDL.h>

namespace Cooper { namespace Math {

//----------------------------------------------------------------------------//
// Constants                                                                  //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// B/W Colors.
constexpr SDL_Color ColorWhite = SDL_Color{255, 255, 255, 255};
constexpr SDL_Color ColorBlack = SDL_Color{  0,   0,   0, 255};

//------------------------------------------------------------------------------
// Primary Colors.
constexpr SDL_Color ColorRed   = SDL_Color{ 255,   0,   0, 255};
constexpr SDL_Color ColorGreen = SDL_Color{   0, 255,   0, 255};
constexpr SDL_Color ColorBlue  = SDL_Color{   0,   0, 255, 255};

//------------------------------------------------------------------------------
// Secondary Colors.
constexpr SDL_Color ColorCyan    = SDL_Color{  0, 255, 255, 255};
constexpr SDL_Color ColorMagenta = SDL_Color{255,   0, 255, 255};
constexpr SDL_Color ColorYellow  = SDL_Color{255, 255,   0, 255};


//----------------------------------------------------------------------------//
// Helper Functions                                                           //
//----------------------------------------------------------------------------//
constexpr inline SDL_Color MakeColor(int r, int g, int b, int a = 255) noexcept
{
    return SDL_Color {
        Uint8(r),
        Uint8(g),
        Uint8(b),
        Uint8(a)
    };
}

} // namespace Math
} // namespace Cooper
