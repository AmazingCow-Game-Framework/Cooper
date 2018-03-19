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
// AmazingCow Libs
#include "acow/cpp_goodies.h"
#include "acow/sdl_goodies.h"
// Cooper
#include "include/Game/Entity.h"
#include "include/Math/Math.h"
#include "include/Graphics/Color.h"

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
        const std::string &path,
        int               size,
        const std::string &contents,
        const Color       &color = Color::Black);


    //------------------------------------------------------------------------//
    // Text Functions                                                         //
    //------------------------------------------------------------------------//
public:
    // Font.
    void SetFont(const std::string &path, int size);

    // Contents.
    void Contents(const std::string &contents);

    inline const std::string& Contents() const { return m_contents; }

    // Helpers.
private:
    void UpdateTexture();


    //------------------------------------------------------------------------//
    // Render Rect Functions                                                  //
    //------------------------------------------------------------------------//
public:
    // Setters.
    inline void RenderRect(const SDL_Rect &rect)
    {
        m_renderRect          = rect;
        m_overridenRenderRect = true; // Now user decides what render.
    }

    inline void ResetRenderRect()
    {
        m_overridenRenderRect = true; // Now it will render all text.
        UpdateRenderRect();
    }

    // Getters.
    inline const SDL_Rect& RenderRect() const { return m_renderRect; }

    inline bool IsRenderRectOverriden() const { return m_overridenRenderRect; }

    // Helpers.
private:
    void UpdateRenderRect();


    //------------------------------------------------------------------------//
    // Opacity Functions                                                      //
    //------------------------------------------------------------------------//
public:
    // Getters.
    inline float Opacity() const { return m_opacity; }

    // Setters.
    inline void Opacity(float opacity) { m_opacity = opacity; }


    //------------------------------------------------------------------------//
    // Color Functions                                                        //
    //------------------------------------------------------------------------//
public:
    inline const Color& GetColor() const { return m_color; }

    inline void SetColor(const Color &color)
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
    TTF_Font                    *m_pFont; //Weak Reference.
    std::shared_ptr<SDL_Texture> m_pManagedTexture;

    SDL_Rect                     m_renderRect;
    bool                         m_overridenRenderRect;

    std::string m_contents;
    Color       m_color;
    float       m_opacity;

}; // class TextEntity
}  // namespace Cooper
