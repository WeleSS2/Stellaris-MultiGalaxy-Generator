// Stellaris MultiGalaxy Generator.h : Include file for standard system include files,
// or project specific include files.

#pragma once
// Default libs
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
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


// Additional dependencies
#include <windows.h>
#include <ShObjIdl.h>
#include <ShlObj.h>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "steam_api.h"


// Headers
// Part 1, "deep code"
#include "Headers/Classes_Declarations.h"
#include "Headers/smgg_namespace.h" // Namespace for SMGG
#include "Headers/window_init.h"
#include "Headers/init_textures.h"


// Part 2
#include "Headers/smgg_pointers_namespace.h"
#include "Headers/buttons.h"
#include "Headers/graphics_engine.h"
#include "Headers/base.h"

// Source
#include "Source/window_init.cpp"
#include "Source/init_textures.cpp"
#include "Source/graphics_engine.cpp"
#include "Source/buttons.cpp"
#include "Source/buttons_events.cpp"

#include "Source/application_modules.cpp"
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






















