//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : TextureEntity.cpp                                             //
//  Project   : Cooper                                                        //
//  Date      : Nov 17, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#include "include/Graphics/TextureEntity.h"
// Cooper
#include "include/Game/RES.h"
#include "include/Graphics/Graphics.h"

// Usings
using namespace Cooper;


//------------------------------------------------------------------------//
// CTOR / DTOR                                                            //
//------------------------------------------------------------------------//
TextureEntity::TextureEntity(
    const std::string &path,
    const acow::math::Vec2 &pos,  /* = Vec2::Zero() */
    const acow::math::Rect &rect  /* = Rect::Empty() */)
    // Base.
    : Entity   (pos)
    // Members.
    , m_pTextureRef(       nullptr)
    , m_renderRect (          rect)
    , m_flip       ( SDL_FLIP_NONE)
    , m_opacity    (          1.0f)
{
    // Get the texture.
    m_pTextureRef = RES::GetTexture(path);

    // The function will calculate the actual rectangle.
    SetRenderRect(rect);
}

TextureEntity::~TextureEntity()
{
    m_pTextureRef = nullptr;
}


//----------------------------------------------------------------------------//
// Update / Render                                                            //
//----------------------------------------------------------------------------//
void TextureEntity::Render()
{
    //--------------------------------------------------------------------------
    // We're fully transparent - So don't need spend cycles drawing it.
    if(m_opacity <= 0.0f || !IsVisible())
        return;

    //--------------------------------------------------------------------------
    // RenderTexture.
    m_pGraphicsRef->RenderTexture(
        m_pTextureRef,
        m_renderRect,
        GetBoundingRect(),
        0,
        acow::math::Vec2::Zero(),
        SDL_RendererFlip(m_flip),
        m_opacity

    );
}
