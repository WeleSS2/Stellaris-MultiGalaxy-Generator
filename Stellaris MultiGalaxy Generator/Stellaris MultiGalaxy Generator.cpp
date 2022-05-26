// Stellaris MultiGalaxy Generator.cpp : Defines the entry point for the application.
//

#include "Stellaris MultiGalaxy Generator.h"

int main(int argc, char* argv[])
{
    setup_app app;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        system("pause");
        return 1;
    }

    HideConsole();
    debug();
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);

    app.app_set_screen_width_height(DM.w, DM.h);

    if (!app.get_init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        //Load media
        if (!app.get_loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {
            app.app_background();
        }
    }
    return 0;
}