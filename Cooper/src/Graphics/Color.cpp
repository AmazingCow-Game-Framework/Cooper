//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Color.cpp                                                     //
//  Project   : Cooper                                                        //
//  Date      : Feb 22, 2018                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2018                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

// Header
#include "include/Graphics/Color.h"

// Usings
using namespace Cooper;

//----------------------------------------------------------------------------//
// Enums / Contants / Typedefs                                                //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// BW.
const Color Color::White(255, 255, 255);
const Color Color::Black(  0,   0,   0);

//------------------------------------------------------------------------------
// Primary Colors.
const Color Color::Red  (255,   0,   0);
const Color Color::Green(0,   255,   0);
const Color Color::Blue (0,     0, 255);

//------------------------------------------------------------------------------
// Secondary Colors.
const Color Color::Cyan   (0,   255, 255);
const Color Color::Magenta(255,   0, 255);
const Color Color::Yellow (255, 255,   0);
