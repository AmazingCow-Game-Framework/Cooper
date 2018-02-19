//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Graphics.cpp                                                  //
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
#include "include/Graphics/Graphics.h"
// Cooper
#include "include/Log/Log.h"

// Usings
using namespace Cooper;


//----------------------------------------------------------------------------//
// Singleton                                                                  //
//----------------------------------------------------------------------------//
Graphics::Graphics() :
    // Members
    m_initialized(false),
    m_width (0),
    m_height(0),
    // m_caption - Default init...
    m_pWindow  (nullptr),
    m_pRenderer(nullptr)
{
    //Empty...
}

Graphics::~Graphics()
{
    //Empty...
}


//----------------------------------------------------------------------------//
// Lifecycle Functions.                                                       //
//----------------------------------------------------------------------------//
void Graphics::Init(int width, int height, const std::string &caption)
{
    COOPER_ASSERT(
        !Instance()->Initialized(),
        "Graphics is already initialized."
    );

    //--------------------------------------------------------------------------
    // Initialize Subsystems.
    //   SDL_Video
    COOPER_VERIFY(
        SDL_Init(SDL_INIT_VIDEO) == 0,
        "SDL_Init(SDL_INIT_VIDEO) failed\n:SDL_Error: %s",
        SDL_GetError()
    );
    //  SDL_image
    COOPER_VERIFY(
        IMG_Init(IMG_INIT_PNG) != 0, //Init returns non zero on success...
        "IMG_Init Error: %s",
        IMG_GetError()
    );
    //  SDL_TTF
    COOPER_VERIFY(
        TTF_Init() == 0, //Init returns zero on success...
        "TTF_Init Error: %s",
        TTF_GetError()
    );

    //--------------------------------------------------------------------------
    // Create the window.
    Instance()->m_pWindow = SDL_CreateWindow(
        caption.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    COOPER_VERIFY(
        Instance()->m_pWindow,
        "Failed to create window\nSDL_Error: %s",
        SDL_GetError()
    );

    //--------------------------------------------------------------------------
    // Create Renderer.
    Instance()->m_pRenderer = SDL_CreateRenderer(
        Instance()->m_pWindow,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    COOPER_VERIFY(
        Instance()->m_pRenderer,
        "Failed to create renderer\nSDL_Error: %s",
        SDL_GetError()
    );

    //--------------------------------------------------------------------------
    // Other stuff.
    Instance()->m_initialized = true;

    Instance()->m_width   = width;
    Instance()->m_height  = height;
    Instance()->m_caption = caption;

    Instance()->SetClearColor(Math::ColorBlack);
}

void Graphics::Shutdown()
{
    COOPER_ASSERT(Instance()->Initialized(), "Graphics isn't initialized.");

    //--------------------------------------------------------------------------
    // Renderer.
    SDL_DestroyRenderer(Instance()->m_pRenderer);
    Instance()->m_pRenderer = nullptr;

    //--------------------------------------------------------------------------
    // Window.
    SDL_DestroyWindow(Instance()->m_pWindow);
    Instance()->m_pWindow = nullptr;

    //--------------------------------------------------------------------------
    // Unload the subsystems.
    TTF_Quit();
    IMG_Quit();
    SDL_QuitSubSystem(SDL_INIT_VIDEO);

    //--------------------------------------------------------------------------
    // Other.
    Instance()->m_initialized = false;
}

bool Graphics::Initialized()
{
    return Instance()->m_initialized;
}


//----------------------------------------------------------------------------//
// Screen Functions                                                           //
//----------------------------------------------------------------------------//
void Graphics::SetScreenCaption(const std::string &caption)
{
    COOPER_ASSERT(m_initialized, "Graphics isn't initialized.");

    m_caption = caption;
    SDL_SetWindowTitle(
        m_pWindow,
        m_caption.c_str()
    );
}


//----------------------------------------------------------------------------//
// Texture Creation Functions.                                                //
//----------------------------------------------------------------------------//
SDL_Texture* Graphics::LoadTexture(const std::string &path)
{
    COOPER_ASSERT(m_initialized, "Graphics isn't initialized");

    //--------------------------------------------------------------------------
    // To load a texture in SDL we must:
    //   1 - Load the surface from file.
    //   2 - Create a texture from that surface.
    //   3 - Free the surface (!) - If we fail to free it, this will be a
    //       memory leak in our game.
    //   4 - Return it ;D

    //--------------------------------------------------------------------------
    // 1 - Loads the surface.
    auto p_surface = IMG_Load(path.c_str());
    COOPER_VERIFY(
        p_surface, //Surface must be not null...
        "Failed to load image at:(%s)\nIMG_Error: %s",
        path.c_str(),
        IMG_GetError()
    );

    //--------------------------------------------------------------------------
    // 2 - Create the texture from surface.
    auto p_texture = SDL_CreateTextureFromSurface(m_pRenderer, p_surface);
    COOPER_VERIFY(
        p_surface, //Texture must be not null...
        "Failed to create texture from surface: (%s)\nSDL_Error: %s",
        path.c_str(),
        SDL_GetError()
    );

    //--------------------------------------------------------------------------
    // 3 - Free the surface.
    SDL_FreeSurface(p_surface);

    //--------------------------------------------------------------------------
    // 4 - Return it ;D
    return p_texture;
}


//COWTODO(n2omatt): Today our text rendering functions are too inflexible
//                  try to implement more rendering options.
SDL_Texture* Graphics::CreateFontTexture(
    TTF_Font          *pFont,
    const std::string &contents,
    SDL_Color          color)
{
    //--------------------------------------------------------------------------
    // To render a text in SDL we must:
    //   1 - Call the appropriated text render function.
    //       It will return a surface.
    //   2 - Create a texture from that surface.
    //   3 - Free the surface (!) - If we fail to free it, this will be a
    //       memory leak in our game.
    //   4 - Return it ;D

    //--------------------------------------------------------------------------
    // 1 - Render the text to surface.
    auto p_surface = TTF_RenderText_Solid(
        pFont,
        contents.c_str(),
        Math::ColorWhite
    );

    COOPER_VERIFY(
        p_surface, //Surface must be not null...
        "Failed to render text:(%s)\nTTF_Error: %s",
        contents.c_str(),
        TTF_GetError()
    );


    //--------------------------------------------------------------------------
    // 2 - Create the texture from surface.
    auto p_texture = SDL_CreateTextureFromSurface(m_pRenderer, p_surface);

    COOPER_VERIFY(
        p_surface, //Texture must be not null...
        "Failed to create texture from text surface: (%s)\nSDL_Error: %s",
        contents.c_str(),
        SDL_GetError()
    );

    // Set its color.
    SDL_SetTextureColorMod(p_texture, color.r, color.g, color.b);

    //--------------------------------------------------------------------------
    // 3 - Free the surface.
    SDL_FreeSurface(p_surface);

    //--------------------------------------------------------------------------
    // 4 - Return it ;D
    return p_texture;
}


std::shared_ptr<SDL_Texture> Graphics::CreateFontTextureManaged(
    TTF_Font          *pFont,
    const std::string &contents,
    SDL_Color          color)
{
    //--------------------------------------------------------------------------
    // Forward the creation - They are exactly equal, the only difference
    // it that this version will handle the deletion of the SDL_Texture.
    // We don't need check the result since CreateFontTexture will
    // ensure that the operation is succeed or an abort.
    auto p_texture = CreateFontTexture(
        pFont,
        contents,
        color
    );

    //--------------------------------------------------------------------------
    // The "trick" to make the SDL_Texture managed is to add a custom deleter
    // on the std::shared_ptr. So when the shared_ptr's destructor is called
    // it will call our custom deleter as well.
    return std::shared_ptr<SDL_Texture>(p_texture, [=](SDL_Texture *p){
        //Cooper::Log::D("Destroyed managed SDL_Texture.");
        SDL_DestroyTexture(p);
    });
}


//----------------------------------------------------------------------------//
// Rendering Functions.                                                       //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// Texture.
void Graphics::RenderTexture(
    SDL_Texture         *pTexture,
    const SDL_Rect      &srcRect,
    const SDL_Rect      &dstRect,
    float                angleDegrees,
    const SDL_Point     &origin,
    SDL_RendererFlip    flip,   /* = SDL_FLIP_NONE */
    float               opacity /* = 1.0f          */)
{
    COOPER_ASSERT(m_initialized, "Graphics isn't initialized.");

    //--------------------------------------------------------------------------
    //  Prepare the Texture to take alpha info.
    SDL_SetTextureAlphaMod(
        pTexture,
        Uint8(Math::Clamp<float>(opacity * 255.0f, 0, 255))
    );

    //--------------------------------------------------------------------------
    //  Render it ;D
    SDL_RenderCopyEx(
        m_pRenderer,
        pTexture,
        &srcRect,
        &dstRect,
        angleDegrees,
        NULL,
        flip
    );
}


//------------------------------------------------------------------------------
// Rectangle.
void Graphics::RenderRect(
    const SDL_Rect  &rect,
    const SDL_Color &c /* = Math::ColorWhite */)
{
    COOPER_ASSERT(m_initialized, "Graphics isn't initialized.");

    //--------------------------------------------------------------------------
    // Push the new color - So the rendering will be on that.
    SDL_SetRenderDrawColor(m_pRenderer, c.r, c.g, c.b, 0xFF);

    //--------------------------------------------------------------------------
    // Render.
    SDL_RenderDrawRect(m_pRenderer, &rect);

    //--------------------------------------------------------------------------
    // Make the renderer use our clear color.
    SDL_SetRenderDrawColor(
        m_pRenderer,
        m_clearColor.r,
        m_clearColor.g,
        m_clearColor.b,
        0xFF
    );
}

//------------------------------------------------------------------------------
// Circle.
void Graphics::RenderCircle(
    const Vec2      &center,
    float            radius,
    const SDL_Color &color /* = Math::ColorWhite */,
    int              sides /* = -1               */)
{
    COOPER_ASSERT(m_initialized, "Graphics isn't initialized.");

    //--------------------------------------------------------------------------
    if(sides < 0)
        sides = int((Math::k2PI * radius) / 0.5f);

    //--------------------------------------------------------------------------
    auto delta_angle = Math::k2PI / sides;
    auto angle       = delta_angle;
    auto end_point   = Vec2(radius + center.x, 0.0f + center.y);

    //--------------------------------------------------------------------------
    for(int i = 0; i < sides; i++)
    {
        auto start_point = end_point;

        end_point.x = (cosf(angle) * radius);
        end_point.y = (sinf(angle) * radius);

        end_point = end_point + center;

        angle += delta_angle;

        RenderLine(start_point, end_point, color);
    }
}

//------------------------------------------------------------------------------
// Line.
void Graphics::RenderLine(const Vec2 &start, const Vec2 &end, const SDL_Color& c)
{
    COOPER_ASSERT(m_initialized, "Graphics isn't initialized.");

    //--------------------------------------------------------------------------
    // Push the new color - So the rendering will be on that.
    SDL_SetRenderDrawColor(m_pRenderer, c.r, c.g, c.b, 0xFF);

    //--------------------------------------------------------------------------
    // RenderTexture a line
    SDL_RenderDrawLine(
        m_pRenderer,
        int(start.x),
        int(start.y),
        int(  end.x),
        int(  end.y)
    );

    //--------------------------------------------------------------------------
    // Make the renderer use our clear color.
    SDL_SetRenderDrawColor(
        m_pRenderer,
        m_clearColor.r,
        m_clearColor.g,
        m_clearColor.b,
        0xFF
    );
}
