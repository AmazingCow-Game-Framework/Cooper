//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : TextureAtlas.h                                                //
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

// std
#include <map>
#include <string>
// Cooper
#include "include/Graphics/TextureEntity.h"
#include "include/Macros/Macros.h"


namespace Cooper {

class TextureAtlas
{
    //------------------------------------------------------------------------//
    // Enums / Constants / Typedefs                                           //
    //------------------------------------------------------------------------//
public:
    COOPER_SMART_PTRS_OF(TextureAtlas);


    //------------------------------------------------------------------------//
    // CTOR / DTOR                                                            //
    //------------------------------------------------------------------------//
public:
     explicit TextureAtlas(const std::string &path);

    ~TextureAtlas() = default;


    //------------------------------------------------------------------------//
    //  Getters                                                               //
    //------------------------------------------------------------------------//
public:
    //--------------------------------------------------------------------------
    // This will return a brand new TextureEntity with the Render Rectangle
    // set and the Position to (0,0).
    //
    // If we want just to get the Render Rectangles to make an animation
    // of the texture we can call the Rectangle() function instead.
    TextureEntity::UPtr Texture(const std::string &key);


    //--------------------------------------------------------------------------
    // Gets the rectangle described by the key.
    // This is useful to make an texture animation.
    const SDL_Rect& Rectangle(const std::string &key);


    //------------------------------------------------------------------------//
    // Loading Functions                                                      //
    //------------------------------------------------------------------------//
private:
    void LoadFromFile();


    //------------------------------------------------------------------------//
    // iVars                                                                  //
    //------------------------------------------------------------------------//
private:
    std::string                     m_atlasPath;
    std::string                     m_texturesPath;
    std::map<std::string, SDL_Rect> m_rectsMap;

}; // class TextureAtlas
}  // namespace Cooper
