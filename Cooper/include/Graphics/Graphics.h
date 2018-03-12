//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Graphics.h                                                    //
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
// Amazing Cow Libs
#include "acow/cpp_goodies.h"
#include "acow/sdl_goodies.h"
#include "CoreAssert/CoreAssert.h"


namespace Cooper {

class Graphics
{
    //------------------------------------------------------------------------//
    // Singleton                                                              //
    //------------------------------------------------------------------------//
public:
    ACOW_SINGLETON_OF(Graphics);


    //------------------------------------------------------------------------//
    // Lifecycle Functions                                                    //
    //------------------------------------------------------------------------//
public:
    struct Options
    {
        //----------------------------------------------------------------------
        //
        u16 win_Width;
        u16 win_Height;

        //----------------------------------------------------------------------
        //
        u16 win_MaxWidth;
        u16 win_MaxHeight;

        //----------------------------------------------------------------------
        //
        u16 win_MinWidth;
        u16 win_MinHeight;

        //----------------------------------------------------------------------
        //
        bool win_Resizable;
        u32  win_SDLFlags;

        std::string win_Caption;
    };

    static void Init(const Options &options) noexcept;

    static void Init(u16 width, u16 height, const std::string &caption);
    static void Shutdown();

    static bool IsInitialized() noexcept;


    //------------------------------------------------------------------------//
    // Screen Functions                                                       //
    //------------------------------------------------------------------------//
public:
    inline acow::math::Vec2
    GetScreenSize() const noexcept
    {
        return acow::math::Vec2(m_width, m_height);
    }

    inline i16
    GetScreenWidth() const noexcept
    {
        return m_width;
    }

    inline i16
    GetScreenHeight() const noexcept
    {
        return m_height;
    }

    inline const std::string&
    GetScreenCaption() const noexcept
    {
        return m_caption;
    }

    void SetScreenCaption(const std::string &caption) noexcept;


    //------------------------------------------------------------------------//
    // Texture Creation Functions                                             //
    //------------------------------------------------------------------------//
public:
    SDL_Texture* LoadTexture(const std::string &path);

    SDL_Texture* CreateTexture(
        i32  width,
        i32  height,
        u32  format = SDL_PIXELFORMAT_ARGB8888,
        i32  access = SDL_TEXTUREACCESS_STATIC)
    {
        COREASSERT_ASSERT(m_initialized, "Graphics isn't initialized.");

        auto p_texture = SDL_CreateTexture(
            m_pRenderer.get(),
            format,
            access,
            width,
            height
        );

        COREASSERT_VERIFY(
            p_texture, //Texture must be not null...
            "Failed to create texture!\nSDL_Error: %s",
            SDL_GetError()
        );

        return p_texture;
    }


    //--------------------------------------------------------------------------
    // NOT MANAGED!
    //   Users must call SDL_DestroyTexture() themselves or
    //   a memory leak will occur.
    SDL_Texture* CreateFontTexture(
        TTF_Font                *pFont,
        const std::string       &contents,
        const acow::sdl::Color  &color);

    //--------------------------------------------------------------------------
    // MANAGED!
    //   The destruction of this texture is handled by the std::shared_ptr
    //   itself, so users don't need to worry about memory leaks.
    std::shared_ptr<SDL_Texture> CreateFontTextureManaged(
        TTF_Font               *pFont,
        const std::string      &contents,
        const acow::sdl::Color &color);


    //------------------------------------------------------------------------//
    // Rendering Functions                                                    //
    //------------------------------------------------------------------------//
public:
    inline void
    SetClearColor(const acow::sdl::Color &c) noexcept
    {
        COREASSERT_ASSERT(m_initialized, "Graphics isn't initialized.");

        m_clearColor = c;
        SDL_SetRenderDrawColor(
            m_pRenderer.get(),
            c.r * 0xFF,
            c.g * 0xFF,
            c.b * 0xFF,
            0xFF
        );
    }

    inline void
    Clear() noexcept
    {
        COREASSERT_ASSERT(m_initialized, "Graphics isn't initialized.");
        SDL_RenderClear(m_pRenderer.get());
    }

    inline void
    Present() noexcept
    {
        COREASSERT_ASSERT(m_initialized, "Graphics isn't initialized.");
        SDL_RenderPresent(m_pRenderer.get());
    }


    //--------------------------------------------------------------------------
    // Texture.
    void RenderTexture(
        SDL_Texture            *pTexture,
        const acow::math::Rect  &srcRect,
        const acow::math::Rect  &dstRect,
        float                    angleDegrees,
        const acow::math::Vec2  &origin,
        SDL_RendererFlip         flip    = SDL_FLIP_NONE,
        float                    opacity = 1.0f         ) noexcept;


    //--------------------------------------------------------------------------
    // Rectangle.
    void RenderRect(
        const acow::math::Rect &rect,
        const acow::sdl::Color &color = acow::sdl::Color::White());

    //--------------------------------------------------------------------------
    // Circle.
    void RenderCircle(
        const acow::math::Vec2 &center,
        f32                     radius,
        const acow::sdl::Color &color = acow::sdl::Color::White(),
        i32                     sides = -1);

    //--------------------------------------------------------------------------
    // Line.
    void RenderLine(
        const acow::math::Vec2 &start,
        const acow::math::Vec2 &end,
        const acow::sdl::Color& color);


    //------------------------------------------------------------------------//
    // iVars.                                                                 //
    //------------------------------------------------------------------------//
public:
    // Control.
    bool              m_initialized;
    acow::sdl::Color  m_clearColor;

    // Window.
    i32         m_width;
    i32         m_height;
    std::string m_caption;

    // SDL.
    acow::sdl::Window  ::UPtr m_pWindow;
    acow::sdl::Renderer::UPtr m_pRenderer;

}; // class Graphics
}  // namespace Cooper
