//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : RES.cpp                                                       //
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
#include "include/Game/RES.h"
// std
#include <map>
// AmazingCow Libs
#include "acow/sdl_goodies.h"
#include "CoreAssert/CoreAssert.h"
#include "CoreFS/CoreFS.h"
// Cooper
#include "include/Graphics/Graphics.h"
#include "include/Graphics/TextureAtlas.h"

// Usings
using namespace Cooper;


//COWNOTE(n2omatt): To think about...
// Currently the Graphics module is responsible to load the texture
// but the RES module is responsible to load Fonts (and in future audio).
// While this implmentation works well, I don't like that the load logic
// is spread across multiple modules.
// Should we:
//   1 - Maintain the current way.
//   2 - Make RES responsible to load everything...
//   3 - Make Graphics responsible for everything related to graphics.
//       Sound responsible for everything related to Sound and RES
//       just be a "cache".
//   4 - Create a loader module to be responsible to load everything
//       and make RES just be a "cache'.

//----------------------------------------------------------------------------//
// Variables                                                                  //
//----------------------------------------------------------------------------//
// Control.
acow_global_variable bool m_initialized = false;

// BasePath.
acow_global_variable std::string m_basePath;

// Maps.
acow_global_variable std::map<std::string, std::shared_ptr<TextureAtlas>> m_atlasMap;
acow_global_variable std::map<std::string, std::shared_ptr<SDL_Texture >> m_texturesMap;
acow_global_variable std::map<std::string, std::shared_ptr<TTF_Font    >> m_fontMap;

// Weak References.
acow_global_variable Graphics *m_pGraphicsRef = nullptr; //Cached for performance.


//------------------------------------------------------------------------------
//  This functions will make an variadic argument list and make it turn
//  into one string. This way we can make keys for resource maps easly.
template<typename T>
acow_internal_function inline std::string
make_key(const T &v) noexcept
{
    return std::to_string(v);
}

template<typename T, typename... Args>
acow_internal_function std::string
make_key(const T &first, Args... args) noexcept
{
    return first + make_key(args...);
}

//----------------------------------------------------------------------------//
// Function Declarations                                                      //
//   Helper functions that doesn't need to be defined "in-place".             //
//----------------------------------------------------------------------------//
acow_internal_function void
free_font(const std::string &key) noexcept;


//----------------------------------------------------------------------------//
// Lifecycle Functions                                                        //
//----------------------------------------------------------------------------//
void
RES::Init(const std::string &path)
{
    COREASSERT_ASSERT(!m_initialized, "RES is already initialized.");

    m_initialized  = true;
    m_pGraphicsRef = Graphics::Instance(); //Cached for performance.
    m_basePath     = path;

    // COWTODO(n2omatt): Check if it exists....
}

void RES::Shutdown()
{
    COREASSERT_ASSERT(m_initialized, "RES isn't initialized.");

    //--------------------------------------------------------------------------
    // Release all Atlases.
    while(!m_atlasMap.empty())
        FreeAtlas(m_atlasMap.begin()->first);

    //--------------------------------------------------------------------------
    // Release all Textures.
    while(!m_texturesMap.empty())
        FreeTexture(m_texturesMap.begin()->first);

    //--------------------------------------------------------------------------
    // Release all Fonts.
    while(!m_fontMap.empty())
        free_font(m_fontMap.begin()->first);

    //COWTODO(n2omatt): Implement for audio.

    m_initialized  = false;
    m_pGraphicsRef = nullptr;
}

bool
RES::IsInitialized() noexcept
{
    return m_initialized;
}


//------------------------------------------------------------------------//
// Path Functions                                                         //
//------------------------------------------------------------------------//
void
RES::SetBasePath(const std::string &path)
{
    // COWTODO(n2omatt): Check if valid.
    m_basePath = path;
}

const std::string&
RES::GetBasePath() noexcept
{
    return m_basePath;
}

std::string
RES::GetFullpath(const std::string &path) noexcept
{
    return CoreFS::Join(m_basePath, {path});
}


//----------------------------------------------------------------------------//
// Atlas Functions                                                            //
//----------------------------------------------------------------------------//
TextureAtlas*
RES::GetAtlas(const std::string &path)
{
    COREASSERT_ASSERT(m_initialized, "RES isn't initialized.");

    //--------------------------------------------------------------------------
    // Assume that Texture is already loaded...
    auto it = m_atlasMap.find(path);
    if(it != std::end(m_atlasMap))
        return it->second.get();

    //--------------------------------------------------------------------------
    // If not, load it now...
    m_atlasMap[path] = std::make_shared<TextureAtlas>(path);
    return m_atlasMap[path].get();
}


