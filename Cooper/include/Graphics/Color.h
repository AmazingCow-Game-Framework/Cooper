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
//  Date      : Feb 22, 2018                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2018                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

// std
#include <cstdint> // For int types...
// AmazingCow Libs
#include "acow/sdl_goodies.h"


namespace Cooper {

class Color
{
    //------------------------------------------------------------------------//
    //  Enums / Constants / Typedefs                                          //
    //------------------------------------------------------------------------//
public:
    //--------------------------------------------------------------------------
    // BW.
    const static Color White;
    const static Color Black;
    //--------------------------------------------------------------------------
    // Primary Colors.
    const static Color Red;
    const static Color Blue;
    const static Color Green;
    //--------------------------------------------------------------------------
    // Secondary Colors.
    const static Color Cyan;
    const static Color Magenta;
    const static Color Yellow;


    //------------------------------------------------------------------------//
    // CTOR / DTOR                                                            //
    //------------------------------------------------------------------------//
public:
     Color(uint8_t _r = 0, uint8_t _g = 0, uint8_t _b = 0, uint8_t _a = 255)
        : color(SDL_Color{_r,_g,_b,_a})
     {
         // Empty...
     }

    ~Color() = default;


    //------------------------------------------------------------------------//
    // Operators                                                              //
    //------------------------------------------------------------------------//
public:
    inline operator SDL_Color() const { return color; }


    //------------------------------------------------------------------------//
    // iVars                                                                  //
    //------------------------------------------------------------------------//
public:
    union {
        SDL_Color color;
        struct {
            uint8_t r;
            uint8_t g;
            uint8_t b;
            uint8_t a;
        };
    };

}; // class Cooper
}  // namespace Color
