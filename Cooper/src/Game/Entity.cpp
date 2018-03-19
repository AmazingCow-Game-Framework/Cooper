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

// Usings
using namespace Cooper;


//----------------------------------------------------------------------------//
// CTOR / DTOR                                                                //
//----------------------------------------------------------------------------//
Entity::Entity(const acow::math::Vec2 &pos /* = acow::math::Vec2::Zero() */)
    // Members.
    : m_position    (pos)
    , m_scale       (acow::math::Vec2::One())
    , m_rotation    (0.0f)
    , m_origin      (acow::math::Vec2::Half())
    , m_size        (acow::math::Vec2::Zero())
    , m_enabled     (   true)
    , m_visible     (   true)
    , m_pParentRef  (nullptr)
    , m_pGraphicsRef(Cooper::Graphics::Instance())
    , m_pGameRef    (Cooper::Game    ::Instance())
{
    // Empty...
}

Entity::~Entity()
{
    //--------------------------------------------------------------------------
    // Set the weak references to null.
    m_pParentRef   = nullptr;
    m_pGraphicsRef = nullptr;
    m_pGameRef     = nullptr;
}


//----------------------------------------------------------------------------//
// Parent                                                                     //
//----------------------------------------------------------------------------//
// Setters.
void
Entity::SetParent(Entity *pParent)
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
    auto parent_position = pParent->GetPosition(Space::World);
    auto parent_scale    = pParent->GetScale   (Space::World);
    auto parent_rotation = pParent->GetRotation(Space::World);

    // Position
    m_position = (GetPosition(Space::World) - parent_position)
                     .Rotated(-parent_rotation) / parent_scale;

    // Rotation
    m_rotation -= parent_rotation;

    // Scale
    m_scale /= parent_scale;

    //--------------------------------------------------------------------------
    // Set the new parent.
    m_pParentRef = pParent;
}


// Helpers
void
Entity::RemoveParent()
{
    // Since we're getting detached from Parent we need convert our transform
    // to the world. This way we gonna stay at "same" place.
    m_position = GetPosition(Space::World);
    m_scale    = GetScale   (Space::World);
    m_rotation = GetRotation(Space::World);

    m_pParentRef = nullptr;
}


//----------------------------------------------------------------------------//
// Position                                                                   //
//----------------------------------------------------------------------------//
// Getters
acow::math::Vec2
Entity::GetPosition(Space space /* = Space::World */) const
{
    // When Entity doesn't have a parent it's position is treated as world.
    if(!m_pParentRef || space == Space::Local)
        return m_position;

    // Entity have a parent.
    //   So we need offset by its transform.
    auto rotated_position = (m_position * m_pParentRef->GetScale(Space::World));
    rotated_position.Rotate(m_pParentRef->GetRotation(Space::World));

    return rotated_position + m_pParentRef->GetPosition(Space::World);
}


//----------------------------------------------------------------------------//
// Rotation                                                                   //
//----------------------------------------------------------------------------//
// Getters.
f32
Entity::GetRotation(Space space /* = Space::World */) const
{
    //--------------------------------------------------------------------------
    // When Entity doesn't have a parent it's rotation is treated as world.
    if(!m_pParentRef || space == Space::Local)
        return m_rotation;

    return m_rotation + m_pParentRef->GetRotation(Space::World);
}


//----------------------------------------------------------------------------//
// Scale                                                                      //
//----------------------------------------------------------------------------//
// Getters.
acow::math::Vec2
Entity::GetScale(Space space /* = Space::World */) const
{
    //--------------------------------------------------------------------------
    // When Entity doesn't have a parent it's scale is treated as world.
    if(!m_pParentRef || space == Space::Local)
        return m_scale;

    return m_scale * m_pParentRef->GetScale(Space::World);
}


//----------------------------------------------------------------------------//
// Bounding Rect                                                              //
//----------------------------------------------------------------------------//
acow::math::Rect
Entity::GetBoundingRect() const
{
    const auto &pos    = GetPosition();
    const auto &size   = GetSize    ();
    const auto &origin = GetOrigin  ();
    const auto &scale  = GetScale   ();

    return acow::math::Rect(
        (pos.x - size.x * scale.x * origin.x),
        (pos.y - size.y * scale.y * origin.y),
        (scale.x * size.x),
        (scale.y * size.y)
    );
}
