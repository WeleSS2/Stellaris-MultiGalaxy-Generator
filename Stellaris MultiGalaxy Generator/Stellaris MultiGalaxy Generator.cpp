// Stellaris MultiGalaxy Generator.cpp : Defines the entry point for the application.
//

#include "Stellaris MultiGalaxy Generator.h"

int main(int argc, char* argv[])
{
    //Init SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        system("pause");
        return 1;
    }

    // Debug mode with console
    HideConsole();
    debug();

    // Take screen
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    SMGG_P::app->app_set_screen_width_height(DM.w, DM.h);


    // Init window
    if (!SMGG_P::app->get_init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        //Load media
        if (!SMGG_P::app->get_loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {
            // Some static required things
            bool exit = false;
            SDL_Event e;
            srand(time(NULL));

            //Settings checking, if they exist and are correctly load if not create new



            //Show up main menu
            SMGG::OpenedWindow.set(0);
            SMGG::OpenedWindow.set(1);
            SMGG::Windows_Path.emplace_back();
            SMGG::Windows_Path[0].push_back(0);
            //Fill windows vector
            for (int i = 0; i < 1000; ++i)
            {
                SMGG::Window_Cord.emplace_back();
            }
            SMGG_P::app->rerender();

            // Main loop
            while (!exit)
            {
                // Set max FPS at 30
                SDL_Delay(33);

                while (SDL_PollEvent(&e))
                {
                    if (e.type == SDL_MOUSEBUTTONDOWN)
                    {
                        SMGG_P::P_Buttons_Objects->Button_Back.handle_Button_Back(e);

                        if (SMGG::OpenedWindow.test(0))
                        {
                            for (int i = 0; i < SMGG_P::P_Buttons_Objects->Main_Menu_Buttons.size(); ++i)
                            {
                                SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[i].handle_Main_Menu_Buttons(e, i);
                            }
                            if (SMGG::OpenedWindow.test(10))
                            {
                                for (int i = 0; i < SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons.size(); ++i)
                                {
                                    SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[i].handle_Menu_Galaxies_Buttons(e, i);
                                }
                            }
                        }

                        SMGG_P::app->rerender();
                    }
                }
            }
        }
    }
    return 0;
}