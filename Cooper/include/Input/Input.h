//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Input.h                                                       //
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
#include <string>
// Cooper
#include "acow/math_goodies.h"

namespace Cooper {

// "class-like" namespace.
namespace Input
{
    //------------------------------------------------------------------------//
    // Lifecycle Functions                                                    //
    //------------------------------------------------------------------------//
    void Init    ();
    void Shutdown();

    bool IsInitialized() noexcept;

    void Update    ();
    void PostUpdate();


    //------------------------------------------------------------------------//
    // Keyboard Functions                                                     //
    //------------------------------------------------------------------------//
    //--------------------------------------------------------------------------
    // Check if there is any keyboard input on this frame.
    bool HasKeyboardInput();

    //--------------------------------------------------------------------------
    // True every time that key is down.
    bool IsKeyDown(u32 key);

    //--------------------------------------------------------------------------
    // True only on the frame that key is down.
    bool IsKeyPress(u32 key);

    //--------------------------------------------------------------------------
    // True only on the frame that key is up.
    bool IsKeyRelease(u32 key);


    //------------------------------------------------------------------------//
    // Mouse Functions                                                        //
    //------------------------------------------------------------------------//
    //--------------------------------------------------------------------------
    // Check if there is any mouse input on this frame.
    bool HasMouseInput();

    //--------------------------------------------------------------------------
    // The position of mouse - Relative to the screen.
    const acow::math::Vec2& GetMousePosition();

    //COWTODO(n2omatt): Should we use a enumeration to better reading?
    //--------------------------------------------------------------------------
    // True every time that button is down.
    bool IsMouseButtonDown(u8 button);

    //--------------------------------------------------------------------------
    // True only on the frame that button is down.
    bool IsMouseButtonPress(u8 button);

    //--------------------------------------------------------------------------
    // True only on the frame that button is up.
    bool IsMouseButtonRelease(u8 button);

} // namespace Input
} // namespace Cooper
