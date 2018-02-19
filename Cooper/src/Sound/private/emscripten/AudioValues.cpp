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

#ifdef EMSCRIPTEN

// Header
#include "src/Sound/private/AudioValues.h"
// Emscripten
#include <emscripten/emscripten.h>

// Usings
using namespace Cooper;

//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
Private::AudioValues Private::GetPlatformAudioValues()
{
    //--------------------------------------------------------------------------
    // This will try to get the best browser frequency.
    // Taken from:
    //   https://github.com/kripken/emscripten/issues/3985
    const auto frequency = EM_ASM_INT_V({
        var context;
        try {
            context = new AudioContext();
        } catch (e) {
            context = new webkitAudioContext();
        }
        return context.sampleRate;
    });

    return AudioValues {
       .format     = AUDIO_F32,
        .frequency = frequency,
        .channels  = 2,
        .samples   = 512,
    };
}

#endif // #ifdef EMSCRIPTEN
