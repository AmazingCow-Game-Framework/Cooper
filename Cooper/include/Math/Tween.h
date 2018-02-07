//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Tween.h                                                       //
//  Project   : Cooper                                                        //
//  Date      : Nov 10, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//---------------------------------------------------------------------------~//

#pragma once
// std
#include <functional> //std::function
// Cooper
#include "include/Math/Operations.h"

namespace Cooper {

template <typename T>
class Tween
{
    //------------------------------------------------------------------------//
    // Typedefs                                                               //
    //------------------------------------------------------------------------//
public:
    typedef std::function<void (const T &)> OnChangeCallback;
    typedef std::function<void ()>          OnStartCallback;
    typedef std::function<void ()>          OnStopCallback;
    typedef std::function<void ()>          OnPauseCallback;
    typedef std::function<void ()>          OnResumeCallback;
    typedef std::function<void ()>          OnFinishCallback;


    //------------------------------------------------------------------------//
    // Setup Value Functions                                                  //
    //------------------------------------------------------------------------//
public:
    Tween<T>& From(const T &value) { m_startValue = value; return *this; }
    Tween<T>& To  (const T &value) { m_endValue   = value; return *this; }
    Tween<T>& In  (float    value) { m_duration   = value; return *this; }


    //------------------------------------------------------------------------//
    // Setup Callbacks Functions                                              //
    //------------------------------------------------------------------------//
    Tween<T>& OnChange(const OnChangeCallback &c) { m_onChange = c; return *this; }
    Tween<T>& OnStart (const OnStartCallback  &c) { m_onStart  = c; return *this; }
    Tween<T>& OnStop  (const OnStopCallback   &c) { m_onStop   = c; return *this; }
    Tween<T>& OnPause (const OnPauseCallback  &c) { m_onPause  = c; return *this; }
    Tween<T>& OnResume(const OnResumeCallback &c) { m_onResume = c; return *this; }
    Tween<T>& OnFinish(const OnFinishCallback &c) { m_onFinish = c; return *this; }


    //------------------------------------------------------------------------//
    // Action Functions                                                       //
    //------------------------------------------------------------------------//
public:
    Tween<T>& Start()
    {
        //----------------------------------------------------------------------
        // Reset the control values.
        m_started  = true;
        m_paused   = false;
        m_finished = false;

        //----------------------------------------------------------------------
        // Reset timing values.
        m_currentTime = 0.0f;

        //----------------------------------------------------------------------
        // Reset tween value.
        value = m_startValue;

        //----------------------------------------------------------------------
        // Fire the callback.
        if(m_onStart) m_onStart();

        return *this;
    }

    Tween<T>& Stop()
    {
        //----------------------------------------------------------------------
        // Reset the control values.
        m_started  = false;
        m_paused   = false;
        m_finished = false;

        //----------------------------------------------------------------------
        // Reset timing values.
        m_currentTime = 0.0f;

        //----------------------------------------------------------------------
        // Fire the callback.
        if(m_onFinish) m_onFinish();

        return *this;
    }

    Tween<T>& Pause()
    {
        if(!m_started || m_finished || m_paused)
            return *this;

        //----------------------------------------------------------------------
        // Reset the control values.
        m_paused = true;

        //----------------------------------------------------------------------
        // Fire the callback.
        if(m_onPause) m_onPause();

        return *this;
    }

    Tween<T>& Resume()
    {
        if(!m_started || m_finished || !m_paused)
            return *this;

        //----------------------------------------------------------------------
        // Reset the control values.
        m_paused = false;

        //----------------------------------------------------------------------
        // Fire the callback.
        if(m_onResume) m_onResume();

        return *this;
    }


    //------------------------------------------------------------------------//
    // Update                                                                 //
    //------------------------------------------------------------------------//
public:
    void Update(float dt)
    {
        if(!m_started || m_finished || m_paused)
            return;

        //----------------------------------------------------------------------
        // Update Timing.
        m_currentTime += dt;

        //----------------------------------------------------------------------
        // Update Value.
        value = Math::Lerp(
            m_startValue,
            m_endValue,
            m_currentTime / m_duration
        );

        if(m_onChange) m_onChange(value);

        //----------------------------------------------------------------------
        // Check completion.
        m_finished = (m_currentTime >= m_duration);

        if(m_finished && m_onFinish) m_onFinish();
    }


    //------------------------------------------------------------------------//
    // iVars                                                                  //
    //------------------------------------------------------------------------//
public:
    T value;

private:
    // Timing.
    float m_duration;
    float m_currentTime;

    // Values.
    T m_startValue;
    T m_endValue;

    // Control.
    bool m_started;
    bool m_paused;
    bool m_finished;

    // Callbacks.
    OnStartCallback  m_onStart;
    OnStopCallback   m_onStop;
    OnPauseCallback  m_onPause;
    OnResumeCallback m_onResume;

    OnFinishCallback m_onFinish;
    OnChangeCallback m_onChange;

}; // class Tween<T>
}  // namespace Cooper
