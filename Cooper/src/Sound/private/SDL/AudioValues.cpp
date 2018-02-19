//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : AudioValues.cpp                                               //
//  Project   : Cooper                                                        //
//  Date      : Nov 17, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#ifndef EMSCRIPTEN
// Header
#include "src/Sound/private/AudioValues.h"

// Usings
using namespace Cooper;


//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
Private::AudioValues Private::GetPlatformAudioValues()
{
    return AudioValues {
        /* .format    = */ AUDIO_F32,
        /* .frequency = */ 44100,
        /* .channels  = */ 2,
        /* .samples   = */ 512,
    };
}

#endif //#ifndef EMSCRIPTEN
