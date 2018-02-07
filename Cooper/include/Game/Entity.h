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

// Cooper
#include "include/Macros/Macros.h"
#include "include/Math/Math.h"

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
    COOPER_SMART_PTRS_OF(Entity);

    enum class Space { Local, World };


    //------------------------------------------------------------------------//
    // CTOR / DTOR                                                            //
    //------------------------------------------------------------------------//
public:
    explicit Entity(const Vec2 &pos = Vec2::Zero());
    virtual ~Entity();


    //------------------------------------------------------------------------//
    // Parent                                                                 //
    //------------------------------------------------------------------------//
public:
    // Getters.
    inline const Entity* Parent() const { return m_pParent; }
    // Setters.
    void Parent(Entity *pParent);

    // Helpers.
private:
    void RemoveParent();


    //------------------------------------------------------------------------//
    // Enabled / Visible                                                      //
    //------------------------------------------------------------------------//
public:
    // Getters.
    inline bool Enabled() const { return m_enabled; }
    inline bool Visible() const { return m_visible; }

    // Setters.
    inline void Enabled(bool enable ) { m_enabled = enable;  }
    inline void Visible(bool visible) { m_visible = visible; }


    //------------------------------------------------------------------------//
    // Position                                                               //
    //------------------------------------------------------------------------//
public:
    // Getters.
    Vec2 Position(Space space = Space::World) const;

    // Setters.
    inline void Position(const Vec2 &pos)  { m_position = pos;     }
    inline void Position(float x, float y) { Position(Vec2(x, y)); }


    //------------------------------------------------------------------------//
    // Rotation                                                               //
    //------------------------------------------------------------------------//
public:
    // Getters.
    float Rotation(Space space = Space::World) const;

    // Setters.
    inline void Rotation(float degrees) { m_rotation = degrees; }


    //------------------------------------------------------------------------//
    // Scale                                                                  //
    //------------------------------------------------------------------------//
public:
    // Getters.
    Vec2 Scale(Space space = Space::World) const;

    // Setters.
    inline void Scale(const Vec2 &scale)  { m_scale = scale;           }
    inline void Scale(float x, float y )  { Scale(Vec2(x,         y)); }
    inline void Scale(float value      )  { Scale(Vec2(value, value)); }


    //------------------------------------------------------------------------//
    // Size                                                                   //
    //------------------------------------------------------------------------//
public:
    // Getters.
    inline Vec2 Size() const { return m_size; }

    // Setters.
    inline void Size(const Vec2 &size) { m_size = size;    }
    inline void Size(float x, float y) { Size(Vec2(x, y)); }


    //------------------------------------------------------------------------//
    // Origin                                                                 //
    //   Notice that Origin is defined in relative means, so a (0.5, 0.5)     //
    //   is the center of the texture no matter what is its size.             //
    //   This is the same behaviour from Cocos2dx                             //
    //------------------------------------------------------------------------//
public:
    // Getters.
    inline Vec2 Origin() const { return m_origin; }

    // Setters
    inline void Origin(const Vec2 &origin) { m_origin = origin; }
    inline void Origin(float x, float y)   { Origin(Vec2(x, y)); }


    //------------------------------------------------------------------------//
    // Bounding Rect                                                          //
    //------------------------------------------------------------------------//
public:
    SDL_Rect BoundingRect() const;


    //------------------------------------------------------------------------//
    // Transformations                                                        //
    //------------------------------------------------------------------------//
public:
    inline void DoTranslate(const Vec2 &amount) { m_position += amount;  }
    inline void DoScale    (const Vec2 &amount) { m_scale    += amount;  }
    inline void DoRotate   (float      degrees) { m_rotation += degrees; }


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
    Vec2  m_position;
    Vec2  m_scale;
    float m_rotation;

    // Origin / Size.
    Vec2 m_origin;
    Vec2 m_size;

    // Control
    bool m_enabled;
    bool m_visible;

    // Hierarchy
    Entity *m_pParent; //Weak Reference...


    //--------------------------------------------------------------------------
    // This is just to ease the coding (and improve performance)!
    //   So the users instead of cache the objects by themselves or worse
    //   call the "Module"::Instance() every time he can just use those references.
protected:
    Graphics *m_pGraphicsRef;
    Game     *m_pGameRef;

}; //class Entity
} //namespace Cooper
