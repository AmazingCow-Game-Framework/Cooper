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
// SDL
#include <SDL.h>
#include <SDL_ttf.h>
// Cooper
#include "include/Game/Entity.h"
#include "include/Macros/Macros.h"
#include "include/Math/Math.h"


namespace Cooper {

class TextEntity
    : public Entity
{
    //------------------------------------------------------------------------//
    // Enums / Constants / Typedefs                                           //
    //------------------------------------------------------------------------//
public:
    COOPER_SMART_PTRS_OF(TextEntity);


    //------------------------------------------------------------------------//
    // CTOR / DTOR                                                            //
    //------------------------------------------------------------------------//
public:
    TextEntity(
        const std::string &path,
        int               size,
        const std::string &contents,
        const SDL_Color   &color = Math::ColorBlack);


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
    // Getters.
    inline const SDL_Color& Color() const { return m_color; }

    // Setters.
    inline void Color(const SDL_Color &color)
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
    SDL_Color   m_color;
    float       m_opacity;

}; // class TextEntity
}  // namespace Cooper
