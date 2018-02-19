//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Entity.cpp                                                    //
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
#include "include/Game/Entity.h"
// Cooper
#include "include/Game/Game.h"
#include "include/Graphics/Graphics.h"

//Usings
using namespace Cooper;


//----------------------------------------------------------------------------//
// CTOR / DTOR                                                                //
//----------------------------------------------------------------------------//
Entity::Entity(const Vec2 &pos /* = Vec2::Zero() */) :
    // Members.
    m_position(pos),
    m_scale   (Vec2::One()),
    m_rotation(0.0f),
    m_origin  (Vec2::Half()),
    m_size    (Vec2::Zero()),
    m_enabled (true),
    m_visible (true),
    m_pParent (nullptr),
    m_pGraphicsRef(Cooper::Graphics::Instance()),
    m_pGameRef    (Cooper::Game    ::Instance())
{
    //Empty...
}

Entity::~Entity()
{
    //--------------------------------------------------------------------------
    // Set the weak references to null.
    m_pParent      = nullptr;
    m_pGraphicsRef = nullptr;
    m_pGameRef     = nullptr;
}


//----------------------------------------------------------------------------//
// Parent                                                                     //
//----------------------------------------------------------------------------//
// Setters.
void Entity::Parent(Entity *pParent)
{
    //--------------------------------------------------------------------------
    // We're losing our parent - So let's make our transform to world.
    if(!pParent)
    {
        RemoveParent();
        return;
    }

    //--------------------------------------------------------------------------
    // Attaching to new parent - So let's update our transform.
    auto parent_position = pParent->Position(Space::World);
    auto parent_scale    = pParent->Scale   (Space::World);
    auto parent_rotation = pParent->Rotation(Space::World);

    // Position
    m_position = (Position(Space::World) - parent_position)
                     .Rotated(-parent_rotation) / parent_scale;

    // Rotation
    m_rotation -= parent_rotation;

    // Scale
    m_scale /= parent_scale;

    //--------------------------------------------------------------------------
    // Set the new parent.
    m_pParent = pParent;
}


// Helpers
void Entity::RemoveParent()
{
    // Since we're getting detached from Parent we need convert our transform
    // to the world. This way we gonna stay at "same" place.
    m_position = Position(Space::World);
    m_scale    = Scale   (Space::World);
    m_rotation = Rotation(Space::World);

    m_pParent = nullptr;
}


//----------------------------------------------------------------------------//
// Position                                                                   //
//----------------------------------------------------------------------------//
// Getters
Vec2 Entity::Position(Space space /* = Space::World */) const
{
    // When Entity doesn't have a parent it's position is treated as world.
    if(!m_pParent || space == Space::Local)
        return m_position;

    // Entity have a parent.
    //   So we need offset by its transform.
    auto rotated_position = (m_position * m_pParent->Scale(Space::World));
    rotated_position.Rotate(m_pParent->Rotation(Space::World));

    return rotated_position + m_pParent->Position(Space::World);
}


//----------------------------------------------------------------------------//
// Rotation                                                                   //
//----------------------------------------------------------------------------//
// Getters.
float Entity::Rotation(Space space /* = Space::World */) const
{
    //When Entity doesn't have a parent it's rotation is treated as world.
    if(!m_pParent || space == Space::Local)
        return m_rotation;

    return m_rotation + m_pParent->Rotation(Space::World);
}


//----------------------------------------------------------------------------//
// Scale                                                                      //
//----------------------------------------------------------------------------//
// Getters.
Vec2 Entity::Scale(Space space /* = Space::World */) const
{
    //When Entity doesn't have a parent it's scale is treated as world.
    if(!m_pParent || space == Space::Local)
        return m_scale;

    return m_scale * m_pParent->Scale(Space::World);
}


//----------------------------------------------------------------------------//
// Bounding Rect                                                              //
//----------------------------------------------------------------------------//
SDL_Rect Entity::BoundingRect() const
{
    const auto &pos    = Position();
    const auto &size   = Size    ();
    const auto &origin = Origin  ();
    const auto &scale  = Scale   ();

    return Math::MakeRect(
        (pos.x - size.x * scale.x * origin.x),
        (pos.y - size.y * scale.y * origin.y),
        (scale.x * size.x),
        (scale.y * size.y)
    );
}
