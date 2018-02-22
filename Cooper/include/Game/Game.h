//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Game.h                                                        //
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
#include "acow/sdl_goodies.h"
// Cooper
#include "include/Game/Entity.h"
#include "include/Timer/Timer.h"

//COWTODO(n2omatt): We're not using the targetFPS hint today.

namespace Cooper {
//Forward declarations.
class Graphics;

class Game
{
    //------------------------------------------------------------------------//
    // Singleton                                                              //
    //------------------------------------------------------------------------//
public:
    ACOW_SINGLETON_OF(Game);


    //------------------------------------------------------------------------//
    // Lifecycle Functions                                                    //
    //------------------------------------------------------------------------//
public:
    static void Init(int targetFPS);
    static void Shutdown();

    static bool IsInitialized();

    static void Run();

private:
    static void InnerRun();


    //------------------------------------------------------------------------//
    // Getter Functions                                                       //
    //------------------------------------------------------------------------//
public:
    inline const Timer* const GetTimer() const { return &m_timer; }

    inline bool IsRunning() const { return m_running; }


    //------------------------------------------------------------------------//
    // Root Entity                                                            //
    //------------------------------------------------------------------------//
public:
    void SetRootEntity(Entity::UPtr pEntity) noexcept;

    inline Entity* GetRootEntity() const
    {
        return m_pBaseEntity.get();
    }


    //------------------------------------------------------------------------//
    // Update Functions.                                                      //
    //------------------------------------------------------------------------//
public:
    void PreUpdate ();
    void Update    ();
    void PostUpdate();


    //------------------------------------------------------------------------//
    // Render Functions                                                       //
    //------------------------------------------------------------------------//
public:
    void Render();


    //------------------------------------------------------------------------//
    // iVars.                                                                 //
    //------------------------------------------------------------------------//
public:
    bool  m_initialized;
    bool  m_running;
    int   m_fpsFrames;
    float m_fpsTime;

    Timer m_timer;

    Entity::UPtr m_pBaseEntity;

    //--------------------------------------------------------------------------
    // Weak References.
    Graphics *m_pGraphics; // Cached for performance.

}; // class Game
}  // namespace Cooper
