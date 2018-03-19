//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : TextEntity.h                                                  //
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
#include <cstdarg>
// AmazingCow Libs
#include "acow/cpp_goodies.h"
#include "acow/sdl_goodies.h"
#include "acow/math_goodies.h"
// Cooper
#include "include/Game/Entity.h"

namespace Cooper {

class TextEntity
    : public Entity
{
    //------------------------------------------------------------------------//
    // Enums / Constants / Typedefs                                           //
    //------------------------------------------------------------------------//
public:
    ACOW_SMART_PTRS_OF(TextEntity);


    //------------------------------------------------------------------------//
    // CTOR / DTOR                                                            //
    //------------------------------------------------------------------------//
public:
    TextEntity(
        const std::string      &path,
        int                     size,
        const std::string      &contents,
        const acow::sdl::Color &color = acow::sdl::Color::Black());


    //------------------------------------------------------------------------//
    // Text Functions                                                         //
    //------------------------------------------------------------------------//
public:
    // Font.
    void SetFont(const std::string &path, int size);

    // Contents.
    inline const std::string&
    GetContents() const noexcept
    {
        return m_contents;
    }

    void SetContents(const std::string &format, ...);

    // Helpers.
private:
    void UpdateTexture();


    //------------------------------------------------------------------------//
    // Render Rect Functions                                                  //
    //------------------------------------------------------------------------//
public:
    inline void
    SetRenderRect(const acow::math::Rect &rect) noexcept
    {
        m_renderRect          = rect;
        m_overridenRenderRect = true; // Now user decides what render.
    }

    inline void
    ResetRenderRect()
    {
        m_overridenRenderRect = true; // Now it will render all text.
        UpdateRenderRect();
    }

    // Getters.
    inline const acow::math::Rect&
    GetRenderRect() const noexcept
    {
        return m_renderRect;
    }

    inline bool
    IsRenderRectOverriden() const noexcept
    {
        return m_overridenRenderRect;
    }


    // Helpers.
private:
    void UpdateRenderRect();


    //------------------------------------------------------------------------//
    // Opacity Functions                                                      //
    //------------------------------------------------------------------------//
public:
    inline float GetOpacity() const noexcept
    {
        return m_opacity;
    }

    inline void
    SetOpacity(float opacity) noexcept
    {
        m_opacity = opacity;
    }


    //------------------------------------------------------------------------//
    // Color Functions                                                        //
    //------------------------------------------------------------------------//
public:
    inline const acow::sdl::Color&
    GetColor() const noexcept
    {
        return m_color;
    }

    inline void
    SetColor(const acow::sdl::Color &color) noexcept
    {
        m_color = color;
        UpdateColor();
    }

    // Helpers.
private:
    void UpdateColor();


    //------------------------------------------------------------------------//
    // Update / Render                                                        //
    //------------------------------------------------------------------------//
public:
    void Render() override;


    //------------------------------------------------------------------------//
    // iVars                                                                  //
    //------------------------------------------------------------------------//
private:
    TTF_Font                 *m_pFontRef;        //Weak Reference.
    acow::sdl::Texture::SPtr  m_pManagedTexture;

    acow::math::Rect m_renderRect;
    bool             m_overridenRenderRect;

    std::string      m_contents;
    acow::sdl::Color m_color;
    float            m_opacity;

}; // class TextEntity
}  // namespace Cooper
