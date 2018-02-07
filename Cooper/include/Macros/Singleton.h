//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Singleton.h                                                   //
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

//----------------------------------------------------------------------------//
// Macros                                                                     //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// Makes the type a Singleton. So instead of type all of the code bellow for
// each type that we want to make a singleton we can just type, lets say:
//   COOPER_SINGLETON_OF(Enemy);
// Please notice that it expects that the user is reasonable with the type
// passed in, it only work for the classes that you own.
//
// Reference:
//   https://en.wikipedia.org/wiki/Singleton_pattern
#define COOPER_SINGLETON_OF(_type_)                   \
    static _type_* Instance() {                       \
        static _type_ s_instance;                     \
        return &s_instance;                           \
    };                                                \
                                                      \
    /* CTOR / DTOR */                                 \
    private:                                          \
         _type_();                                    \
        ~_type_();                                    \
                                                      \
    public:                                           \
        /* Copy CTOR / Copy Assign */                 \
        _type_(const _type_&) = delete;               \
        _type_& operator=(const _type_&) = delete;    \
                                                      \
        /* Move CTOR / Move Assign */                 \
        _type_(_type_&&) = delete;                    \
        _type_& operator=(_type_&&) = delete;         \
                                                      \
    /* Let everything bellow be private by default */ \
    private:

