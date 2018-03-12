cmake_minimum_required(VERSION 3.5)

##------------------------------------------------------------------------------
## Compiler definitions
##   We need c++14 because we're using constexpr functions that
##   contains more than was permited by c++11.
##   Reference:
##     http://en.cppreference.com/w/cpp/language/constexpr
set(CMAKE_CXX_STANDARD          14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++14")
endif ()


##----------------------------------------------------------------------------##
## AmazingCow Libs                                                            ##
##----------------------------------------------------------------------------##
##
add_definitions(-DACOW_MATH_HAS_SDL_SUPPORT=1)

add_subdirectory(lib/CoreAssert       )
add_subdirectory(lib/CoreRandom       )
add_subdirectory(lib/CoreString       )
add_subdirectory(lib/CoreLog          )
add_subdirectory(lib/CoreFS           )
add_subdirectory(lib/libtermcolor     )
add_subdirectory(lib/acow_nt_posix    )
add_subdirectory(lib/acow_c_goodies   )
add_subdirectory(lib/acow_cpp_goodies )
add_subdirectory(lib/acow_sdl_goodies )
add_subdirectory(lib/acow_math_goodies)


##----------------------------------------------------------------------------##
## Cooper                                                                     ##
##----------------------------------------------------------------------------##
include_directories(
    ./Cooper
)

add_library(Cooper
    ## Game
    Cooper/src/Game/Entity.cpp
    Cooper/src/Game/Game.cpp
    Cooper/src/Game/RES.cpp

    ## Graphics
    Cooper/src/Graphics/Graphics.cpp
    Cooper/src/Graphics/TextEntity.cpp
    Cooper/src/Graphics/TextureAtlas.cpp
    Cooper/src/Graphics/TextureEntity.cpp

    ## Input
    Cooper/src/Input/Input.cpp

    ## Sound
    Cooper/src/Sound/Sound.cpp
    Cooper/src/Sound/private/AudioLib.cpp
    Cooper/src/Sound/private/emscripten/AudioValues.cpp
    Cooper/src/Sound/private/SDL/AudioValues.cpp
)

target_include_directories(Cooper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Cooper PUBLIC ./Cooper                   )
target_include_directories(Cooper PUBLIC ./lib/CoreRandom           )
target_include_directories(Cooper PUBLIC ./lib/acow_c_goodies       )
target_include_directories(Cooper PUBLIC ./lib/acow_cpp_goodies     )
target_include_directories(Cooper PUBLIC ./lib/acow_sdl_goodies     )
target_include_directories(Cooper PUBLIC ./lib/acow_math_goodies    )


##----------------------------------------------------------------------------##
## Link Libraries                                                             ##
##----------------------------------------------------------------------------##
target_link_libraries(Cooper LINK_PUBLIC CoreAssert       )
target_link_libraries(Cooper LINK_PUBLIC CoreRandom       )
target_link_libraries(Cooper LINK_PUBLIC CoreLog          )
target_link_libraries(Cooper LINK_PUBLIC CoreFS           )
target_link_libraries(Cooper LINK_PUBLIC libtermcolor     )
target_link_libraries(Cooper LINK_PUBLIC acow_nt_posix    )
target_link_libraries(Cooper LINK_PUBLIC acow_c_goodies   )
target_link_libraries(Cooper LINK_PUBLIC acow_cpp_goodies )
target_link_libraries(Cooper LINK_PUBLIC acow_sdl_goodies )
target_link_libraries(Cooper LINK_PUBLIC acow_math_goodies)
