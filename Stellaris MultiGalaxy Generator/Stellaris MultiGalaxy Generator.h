// Stellaris MultiGalaxy Generator.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <string>
#include <math.h>
#include <sstream>
#include <filesystem>
#include <random>
#include <limits>
#include <thread>
#include <chrono>
#include <thread>
#include <bitset>
#include <memory>

#define NOMINMAX

#include <windows.h>
#include <ShObjIdl.h>
#include <ShlObj.h>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"


#include "steam_api.h"

#include "Source/smgg_namespaces.h"
#include "Source/window_init.cpp"
#include "Source/init_textures.cpp"
#include "Source/graphics_engine.cpp"
#include "Source/button_data.h"
#include "Source/buttons.cpp"
#include "Source/buttons_events.cpp"

#include "Source/base.cpp"
#include "Source/basic_menu.cpp"
#include "Source/algo.cpp"
#include "Source/file_operation.cpp"
#include "Source/debug.cpp"

// TODO: Reference additional headers your program requires here.

//
//Project tree and data
// window_init.cpp (Building a window and renderer)
// init_textures.cpp (Loading textures and keeping them in memory)
// graphics_engine.cpp (Rendering textures, buttons and others graphics things)
// buttons_data.h (Sprite sheets for buttons)
// buttons.cpp (Building objects for a buttons and keeping them in memory)
// buttons_events.cpp (Buttons operations and events)
// basic_menu.cpp (Rendering background and basic menu operations + (Current tab maintainment))






















