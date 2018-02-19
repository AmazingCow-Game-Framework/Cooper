//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Sound.h                                                       //
//  Project   : Cooper                                                        //
//  Date      : Nov 17, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

// std
#include <string>
#include <vector>

namespace Cooper {
// Forward declarations.

// "class-like" namespace.
namespace Sound {

    //------------------------------------------------------------------------//
    // Lifecycle Functions                                                    //
    //------------------------------------------------------------------------//
    void Init();
    void Shutdown();

    bool Initialized();


    //------------------------------------------------------------------------//
    // Sound Functions                                                        //
    //------------------------------------------------------------------------//
    void PreloadSound(const std::vector<std::string> &path);
    void FreeSound   (const std::string &path);

    bool IsLoaded(const std::string &path);

    void PlaySound(const std::string &path);


} // namespace Sound
} // namespace Cooper
