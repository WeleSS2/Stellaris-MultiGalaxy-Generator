# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8...3.23)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
	cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(SMGG VERSION 1.0
                  DESCRIPTION "Stellaris MultiGalaxy Generator"
                  LANGUAGES CXX)


add_executable (CMakeTarget "${PROJECT_SOURCE_DIR}/Stellaris MultiGalaxy Generator/Stellaris MultiGalaxy Generator.cpp")

# Include sub-projects.
add_subdirectory ("Stellaris MultiGalaxy Generator")

# FILE(COPY "${PROJECT_SOURCE_DIR}/Dependencies/graphics" DESTINATION "${RUNTIME_OUTPUT_DIRECTORY}")

set( LIST_NEEDED_DLL
    ${PROJECT_SOURCE_DIR}/Dependencies/SDL/lib/x64/SDL2.dll
    ${PROJECT_SOURCE_DIR}/Dependencies/SDL_image/lib/x64/SDL2_image.dll
    ${PROJECT_SOURCE_DIR}/Dependencies/SDL_image/lib/x64/libpng16-16.dll
    ${PROJECT_SOURCE_DIR}/Dependencies/SDL_image/lib/x64/libjpeg-9.dll
    ${PROJECT_SOURCE_DIR}/Dependencies/SDL_image/lib/x64/libtiff-5.dll
    ${PROJECT_SOURCE_DIR}/Dependencies/SDL_image/lib/x64/libwebp-7.dll
    ${PROJECT_SOURCE_DIR}/Dependencies/SDL_TTF/lib/x64/SDL2_ttf.dll
    ${PROJECT_SOURCE_DIR}/Dependencies/SDL_TTF/lib/x64/libfreetype-6.dll
    ${PROJECT_SOURCE_DIR}/Dependencies/SDL_TTF/lib/x64/zlib1.dll
    ${PROJECT_SOURCE_DIR}/Dependencies/STEAM_API/lib/win64/steam_api64.dll
)

foreach( file_i ${LIST_NEEDED_DLL})
    add_custom_command(
    TARGET CMakeTarget
    POST_BUILD
    COMMAND ${CMAKE_COMMAND}
    ARGS -E copy ${file_i} $<TARGET_FILE_DIR:CMakeTarget>
)
endforeach( file_i )