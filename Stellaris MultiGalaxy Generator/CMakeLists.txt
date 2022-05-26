# CMakeList.txt : CMake project for Stellaris MultiGalaxy Generator, include source and define
# project specific logic here.
#
# Add source to this project's executable.

find_package(SDL2 REQUIRED PATHS ${PROJECT_SOURCE_DIR}/Dependencies/SDL)
find_package(SDL2_image REQUIRED PATHS ${PROJECT_SOURCE_DIR}/Dependencies/SDL_image)
find_package(SDL2_ttf REQUIRED PATHS ${PROJECT_SOURCE_DIR}/Dependencies/SDL_TTF)
find_package(STEAMAPI REQUIRED PATHS ${PROJECT_SOURCE_DIR}/Dependencies/STEAM_API)

add_subdirectory ("Source")

target_include_directories(CMakeTarget PRIVATE "${PROJECT_SOURCE_DIR}/Graphics")

target_include_directories(CMakeTarget PRIVATE "${SDL2_INCLUDE_DIRS}")
target_include_directories(CMakeTarget PRIVATE "${SDL2_IMAGE_INCLUDE_DIRS}")
target_include_directories(CMakeTarget PRIVATE "${SDL2_TTF_INCLUDE_DIRS}")
target_include_directories(CMakeTarget PRIVATE "${STEAMAPI_INCLUDE_DIRS}")


target_include_directories(CMakeTarget PRIVATE Source)
target_link_directories(CMakeTarget PRIVATE Source)

target_link_libraries(CMakeTarget ${SDL2_LIBRARIES}) 
target_link_libraries(CMakeTarget ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(CMakeTarget ${SDL2_TTF_LIBRARIES}) 
target_link_libraries(CMakeTarget ${STEAMAPI_LIBRARIES})
# TODO: Add tests and install targets if needed.
