//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Disallow.h                                                    //
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
// CTOR / DTOR                                                                //
//----------------------------------------------------------------------------//
#define COOPER_DISALLOW_CTOR(_type_)  _type_() = delete;
#define COOPER_DISALLOW_DTOR(_type_) ~_type_() = delete;

#define COOPER_DISALLOW_CTOR_DTOR(_type_) \
    COOPER_DISALLOW_CTOR(_type_)          \
    COOPER_DISALLOW_DTOR(_type_)


//----------------------------------------------------------------------------//
// Copy                                                                       //
//----------------------------------------------------------------------------//
#define COOPER_DISALLOW_COPY_CTOR(_type_) \
    _type_(const _type_ &) = delete;

#define COOPER_DISALLOW_COPY_ASSIGN(_type_) \
    _type_& operator=(const _type_&) = delete;

#define COOPER_DISALLOW_COPY_CTOR_AND_COPY_ASSIGN(_type_) \
    COOPER_DISALLOW_COPY_CTOR(_type_)                     \
    COOPER_DISALLOW_COPY_ASSIGN(_type_)


//----------------------------------------------------------------------------//
// Move                                                                       //
//----------------------------------------------------------------------------//
#define COOPER_DISALLOW_MOVE_CTOR(_type_) \
    _type_(const _type_ &&) = delete;

#define COOPER_DISALLOW_MOVE_ASSIGN(_type_) \
    _type_& operator=(const _type_&&) = delete;

#define COOPER_DISALLOW_MOVE_CTOR_AND_MOVE_ASSIGN(_type_) \
    COOPER_DISALLOW_MOVE_CTOR(_type_)                     \
    COOPER_DISALLOW_MOVE_ASSIGN(_type_)


//----------------------------------------------------------------------------//
// Everything                                                                 //
//----------------------------------------------------------------------------//
#define COOPER_DISALLOW_EVERYTHING(_type_)            \
    COOPER_DISALLOW_CTOR_DTOR(_type_)                 \
    COOPER_DISALLOW_COPY_CTOR_AND_COPY_ASSIGN(_type_) \
    COOPER_DISALLOW_MOVE_CTOR_AND_MOVE_ASSIGN(_type_)
