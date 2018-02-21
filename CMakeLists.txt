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

##------------------------------------------------------------------------------
## Modules
##   Find packages scripts was taken from:
##     https://github.com/tcbrindle/sdl2-cmake-scripts
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake_find")


##----------------------------------------------------------------------------##
## SDL                                                                        ##
##----------------------------------------------------------------------------##
if(WIN32)
    set(SDL2_PATH       "${CMAKE_CURRENT_SOURCE_DIR}/windows/VS/SDL2-2.0.7"      )
    set(SDL2_IMAGE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/windows/VS/SDL2_image-2.0.2")
    set(SDL2_TTF_PATH   "${CMAKE_CURRENT_SOURCE_DIR}/windows/VS/SDL2_ttf-2.0.14" )
endif()

find_package(SDL2       REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf   REQUIRED)

include_directories(
    ${SDL2_INCLUDE_DIR}
    ${SDL2_IMAGE_INCLUDE_DIR}
    ${SDL2_TTF_INCLUDE_DIR}
)


##----------------------------------------------------------------------------##
## CoreRandom                                                                 ##
##----------------------------------------------------------------------------##
add_subdirectory(lib/CoreAssert      )
add_subdirectory(lib/CoreRandom      )
add_subdirectory(lib/CoreString      )
add_subdirectory(lib/CoreLog         )
add_subdirectory(lib/libtermcolor    )
add_subdirectory(lib/acow_nt_posix   )
add_subdirectory(lib/acow_cpp_goodies)
add_subdirectory(lib/acow_sdl_goodies)


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

    ## Sount
    Cooper/src/Sound/Sound.cpp
    Cooper/src/Sound/private/AudioLib.cpp
    Cooper/src/Sound/private/emscripten/AudioValues.cpp
    Cooper/src/Sound/private/SDL/AudioValues.cpp

    Cooper/src/Timer/Timer.cpp
)

target_include_directories(Cooper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Cooper PUBLIC ${SDL2_INCLUDE_DIR}        )
target_include_directories(Cooper PUBLIC ${SDL2_IMAGE_INCLUDE_DIRS} )
target_include_directories(Cooper PUBLIC ${SDL2_TTF_INCLUDE_DIRS}   )
target_include_directories(Cooper PUBLIC ./Cooper                   )
target_include_directories(Cooper PUBLIC ./lib/CoreRandom           )
target_include_directories(Cooper PUBLIC ./lib/acow_cpp_goodies     )
target_include_directories(Cooper PUBLIC ./lib/acow_sdl_goodies     )


##----------------------------------------------------------------------------##
## Link Libraries                                                             ##
##----------------------------------------------------------------------------##
target_link_libraries(Cooper LINK_PUBLIC CoreAssert             )
target_link_libraries(Cooper LINK_PUBLIC CoreRandom             )
target_link_libraries(Cooper LINK_PUBLIC CoreLog                )
target_link_libraries(Cooper LINK_PUBLIC libtermcolor           )
target_link_libraries(Cooper LINK_PUBLIC acow_nt_posix          )
target_link_libraries(Cooper LINK_PUBLIC acow_cpp_goodies       )
target_link_libraries(Cooper LINK_PUBLIC acow_sdl_goodies       )
target_link_libraries(Cooper LINK_PUBLIC ${SDL2_LIBRARY}        )
target_link_libraries(Cooper LINK_PUBLIC ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(Cooper LINK_PUBLIC ${SDL2_TTF_LIBRARIES}  )