//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : TextureEntity.h                                               //
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
#include "acow/cpp_goodies.h"
#include "acow/sdl_goodies.h"
#include "acow/math_goodies.h"
// Cooper
#include "include/Game/Entity.h"


namespace Cooper {
//Forward Declarations.
class Graphics;

class TextureEntity
    : public Entity
{
    //------------------------------------------------------------------------//
    // Enums / Constants / Typedefs                                           //
    //------------------------------------------------------------------------//
public:
    ACOW_SMART_PTRS_OF(TextureEntity);


    //------------------------------------------------------------------------//
    // CTOR / DTOR                                                            //
    //------------------------------------------------------------------------//
public:
    explicit TextureEntity(
        const std::string      &path,
        const acow::math::Vec2 &pos  = acow::math::Vec2::Zero (),
        const acow::math::Rect &rect = acow::math::Rect::Empty());

    explicit TextureEntity(
        const std::string      &path,
        const acow::math::Rect &rect)
        // Just forward the call.
        : TextureEntity(path, acow::math::Vec2::Zero(), rect)
    {
        // Empty...
    }

    ~TextureEntity() override;


    //------------------------------------------------------------------------//
    // Size                                                                   //
    //------------------------------------------------------------------------//
public:
    // Getters.
    inline const acow::math::Rect&
    GetRenderRect() const noexcept
    {
        return m_renderRect;
    }

    // Setters.
    inline void SetRenderRect(const acow::math::Rect &rect)
    {
        m_renderRect = rect;
        if(rect.IsEmpty())
            SetSize(acow::sdl::Texture::QuerySize(m_pTextureRef));
    }


    //------------------------------------------------------------------------//
    // Opacity                                                                //
    //------------------------------------------------------------------------//
public:
    // Getters.
    inline f32 GetOpacity() const noexcept { return m_opacity; }

    // Setters.
    inline void SetOpacity(f32 opacity) noexcept { m_opacity = opacity; }


    //------------------------------------------------------------------------//
    // Flip                                                                   //
    //------------------------------------------------------------------------//
public:
    // Getters.
    inline bool
    FlipX() const noexcept
    {
        return ACOW_FLAG_HAS(SDL_FLIP_HORIZONTAL, m_flip);
    }

    inline bool
    FlipY() const noexcept
    {
        return ACOW_FLAG_HAS(SDL_FLIP_VERTICAL, m_flip);
    }

    // Setters.
    inline void
    FlipX(bool b) noexcept
    {
        if(b) ACOW_FLAG_ADD   (u32(SDL_FLIP_HORIZONTAL), m_flip);
        else  ACOW_FLAG_REMOVE(u32(SDL_FLIP_HORIZONTAL), m_flip);
    }

    inline void
    FlipY(bool b) noexcept
    {
        if(b) ACOW_FLAG_ADD   (u32(SDL_FLIP_VERTICAL), m_flip);
        else  ACOW_FLAG_REMOVE(u32(SDL_FLIP_VERTICAL), m_flip);
    }


    //------------------------------------------------------------------------//
    // Update / Render                                                        //
    //------------------------------------------------------------------------//
public:
    void Render() override;


    //------------------------------------------------------------------------//
    // iVars                                                                  //
    //------------------------------------------------------------------------//
private:
    SDL_Texture      *m_pTextureRef;  // Weak poi32er - Owned by RES.
    acow::math::Rect  m_renderRect;   // Which part of the texture that will be drawn.
    i32               m_flip;

    f32 m_opacity;

}; // class TextureEntity
}  // namespace Cooper
