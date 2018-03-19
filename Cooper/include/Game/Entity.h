//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Entity.h                                                      //
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
// AmazingCow Libs
#include "acow/cpp_goodies.h"
#include "acow/math_goodies.h"


namespace Cooper {
// Forward declarations.
class Game;
class Graphics;

class Entity
{
    //------------------------------------------------------------------------//
    // Enums / Constants / Typedefs                                           //
    //------------------------------------------------------------------------//
public:
    ACOW_SMART_PTRS_OF(Entity);

    enum class Space { Local, World };


    //------------------------------------------------------------------------//
    // CTOR / DTOR                                                            //
    //------------------------------------------------------------------------//
public:
    explicit Entity(const acow::math::Vec2 &pos = acow::math::Vec2::Zero());
    virtual ~Entity();


    //------------------------------------------------------------------------//
    // Parent                                                                 //
    //------------------------------------------------------------------------//
public:
    // Getters.
    inline const Entity* GetParent() const noexcept { return m_pParentRef; }
    // Setters.
    void SetParent(Entity *pParent);

    // Helpers.
private:
    void RemoveParent();


    //------------------------------------------------------------------------//
    // Enabled / Visible                                                      //
    //------------------------------------------------------------------------//
public:
    // Getters.
    inline bool IsEnabled() const { return m_enabled; }
    inline bool IsVisible() const { return m_visible; }

    // Setters.
    inline void SetEnabled(bool enable ) { m_enabled = enable;  }
    inline void SetVisible(bool visible) { m_visible = visible; }


    //------------------------------------------------------------------------//
    // Position                                                               //
    //------------------------------------------------------------------------//
public:
    // Getters.
    acow::math::Vec2 GetPosition(Space space = Space::World) const;

    // Setters.
    inline void
    SetPosition(const acow::math::Vec2 &pos)
    {
        m_position = pos;
    }

    inline void
    SetPosition(f32 x, f32 y)
    {
        SetPosition(acow::math::Vec2(x, y));
    }


    //------------------------------------------------------------------------//
    // Rotation                                                               //
    //------------------------------------------------------------------------//
public:
    // Getters.
    f32 GetRotation(Space space = Space::World) const;

    // Setters.
    inline void
    SetRotation(f32 degrees)
    {
        m_rotation = degrees;
    }


    //------------------------------------------------------------------------//
    // Scale                                                                  //
    //------------------------------------------------------------------------//
public:
    // Getters.
    acow::math::Vec2 GetScale(Space space = Space::World) const;

    // Setters.
    inline void
    SetScale(const acow::math::Vec2 &scale)
    {
        m_scale = scale;
    }

    inline void
    SetScale(f32 x, f32 y)
    {
        SetScale(acow::math::Vec2(x, y));
    }

    inline void
    SetScale(f32 value)
    {
        SetScale(acow::math::Vec2(value, value));
    }


    //------------------------------------------------------------------------//
    // Size                                                                   //
    //------------------------------------------------------------------------//
public:
    // Getters.
    inline acow::math::Vec2 GetSize() const { return m_size; }

    // Setters.
    inline void
    SetSize(const acow::math::Vec2 &size)
    {
        m_size = size;
    }

    inline void
    SetSize(f32 x, f32 y)
    {
        SetSize(acow::math::Vec2(x, y));
    }


    //------------------------------------------------------------------------//
    // Origin                                                                 //
    //   Notice that Origin is defined in relative means, so a (0.5, 0.5)     //
    //   is the center of the texture no matter what is its size.             //
    //   This is the same behaviour from Cocos2dx                             //
    //------------------------------------------------------------------------//
public:
    // Getters.
    inline acow::math::Vec2 GetOrigin() const { return m_origin; }

    // Setters
    inline void
    SetOrigin(const acow::math::Vec2 &origin)
    {
        m_origin = origin;
    }

    inline void
    SetOrigin(f32 x, f32 y)
    {
        SetOrigin(acow::math::Vec2(x, y));
    }


    //------------------------------------------------------------------------//
    // Bounding Rect                                                          //
    //------------------------------------------------------------------------//
public:
    acow::math::Rect GetBoundingRect() const;


    //------------------------------------------------------------------------//
    // Transformations                                                        //
    //------------------------------------------------------------------------//
public:
    inline void
    DoTranslate(const acow::math::Vec2 &amount)
    {
        m_position += amount;
    }

    inline void
    DoScale(const acow::math::Vec2 &amount)
    {
        m_scale += amount;
    }

    inline void
    DoRotate(f32 degrees)
    {
        m_rotation += degrees;
    }


    //------------------------------------------------------------------------//
    // Update / Render                                                        //
    //------------------------------------------------------------------------//
public:
    virtual void Update() { /* Empty... */ };
    virtual void Render() { /* Empty... */ };


    //------------------------------------------------------------------------//
    // iVars                                                                  //
    //------------------------------------------------------------------------//
private:
    // Transform.
    acow::math::Vec2  m_position;
    acow::math::Vec2  m_scale;
    f32               m_rotation;

    // Origin / Size.
    acow::math::Vec2 m_origin;
    acow::math::Vec2 m_size;

    // Control
    bool m_enabled;
    bool m_visible;

    // Hierarchy
    Entity *m_pParentRef; // Weak Reference...


    //--------------------------------------------------------------------------
    // This is just to ease the coding (and improve performance)!
    //   So the users instead of cache the objects by themselves or worse
    //   call the "Module"::Instance() every time he can just use those references.
protected:
    Graphics *m_pGraphicsRef;
    Game     *m_pGameRef;

}; // class Entity
}  // namespace Cooper
