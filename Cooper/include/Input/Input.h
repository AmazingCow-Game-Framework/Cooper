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
// AmazingCow Libs
#include "acow/math_goodies.h"
// Cooper
#include "Keycodes.h"


namespace Cooper {

// "class-like" namespace.
namespace Input
{
    //------------------------------------------------------------------------//
    // Enums / Constants / Typedefs                                           //
    //------------------------------------------------------------------------//
    enum { MouseLeft = 0, MouseMiddle = 1, MouseRight =2 };

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

} // namespace Input
} // namespace Cooper
