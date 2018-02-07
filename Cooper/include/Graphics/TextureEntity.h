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
// SDL
#include <SDL.h>
// Cooper
#include "include/Game/Entity.h"
#include "include/Math/Math.h"
#include "include/Macros/Macros.h"


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
    COOPER_SMART_PTRS_OF(TextureEntity);


    //------------------------------------------------------------------------//
    // CTOR / DTOR                                                            //
    //------------------------------------------------------------------------//
public:
    explicit TextureEntity(
        const std::string &path,
        const Vec2        &pos  = Vec2::Zero(),
        const SDL_Rect    &rect = Math::RectZero);

    explicit TextureEntity(
        const std::string &path,
        const SDL_Rect    &rect = Math::RectZero) :
        // Just forward the call.
        TextureEntity(path, Vec2::Zero(), rect)
    {
        //Empty...
    }

    ~TextureEntity() override;


    //------------------------------------------------------------------------//
    // Size                                                                   //
    //------------------------------------------------------------------------//
public:
    // Getters.
    inline SDL_Rect RenderRect() const { return m_renderRect; }

    // Setters.
    inline void RenderRect(const SDL_Rect &rect)
    {
        m_renderRect = rect;
        if(m_renderRect.w == 0 || m_renderRect.h == 0)
        {
            SDL_QueryTexture(
                m_pTexture,
                nullptr,
                nullptr,
                &m_renderRect.w,
                &m_renderRect.h
            );
        }

        Size(m_renderRect.w, m_renderRect.h);
    }


    //------------------------------------------------------------------------//
    // Opacity                                                                //
    //------------------------------------------------------------------------//
public:
    // Getters.
    inline float Opacity() const { return m_opacity; }

    // Setters.
    inline void Opacity(float opacity) { m_opacity = opacity; }


    //------------------------------------------------------------------------//
    // Flip                                                                   //
    //------------------------------------------------------------------------//
public:
    // Getters.
    inline bool FlipX() const { return m_flip & SDL_FLIP_HORIZONTAL; }
    inline bool FlipY() const { return m_flip & SDL_FLIP_VERTICAL;   }

    // Setters.
    inline void FlipX(bool b)
    {
        m_flip = (b)
            ? (m_flip | SDL_FLIP_HORIZONTAL)
            : (m_flip & SDL_FLIP_VERTICAL  );
    }

    inline void FlipY(bool b)
    {
        m_flip = (b)
            ? (m_flip | SDL_FLIP_VERTICAL  )
            : (m_flip & SDL_FLIP_HORIZONTAL);
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
    SDL_Texture *m_pTexture;   // Weak pointer - Owned by RES.
    SDL_Rect    m_renderRect; // Which part of the texture that will be drawn.
    int         m_flip;

    float m_opacity;

}; // class TextureEntity
}  // namespace Cooper
