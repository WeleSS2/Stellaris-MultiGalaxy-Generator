void setup_app::app_set_screen_width_height(int x, int y)
{
    SMGG_P::P_Window_Init->set_screen_width_height(x, y);
    SMGG_P::P_Window_Init->set_center();
};

bool setup_app::get_init()
{
    return SMGG_P::P_Window_Init->init();
};

bool setup_app::get_loadMedia()
{
    return SMGG_P::P_Graphics_Engine->loadMedia();
};

void setup_app::app_background()
{
    SMGG_P::P_Graphics_Engine->background();
};

void setup_app::rerender()
{
    throw_out_buttons();
    SDL_RenderClear(SMGG::gRenderer);
    app_background();
    if (SMGG::OpenedWindow.test(0))
    {
        SMGG_P::P_Application_Modules->main_menu_module();
    }
    if (SMGG::OpenedWindow.test(1))
    {
        SMGG_P::P_Application_Modules->left_map_module();
    }
    if (SMGG::OpenedWindow.test(10))
    {
        SMGG_P::P_Application_Modules->galaxies_module();
        if (SMGG::OpenedWindow.test(11))
        {
            SMGG_P::P_Application_Modules->galaxies_module_manage_galaxies();
        }
        if (SMGG::OpenedWindow.test(12))
        {
            SMGG_P::P_Application_Modules->galaxies_module_manage_hyperlanes();
        }
        if (SMGG::OpenedWindow.test(13))
        {
            SMGG_P::P_Application_Modules->galaxies_module_manage_initializers();
        }
    }
    if (SMGG::OpenedWindow.test(20))
    {
        SMGG_P::P_Application_Modules->maps_module();
    }
    SDL_RenderPresent(SMGG::gRenderer);
};

void setup_app::throw_out_buttons()
{
    SMGG_P::P_Buttons_Objects->Button_Back.setPosition(-1000, -1000);
    if (SMGG::OpenedWindow.test(0))
    {
        for (int i = 0; i < SMGG_P::P_Buttons_Objects->Main_Menu_Buttons.size(); ++i)
        {
            SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[i].setPosition(-1000, -1000);
        }
    }
    if (SMGG::OpenedWindow.test(10))
    {
        for (int i = 0; i < SMGG_P::P_Buttons_Objects->Galaxies_Buttons.size(); ++i)
        {
            SMGG_P::P_Buttons_Objects->Galaxies_Buttons[i].setPosition(-1000, -1000);
        }
    }
    for (int i = 0; i < SMGG_P::P_Buttons_Objects->Main_Detailed_Generation_Buttons.size(); ++i)
    {
        SMGG_P::P_Buttons_Objects->Main_Detailed_Generation_Buttons[i].setPosition(-1000, -1000);
    }
    for (int i = 0; i < SMGG_P::P_Buttons_Objects->Initializers_Buttons.size(); ++i)
    {
        SMGG_P::P_Buttons_Objects->Initializers_Buttons[i].setPosition(-1000, -1000);
    }
    for (int i = 0; i < SMGG_P::P_Buttons_Objects->Map_Buttons.size(); ++i)
    {
        SMGG_P::P_Buttons_Objects->Map_Buttons[i].setPosition(-1000, -1000);
    }
    for (int i = 0; i < SMGG_P::P_Buttons_Objects->Settings_Buttons.size(); ++i)
    {
        SMGG_P::P_Buttons_Objects->Settings_Buttons[i].setPosition(-1000, -1000);
    }
}