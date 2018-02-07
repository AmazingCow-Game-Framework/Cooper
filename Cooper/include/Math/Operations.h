//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Operations.h                                                  //
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
// Cooper
#include "include/Math/Vec2.h"


namespace Cooper { namespace Math {

//----------------------------------------------------------------------------//
// Clamp                                                                      //
//----------------------------------------------------------------------------//
template <typename T>
T Clamp(const T &v, const T &_min, const T &_max)
{
    //COWTODO(n2omatt): We might use std::min, std::max.
    //  So search about perfomance (I saw something on CPPCon...)
    if(v < _min) return _min;
    if(v > _max) return _max;

    return v;
}


//----------------------------------------------------------------------------//
// Lerp                                                                       //
//----------------------------------------------------------------------------//
inline float Lerp(float s, float e, float t)
{
    //Precise formula from wikipedia:
    //  https://en.wikipedia.org/wiki/Linear_interpolation
    return (1.0f - t) * s + (t * e);
}

} // namespace Math
} // namespace Cooper
