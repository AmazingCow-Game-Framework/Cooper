//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : TextEntity.cpp                                                //
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
#include "include/Graphics/TextEntity.h"
// Cooper
#include "include/Game/RES.h"
#include "include/Graphics/Graphics.h"

//Usings
using namespace Cooper;


//----------------------------------------------------------------------------//
// CTOR / DTOR                                                                //
//----------------------------------------------------------------------------//
TextEntity::TextEntity(
    const std::string      &path,
    int                    size,
    const std::string      &contents,
    const acow::sdl::Color &color /* = Color::Black */)
    // Member
    : m_pFontRef           (                  nullptr)
    , m_pManagedTexture    (                  nullptr)
    , m_renderRect         (acow::math::Rect::Empty())
    , m_overridenRenderRect(                    false)
    , m_opacity            (                     1.0f)
{
    SetFont    (path, size);
    SetContents(contents  );
    SetColor   (color     );
}


//----------------------------------------------------------------------------//
// Text Methods                                                               //
//----------------------------------------------------------------------------//
// Font.
void TextEntity::SetFont(const std::string &path, int size)
{
    m_pFontRef = RES::GetFont(path, size);
    UpdateTexture();
}

// Contents.
void TextEntity::SetContents(const std::string &contents)
{
    m_contents = contents;
    UpdateTexture();
}

// Helpers.
void TextEntity::UpdateTexture()
{
    //--------------------------------------------------------------------------
    //We're fully transparent - So don't need spend cycles drawing it.
    if(m_contents.empty() || !m_pFontRef)
        return;

    m_pManagedTexture = m_pGraphicsRef->CreateFontTextureManaged(
        m_pFontRef,
        m_contents,
        m_color
    );

    UpdateRenderRect();
    UpdateColor     ();
    SetSize(m_renderRect.GetSize());
}


//----------------------------------------------------------------------------//
// Render Rect Functions                                                      //
//----------------------------------------------------------------------------//
// Helpers.
void TextEntity::UpdateRenderRect()
{
    auto w = 0;
    auto h = 0;
    SDL_QueryTexture(m_pManagedTexture.get(), nullptr, nullptr, &w, &h);

    m_renderRect = acow::math::Rect(0, 0, w, h);
}


//----------------------------------------------------------------------------//
// Color Functions                                                            //
//----------------------------------------------------------------------------//
// Helpers.
void TextEntity::UpdateColor()
{
    SDL_SetTextureColorMod(
        m_pManagedTexture.get(),
        m_color.r,
        m_color.g,
        m_color.b
    );
}


//----------------------------------------------------------------------------//
// Update / Render                                                            //
//----------------------------------------------------------------------------//
void TextEntity::Render()
{
    //--------------------------------------------------------------------------
    //Nothing to draw - So don't need spend cycles drawing it.
    if(m_opacity <= 0.0f || m_contents.empty() || !m_pFontRef || !IsVisible())
        return;

    //--------------------------------------------------------------------------
    // Update the destination rect.
    auto dst = GetBoundingRect();
    dst.SetSize(m_renderRect.GetSize());

    //--------------------------------------------------------------------------
    // RenderTexture.
    m_pGraphicsRef->RenderTexture(
        m_pManagedTexture.get(),
        m_renderRect,
        dst,
        0,
        acow::math::Vec2::Half(),
        SDL_FLIP_NONE,
        m_opacity
    );
}
