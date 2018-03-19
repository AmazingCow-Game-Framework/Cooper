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
    m_pWindow  (nullptr, nullptr),
    m_pRenderer(nullptr, nullptr)
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
void
Graphics::Init(const Options &options) noexcept
{
    //--------------------------------------------------------------------------
    // Init Subsystems.
    acow::sdl     ::Init(SDL_INIT_VIDEO);
    acow::sdl::img::Init(IMG_INIT_PNG);
    acow::sdl::ttf::Init();

    // COWTODO(n2omatt): Validate options..

    //--------------------------------------------------------------------------
    // Create the window.
    Instance()->m_pWindow = acow::sdl::Window::CreateUnique(
        options.win_Caption,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        options.win_Width,
        options.win_Height,
        options.win_SDLFlags
    );

    SDL_SetWindowMinimumSize(
        Instance()->m_pWindow.get(),
        options.win_MinWidth,
        options.win_MinHeight
    );

    SDL_SetWindowMaximumSize(
        Instance()->m_pWindow.get(),
        options.win_MaxWidth,
        options.win_MaxHeight
    );

    //--------------------------------------------------------------------------
    // Create Renderer.
    Instance()->m_pRenderer = acow::sdl::Renderer::CreateUnique(
        Instance()->m_pWindow.get(),
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );


    //--------------------------------------------------------------------------
    // Other stuff.
    Instance()->m_initialized = true;

    Instance()->m_width   = options.win_Width;
    Instance()->m_height  = options.win_Height;
    Instance()->m_caption = options.win_Caption;

    Instance()->SetClearColor(acow::sdl::Color::White());


//    SDL_RenderSetLogicalSize(
//            Instance()->m_pRenderer.get(),
//            options.win_Width  * 0.7,
//            options.win_Height * 0.7
//    );

//    SDL_RenderSetLogicalSize
//    SDL_RenderSetIntegerScale
//    SDL_RenderSetScale
}


void
Graphics::Init(u16 width, u16 height, const std::string &caption)
{
    COREASSERT_ASSERT(
        !Instance()->IsInitialized(),
        "Graphics is already initialized."
    );

    acow::sdl     ::Init(SDL_INIT_VIDEO);
    acow::sdl::img::Init(IMG_INIT_PNG);
    acow::sdl::ttf::Init();

    //--------------------------------------------------------------------------
    // Create the window.
    Instance()->m_pWindow = acow::sdl::Window::CreateUnique(
        caption,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );

    //--------------------------------------------------------------------------
    // Create Renderer.
    Instance()->m_pRenderer = acow::sdl::Renderer::CreateUnique(
        Instance()->m_pWindow.get(),
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );


    //--------------------------------------------------------------------------
    // Other stuff.
    Instance()->m_initialized = true;

    Instance()->m_width   = width;
    Instance()->m_height  = height;
    Instance()->m_caption = caption;

    Instance()->SetClearColor(acow::sdl::Color::Black());
}

void
Graphics::Shutdown()
{
    COREASSERT_ASSERT(Instance()->IsInitialized(), "Graphics isn't initialized.");

    //--------------------------------------------------------------------------
    // Unload the subsystems.
    TTF_Quit();
    IMG_Quit();
    SDL_QuitSubSystem(SDL_INIT_VIDEO);

    //--------------------------------------------------------------------------
    // Other.
    Instance()->m_initialized = false;
}

bool
Graphics::IsInitialized() noexcept
{
    return Instance()->m_initialized;
}


//----------------------------------------------------------------------------//
// Screen Functions                                                           //
//----------------------------------------------------------------------------//
void
Graphics::SetScreenCaption(const std::string &caption) noexcept
{
    COREASSERT_ASSERT(m_initialized, "Graphics isn't initialized.");

    m_caption = caption;
    SDL_SetWindowTitle(
        m_pWindow.get(),
        m_caption.c_str()
    );
}


//----------------------------------------------------------------------------//
// Texture Creation Functions.                                                //
//----------------------------------------------------------------------------//
SDL_Texture*
Graphics::LoadTexture(const std::string &path)
{
    COREASSERT_ASSERT(m_initialized, "Graphics isn't initialized");

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
    COREASSERT_VERIFY(
        p_surface, //Surface must be not null...
        "Failed to load image at:(%s)\nIMG_Error: %s",
        path.c_str(),
        IMG_GetError()
    );

    //--------------------------------------------------------------------------
    // 2 - Create the texture from surface.
    auto p_texture = SDL_CreateTextureFromSurface(m_pRenderer.get(), p_surface);
    COREASSERT_VERIFY(
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
SDL_Texture*
Graphics::CreateFontTexture(
    TTF_Font               *pFont,
    const std::string      &contents,
    const acow::sdl::Color &color)
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
        SDL_Color(acow::sdl::Color::White())
    );

    COREASSERT_VERIFY(
        p_surface, //Surface must be not null...
        "Failed to render text:(%s)\nTTF_Error: %s",
        contents.c_str(),
        TTF_GetError()
    );


    //--------------------------------------------------------------------------
    // 2 - Create the texture from surface.
    auto p_texture = SDL_CreateTextureFromSurface(m_pRenderer.get(), p_surface);

    COREASSERT_VERIFY(
        p_surface, //Texture must be not null...
        "Failed to create texture from text surface: (%s)\nSDL_Error: %s",
        contents.c_str(),
        SDL_GetError()
    );

    // Set its color.
    SDL_SetTextureColorMod(
        p_texture,
        color.r * 0xFF,
        color.g * 0xFF,
        color.b * 0xFF
    );

    //--------------------------------------------------------------------------
    // 3 - Free the surface.
    SDL_FreeSurface(p_surface);

    //--------------------------------------------------------------------------
    // 4 - Return it ;D
    return p_texture;
}


