//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Memory.h                                                      //
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
#include <memory>

namespace Cooper {

// COWTODO(n2omatt) Add support to C++17.

//------------------------------------------------------------------------------
// We're on C++14.
//
// Since C++14 already has a std::make_unique function we don't need to
// implement nothing at all, but doing so we'll break the code that is meant
// to be compiled from C++11 and C++14 compilers because it'll be using the
// Cooper::make_unique function (as defined bellow).
//
// To overcome this we need a way to export the std::make_unique under the
// Cooper namespace. So first we create an anonymous inner namespace, then
// make using of the std namespace (that's ok because it'll be enclosed at
// the end of the anonymous inner namespace), next we make a define with
// the same name of make_unique.
//
#if (defined(_WIN32) && (_MSVC_LANG >= 201402)) || (__cplusplus==201402L)
    namespace {
        using namespace std;
        #define make_unique make_unique
    }

//------------------------------------------------------------------------------
// We're on C++11.
//
// So let's define our version of make_unique. Notice that it's inside
// the namespace Cooper, so user will call Cooper::make_unique to use
// this function.
//
// The function implementation was taken from the great Herb:
//    https://herbsutter.com/gotw/_102
#elif (__cplusplus==201103L) // C++11
    template<typename T, typename ...Args>
    std::unique_ptr<T> make_unique( Args&& ...args )
    {
        return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
    }

//------------------------------------------------------------------------------
// Cooper is meant to be used with a modern compiler.
#else
    #error Cooper needs at least C++11 compiler conformance.
#endif

} // namespace Cooper
