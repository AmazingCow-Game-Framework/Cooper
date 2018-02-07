//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : TextureAtlas.cpp                                              //
//  Project   : Cooper                                                        //
//  Date      : Nov 17, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

// Header
#include "include/Graphics/TextureAtlas.h"
// std
#include <fstream>
#include <sstream>
#include <vector>
// Cooper
#include "include/Game/RES.h"
#include "include/Macros/Macros.h"
#include "include/Memory/Memory.h"

//Usings
using namespace Cooper;


//----------------------------------------------------------------------------//
// CTOR / DTOR                                                                //
//----------------------------------------------------------------------------//
TextureAtlas::TextureAtlas(const std::string &path) :
    m_atlasPath(path)
{
    LoadFromFile();
}


//----------------------------------------------------------------------------//
//  Getters                                                                   //
//----------------------------------------------------------------------------//
TextureEntity::UPtr TextureAtlas::Texture(const std::string &key)
{
    return Cooper::make_unique<TextureEntity>(
        m_texturesPath,
        Rectangle(key)
    );
}

const SDL_Rect& TextureAtlas::Rectangle(const std::string &key)
{
    auto it = m_rectsMap.find(key);

    COOPER_ASSERT(
        it != std::end(m_rectsMap),
        "Rectangle isn't on atlas - Rectangle: %s - Atlas: %s",
        key.c_str(),
        m_atlasPath.c_str()
    );

    return it->second;
}


//----------------------------------------------------------------------------//
// Loading Functions                                                          //
//----------------------------------------------------------------------------//
void TextureAtlas::LoadFromFile()
{
    //COWNOTE(n2omatt): Today our atlas format is very ~idiotic~ simple....
    //
    // Line 1   : Image file path (relative to RES::GetBasePath())
    // Line 2-n : Name , X, Y, W, H
    //
    // That's it ;D
    //

    //COWTODO(n2omatt): This is exactly like the CoreFile...
    //  Should we use it instead to get first class file handling?
    std::vector<std::string> lines;

    std::fstream file_stream;
    file_stream.open(m_atlasPath.c_str(), std::ios::in);

    COOPER_VERIFY(
        file_stream.is_open(),
        "Can't open TextureAtlas: %s",
        m_atlasPath.c_str()
    );

    while(!file_stream.eof())
    {
        std::string line;
        std::getline(file_stream, line);

        if(line.empty())
            continue;

        lines.push_back(line);
    }

    COOPER_ASSERT(
        !lines.empty(),
        "Empty TextureAtlas: %s",
        m_atlasPath.c_str()
    );

    m_texturesPath = RES::Fullpath(lines[0]);
    for(auto it = ++std::begin(lines); it != std::end(lines); ++it)
    {
        std::stringstream ss(*it);
        if(ss.str().empty())
            continue;

        std::string name;
        SDL_Rect    rect;
        ss >> name >> rect.x >> rect.y >> rect.w >> rect.h;

        m_rectsMap[name] = rect;
    }
}
