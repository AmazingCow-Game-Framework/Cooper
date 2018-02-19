//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Sound.cpp                                                     //
//  Project   : Cooper                                                        //
//  Date      : Nov 17, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

// Header
#include "include/Sound/Sound.h"
// std
#include <map>
// Cooper
#include "include/Log/Log.h"
#include "include/Macros/Macros.h"
#include "include/Memory/Memory.h"
// Cooper Sound - Private.
#include "src/Sound/private/AudioLib.h"
#include "src/Sound/private/AudioValues.h"

// Usings
using namespace Cooper;


//----------------------------------------------------------------------------//
// Variables                                                                  //
//----------------------------------------------------------------------------//
namespace {
    // Control.
    bool m_initialized = false;

    // Maps
    std::map<std::string, std::shared_ptr<Audio>> m_audioMap;
}


//----------------------------------------------------------------------------//
// Lifecycle Functions                                                        //
//----------------------------------------------------------------------------//
void Sound::Init()
{
    COOPER_ASSERT(!m_initialized, "Sound is already initialized.");

    //--------------------------------------------------------------------------
    // Init the Audio subsystem.
    if(!(SDL_WasInit(SDL_INIT_AUDIO) & SDL_INIT_AUDIO))
        SDL_InitSubSystem(SDL_INIT_AUDIO);

    //--------------------------------------------------------------------------
    // Let the underlying platform decide its best values.
    auto audio_values = Private::GetPlatformAudioValues();

    //--------------------------------------------------------------------------
    // Initialize the audio library.
    initAudio(
        audio_values.format,
        audio_values.frequency,
        audio_values.channels,
        audio_values.samples
    );

    //--------------------------------------------------------------------------
    // Set our control values.
    m_initialized = true;
}

void Sound::Shutdown()
{
    COOPER_ASSERT(m_initialized, "Sound isn't initialized.");

    //--------------------------------------------------------------------------
    // Init the Audio subsystem.
    if(!(SDL_WasInit(SDL_INIT_AUDIO) & SDL_INIT_AUDIO))
        SDL_QuitSubSystem(SDL_INIT_AUDIO);

    //--------------------------------------------------------------------------
    // Set our control values.
    m_initialized = false;

    //--------------------------------------------------------------------------
    // Release te allocated resources.
    for(const auto &item : m_audioMap)
        FreeSound(item.first);

    //--------------------------------------------------------------------------
    // Quit the audio library.
    endAudio();
}


bool Sound::Initialized()
{
    return m_initialized;
}


//----------------------------------------------------------------------------//
// Sound Functions                                                            //
//----------------------------------------------------------------------------//
void Sound::PreloadSound(const std::vector<std::string> &soundNames)
{
    COOPER_ASSERT(m_initialized, "Sound isn't initialized.");

    for(const auto &sound_name : soundNames)
    {
        // Already loaded - Don't need load it again...
        if(IsLoaded(sound_name))
            continue;

        auto p_audio = createAudio(sound_name.c_str(), 0, SDL_MIX_MAXVOLUME / 2);
        m_audioMap[sound_name] = std::shared_ptr<Audio>(
            // Our audio raw pointer.
            p_audio,
            // Our custom deleter.
            [=](Audio *pAudio) {
                free(pAudio);
            }
        );
    }
}

void Sound::FreeSound(const std::string &path)
{
    COOPER_ASSERT(m_initialized, "Sound isn't initialized.");
    COOPER_ASSERT(IsLoaded(path), "Freeing a not loaded Sound: %s", path.c_str());

    m_audioMap.erase(path);
}

bool Sound::IsLoaded(const std::string &path)
{
    COOPER_ASSERT(m_initialized, "Sound isn't initialized.");
    return m_audioMap.find(path) != std::end(m_audioMap);
}


void Sound::PlaySound(const std::string &path)
{
    COOPER_ASSERT(m_initialized, "Sound isn't initialized.");

    //--------------------------------------------------------------------------
    // Assume that sound isn't loaded.
    //   So load and cache it.
    if(m_audioMap.find(path) == std::end(m_audioMap))
        PreloadSound({path});

    //--------------------------------------------------------------------------
    // Now we're sure that sound is loaded.
    playSoundFromMemory(m_audioMap[path].get(), SDL_MIX_MAXVOLUME / 2);
}
