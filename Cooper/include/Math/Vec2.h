//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Vec2.h                                                        //
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

// SDL
#include <SDL.h>
// std
#include <cmath>
// Cooper
#include "include/Math/Constants.h"

namespace Cooper {

struct Vec2
{
    //------------------------------------------------------------------------//
    // Static Functions                                                       //
    //------------------------------------------------------------------------//
    constexpr inline static Vec2 Zero() noexcept { return Vec2{ 0.0f, 0.0f }; }
    constexpr inline static Vec2 One () noexcept { return Vec2{ 1.0f, 1.0f }; }
    constexpr inline static Vec2 Half() noexcept { return Vec2{ 0.5f, 0.5f }; }

    constexpr inline static Vec2 Left () noexcept { return Vec2{ -1.0f,  0.0f }; }
    constexpr inline static Vec2 Right() noexcept { return Vec2{ +1.0f,  0.0f }; }
    constexpr inline static Vec2 Up   () noexcept { return Vec2{  0.0f, -1.0f }; }
    constexpr inline static Vec2 Down () noexcept { return Vec2{  0.0f, +1.0f }; }


    //-------------------------------------------------------------------------//
    // Public Vars                                                             //
    //-------------------------------------------------------------------------//
    float x; float y;


    //------------------------------------------------------------------------//
    // CTOR / DTOR                                                            //
    //------------------------------------------------------------------------//
    constexpr explicit Vec2(float x = 0.0f, float y = 0.0f) noexcept :
        x(x), y(y)
    {
        //Empty...
    }

    constexpr explicit Vec2(const SDL_Point &point) noexcept :
        Vec2(point.x, point.y)
    {
        //Empty...
    }



    //------------------------------------------------------------------------//
    // Magnitude                                                              //
    //------------------------------------------------------------------------//
    inline float Magnitude   () { return sqrtf(x*x + y*y); }
    inline float MagnitudeSqr() { return       x*x + y*y;  }


    //------------------------------------------------------------------------//
    // Distance                                                               //
    //------------------------------------------------------------------------//
    inline float Distance(const Vec2 v2)
    {
        return sqrtf(powf(x - v2.x, 2) + powf(y - v2.y, 2));
    }

    inline float DistanceSqr(const Vec2 v2)
    {
        return powf(x - v2.x, 2) + powf(y - v2.y, 2);
    }


    //------------------------------------------------------------------------//
    // Normalize                                                              //
    //------------------------------------------------------------------------//
    inline void Normalize()
    {
        auto magnitude = Magnitude();
        x /= magnitude; y /= magnitude;
    }

    inline Vec2 Normalized()
    {
        auto vec2 = Vec2(*this);
        vec2.Normalize();

        return vec2;
    }


    //------------------------------------------------------------------------//
    // Rotation                                                               //
    //------------------------------------------------------------------------//
    inline void Rotate(float degrees)
    {
        auto r = (degrees * Math::kDegrees2Radians);
        auto s = sinf(r);
        auto c = cosf(r);

        x = (x * c - y * s);
        y = (x * s + y * c);
    }

    inline Vec2 Rotated(float degrees) const
    {
        auto vec2 = Vec2(*this);
        vec2.Rotate(degrees);

        return vec2;
    }


    //------------------------------------------------------------------------//
    // Operators                                                              //
    //------------------------------------------------------------------------//
    constexpr friend Vec2 operator +(const Vec2 &lhs, const Vec2 &rhs);
    constexpr friend Vec2 operator -(const Vec2 &lhs, const Vec2 &rhs);
    constexpr friend Vec2 operator *(const Vec2 &lhs, const Vec2 &rhs);
    constexpr friend Vec2 operator /(const Vec2 &lhs, const Vec2 &rhs);

    constexpr friend Vec2& operator +=(Vec2 &lhs, const Vec2 &rhs);
    constexpr friend Vec2& operator -=(Vec2 &lhs, const Vec2 &rhs);
    constexpr friend Vec2& operator *=(Vec2 &lhs, const Vec2 &rhs);
    constexpr friend Vec2& operator /=(Vec2 &lhs, const Vec2 &rhs);


    constexpr friend Vec2 operator*(const Vec2 &lhs, float scalar);
    constexpr friend Vec2 operator*(float scalar, const Vec2 &rhs);

}; //struct Vec2


//----------------------------------------------------------------------------//
// Operators Implementation.                                                  //
//----------------------------------------------------------------------------//
constexpr inline Vec2 operator +(const Vec2 &lhs, const Vec2 &rhs)
{
    return Vec2(lhs.x + rhs.x, lhs.y + rhs.y);
}

constexpr inline Vec2 operator -(const Vec2 &lhs, const Vec2 &rhs)
{
    return Vec2(lhs.x - rhs.x, lhs.y - rhs.y);
}

constexpr inline Vec2 operator *(const Vec2 &lhs, const Vec2 &rhs)
{
    return Vec2(lhs.x * rhs.x, lhs.y * rhs.y);
}

constexpr inline Vec2 operator /(const Vec2 &lhs, const Vec2 &rhs)
{
    return Vec2(lhs.x / rhs.x, lhs.y / rhs.y);
}


constexpr inline Vec2& operator +=(Vec2 &lhs, const Vec2 &rhs)
{
    lhs.x += rhs.x; lhs.y += rhs.y;
    return lhs;
}

constexpr inline Vec2& operator -=(Vec2 &lhs, const Vec2 &rhs)
{
    lhs.x -= rhs.x; lhs.y -= rhs.y;
    return lhs;
}

constexpr inline Vec2& operator *=(Vec2 &lhs, const Vec2 &rhs)
{
    lhs.x *= rhs.x; lhs.y *= rhs.y;
    return lhs;
}

constexpr inline Vec2& operator /=(Vec2 &lhs, const Vec2 &rhs)
{
    lhs.x /= rhs.x; lhs.y /= rhs.y;
    return lhs;
}


constexpr inline Vec2 operator*(const Vec2 &lhs, float scalar)
{
    return Vec2(lhs.x * scalar, lhs.y * scalar);
}

constexpr inline Vec2 operator*(float scalar, const Vec2 &rhs)
{
    return rhs * scalar;
}

} // namespace Cooper