void
RES::FreeAtlas(const std::string &path)
{
    COREASSERT_ASSERT(m_initialized, "RES isn't initialized.");

    //--------------------------------------------------------------------------
    // Atlas must exists.
    //   If not User is trying to free something that he doesn't loaded!
    auto it = m_atlasMap.find(path);
    COREASSERT_ASSERT(
        it != std::end(m_atlasMap),
        "Freeing a not loaded Atlas(key): %s",
        path.c_str()
    );

    //--------------------------------------------------------------------------
    // Free the resource.
    m_atlasMap.erase(path);
}


//----------------------------------------------------------------------------//
// Texture Functions                                                          //
//----------------------------------------------------------------------------//
// Get
SDL_Texture*
RES::GetTexture(const std::string &path)
{
    COREASSERT_ASSERT(m_initialized, "RES isn't initialized.");

    //--------------------------------------------------------------------------
    // Assume that Texture is already loaded...
    auto it = m_texturesMap.find(path);
    if(it != std::end(m_texturesMap))
        return it->second.get();

    //--------------------------------------------------------------------------
    // If not, load it now...
    m_texturesMap[path] = std::shared_ptr<SDL_Texture>(
        // Let the Graphics load the Texture for us.
        m_pGraphicsRef->LoadTexture(path),
        // Our custom deleter.
        [=](SDL_Texture *pTexture) {
            SDL_DestroyTexture(pTexture);
        }
    );

    return m_texturesMap[path].get();
}

// Free
void
RES::FreeTexture(const std::string &path)
{
    COREASSERT_ASSERT(m_initialized, "RES isn't initialized.");

    //--------------------------------------------------------------------------
    // Texture must exists.
    //   If not User is trying to free something that he doesn't loaded!
    auto it = m_texturesMap.find(path);
    COREASSERT_ASSERT(
        it != std::end(m_texturesMap),
        "Freeing a not loaded Texture: %s",
        path.c_str()
    );

    //--------------------------------------------------------------------------
    // Free the resource.
    m_texturesMap.erase(path);
}



//----------------------------------------------------------------------------//
// Font Functions                                                             //
//----------------------------------------------------------------------------//
// Get
TTF_Font*
RES::GetFont(const std::string &path, u32 size)
{
    COREASSERT_ASSERT(m_initialized, "RES isn't initialized.");

    //--------------------------------------------------------------------------
    // Assume that Texture is already loaded...
    auto key = make_key(path, size);
    auto it  = m_fontMap.find(key);
    if(it != std::end(m_fontMap))
        return it->second.get();

    //--------------------------------------------------------------------------
    // It's not - so lets load it ;D
    auto p_load_font = TTF_OpenFont(path.c_str(), size);

    COREASSERT_ASSERT(
        p_load_font, //p_font must be a valid pointer.
        "Failed to open Font %s - Size: %d\nTTF_Error:%s",
        path.c_str(),
        size,
        TTF_GetError()
    );

    m_fontMap[key] = std::shared_ptr<TTF_Font>(
        p_load_font,
        // Our custom deleter.
        [=](TTF_Font *pFont) {
            TTF_CloseFont(pFont);
        }
    );

    return m_fontMap[key].get();
}

// Free
void
RES::FreeFont(const std::string &path, u32 size)
{
    COREASSERT_ASSERT(m_initialized, "RES isn't initialized.");
    free_font(make_key(path, size)); //Just forward the call.
}

//------------------------------------------------------------------------------
// We need that function because the "key management" is only internal
// i.e. users will never need to know how we store the resources internally.
// So to the user's point of view the Font is just a 'path' and a 'size'
// but internally is made into a key.
void
free_font(const std::string &key) noexcept
{
    //--------------------------------------------------------------------------
    // Font must exists.
    //   If not User is trying to free something that he doesn't loaded!
    auto it = m_fontMap.find(key);
    COREASSERT_ASSERT(
        it != std::end(m_fontMap),
        "Freeing a not loaded Font(key): %s",
        key.c_str()
    );

    m_fontMap.erase(key);
}