std::shared_ptr<SDL_Texture>
Graphics::CreateFontTextureManaged(
    TTF_Font               *pFont,
    const std::string      &contents,
    const acow::sdl::Color &color)
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
    SDL_Texture            *pTexture,
    const acow::math::Rect  &srcRect,
    const acow::math::Rect  &dstRect,
    float                    angleDegrees, // = 0
    const acow::math::Vec2  &origin,       // = acow::math::Vec2::Half()
    SDL_RendererFlip         flip,         // = SDL_FLIP_NONE
    float                    opacity       // = 1.0f
) noexcept
{
    COREASSERT_ASSERT(m_initialized, "Graphics isn't initialized.");

    //--------------------------------------------------------------------------
    //  Prepare the Texture to take alpha info.
    SDL_SetTextureAlphaMod(
        pTexture,
        Uint8(acow::math::Clamp<float>(opacity * 255.0f, 0, 255))
    );

    //--------------------------------------------------------------------------
    //  Render it ;D
    auto src_rect = SDL_Rect {
        // COWTODO(n2omatt): Coversion operator.
        int(srcRect.x),
        int(srcRect.y),
        int(srcRect.GetWidth()),
        int(srcRect.GetHeight())
    };
    auto dst_rect = SDL_Rect {
        // COWTODO(n2omatt): Coversion operator.
        int(dstRect.x),
        int(dstRect.y),
        int(dstRect.GetWidth()),
        int(dstRect.GetHeight())
    };

    SDL_RenderCopyEx(
        m_pRenderer.get(),
        pTexture,
        &src_rect,
        &dst_rect,
        angleDegrees,
        nullptr,
        flip
    );

    if(m_debugRenderTextureRects)
        RenderRect(dstRect, acow::sdl::Color::Magenta());
}


//------------------------------------------------------------------------------
// Rectangle.
void Graphics::RenderRect(
    const acow::math::Rect  &rect,
    const acow::sdl::Color  &color /* = Color::White*/)
{
    COREASSERT_ASSERT(m_initialized, "Graphics isn't initialized.");

    //--------------------------------------------------------------------------
    // Push the new color - So the rendering will be on that.
    SDL_SetRenderDrawColor(
        m_pRenderer.get(),
        u8(color.r * 0xFF),
        u8(color.g * 0xFF),
        u8(color.b * 0xFF),
        0xFF
    );

    //--------------------------------------------------------------------------
    // Render.
    auto sdl_rect = SDL_Rect {
        // COWTODO(n2omatt): Conversion operator.
        i32(rect.x),
        i32(rect.y),
        i32(rect.GetWidth ()),
        i32(rect.GetHeight())
    };

    SDL_RenderDrawRect(
        m_pRenderer.get(),
        &sdl_rect
    );

    //--------------------------------------------------------------------------
    // Make the renderer use our clear color.
    SDL_SetRenderDrawColor(
        m_pRenderer.get(),
        u8(m_clearColor.r * 0xFF),
        u8(m_clearColor.g * 0xFF),
        u8(m_clearColor.b * 0xFF),
        0xFF
    );
}

//------------------------------------------------------------------------------
// Circle.
void Graphics::RenderCircle(
    const acow::math::Vec2   &center,
    f32                      radius,
    const acow::sdl::Color  &color, /* = Color::White */
    i32                      sides /* = -1           */)
{
    COREASSERT_ASSERT(m_initialized, "Graphics isn't initialized.");

    //--------------------------------------------------------------------------
    if(sides < 0)
        sides = int((acow::math::k2PI * radius) / 0.5f);

    //--------------------------------------------------------------------------
    auto delta_angle = acow::math::k2PI / sides;
    auto angle       = delta_angle;
    auto end_point   = acow::math::Vec2(radius + center.x, 0.0f + center.y);

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
void Graphics::RenderLine(
    const acow::math::Vec2 &start,
    const acow::math::Vec2 &end,
    const acow::sdl::Color &color)
{
    COREASSERT_ASSERT(m_initialized, "Graphics isn't initialized.");

    //--------------------------------------------------------------------------
    // Push the new color - So the rendering will be on that.
    SDL_SetRenderDrawColor(
        m_pRenderer.get(),
        u8(color.r * 0xFF),
        u8(color.g * 0xFF),
        u8(color.b * 0xFF),
        0xFF);

    //--------------------------------------------------------------------------
    // RenderTexture a line
    SDL_RenderDrawLine(
        m_pRenderer.get(),
        i32(start.x),
        i32(start.y),
        i32(  end.x),
        i32(  end.y)
    );

    //--------------------------------------------------------------------------
    // Make the renderer use our clear color.
    SDL_SetRenderDrawColor(
        m_pRenderer.get(),
        u8(m_clearColor.r * 0xFF),
        u8(m_clearColor.g * 0xFF),
        u8(m_clearColor.b * 0xFF),
        0xFF
    );
}
