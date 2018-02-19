//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : RES.h                                                         //
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

//std
#include <string>
//SDL
#include <SDL.h>
#include <SDL_ttf.h>


namespace Cooper {
// Forward declarations.
class TextureAtlas;

//class-like namespace.
namespace RES {

    //------------------------------------------------------------------------//
    // Lifecycle Functions                                                    //
    //------------------------------------------------------------------------//
    void Init(const std::string &path = "./");
    void Shutdown();

    bool Initialized();


    //------------------------------------------------------------------------//
    // Path Functions                                                         //
    //------------------------------------------------------------------------//
    void SetBasePath(const std::string &path);
    const std::string& GetBasePath();

    std::string Fullpath(const std::string &path);


    //------------------------------------------------------------------------//
    // Atlas Functions                                                        //
    //------------------------------------------------------------------------//
    // Get - Will load the Atlas at first time.
    //       Afterwards it'll just return the reference, until the
    //       Atlas gets freed by FreeTexture().
    TextureAtlas* GetAtlas(const std::string &path);

    // Free - Free the Atlas.
    //        If the Atlas isn't loaded (or already has been freed)
    //        this function will be an error.
    void FreeAtlas(const std::string &path);


    //------------------------------------------------------------------------//
    // Texture Functions                                                      //
    //------------------------------------------------------------------------//
    // Get - Will load the Texture at first time.
    //       Afterwards it'll just return the reference, until the
    //       Texture gets freed by FreeTexture().
    SDL_Texture* GetTexture(const std::string &path);

    // Free - Free the Texture.
    //        If the Texture isn't loaded (or already has been freed)
    //        this function will be an error.
    void FreeTexture(const std::string &path);


    //------------------------------------------------------------------------//
    // Font Functions                                                         //
    //------------------------------------------------------------------------//
    // Get - Will load the Font at first time.
    //       Afterwards it'll just return the reference, until the
    //       Font gets freed by FreeFont().
    TTF_Font* GetFont(const std::string &path, int size);

    // Free - Free the Font.
    //        If the Font isn't loaded (or already has been freed)
    //        this function will be an error.
    void FreeFont(const std::string &path, int size);

} // namespace RES
} // namespace Cooper
