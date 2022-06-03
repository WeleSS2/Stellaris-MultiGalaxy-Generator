class Application_Modules
{
public:
    // Default Modules
    void main_menu_module(); // 0
    void left_map_module(); // 1


    void galaxies_module(); // 10
    void galaxies_module_manage_galaxies(); // 11
    void galaxies_module_manage_hyperlanes(); // 12
    void galaxies_module_manage_initializers(); // 13
    void detailed_generation_module(); // 100

    void maps_module(); // 20
    void load_map_from_photo_module(); // 200


    void settings_module(); // 30
    void generator_settings_module(); // 300
    void game_settings_module(); // 310
    void patch_settings_module(); // 320

    void exit_module(); // 40
};

void Application_Modules::main_menu_module()
{
    SMGG_P::P_Graphics_Engine->blank_window(0, 0, 1200, 0, 720, 150);
    SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[0].render_button_dynamic(0, 0, 0, 1245, 20, -10, 180, 45, "Galaxies", 1278, 25);
    SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[1].render_button_dynamic(0, 0, 1, 1245, 85, -10, 180, 45, "Maps", 1303, 90);
    SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[2].render_button_dynamic(0, 0, 2, 1465, 20, -10, 180, 45, "Settings", 1500, 25);
    SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[3].render_button_dynamic(0, 0, 3, 1465, 85);
    SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[4].render_button_dynamic(0, 0, 4, 1690, 20);
    SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[5].render_button_dynamic(0, 0, 5, 1690, 85, -10, 180, 45, "Play&Exit", 1717, 90);
};

void Application_Modules::left_map_module()
{
    SMGG_P::P_Graphics_Engine->set_alpha(250);
    SMGG_P::P_Graphics_Engine->blank_window(0, 1, 0, 0, 1200, 1080);
    SMGG_P::P_Graphics_Engine->reset_alpha();
    SMGG_P::P_Graphics_Engine->text_render("- -", 20, 10);
    SMGG_P::P_Graphics_Engine->text_render("- +", 20, 10);
    SMGG_P::P_Graphics_Engine->text_render("+ -", 1150, 10);
    SMGG_P::P_Graphics_Engine->text_render("+ +", 1150, 1040);
}

void Application_Modules::galaxies_module()
{
    SMGG_P::P_Graphics_Engine->blank_window(0, 10, 1200, 150, 720, 930);
    int win_x_1{ SMGG::Window_Cord[10].x + 20 }, win_y{ SMGG::Window_Cord[10].y + 15 }, mult{ 0 }, mult_2{ 0 },
        win_x_2 = win_x_1 + 390, y_offset = 15;
    
    // Left panel with galaxy data
    SMGG_P::P_Graphics_Engine->text_render("Systems: " + SMGG::R_T.system_amount, win_x_1, win_y);
    SMGG_P::P_Graphics_Engine->text_render("Empires: " + SMGG::R_T.empires_amount, win_x_1, win_y + (++mult * 40));
    SMGG_P::P_Graphics_Engine->text_render("Fallen Empires: " + SMGG::R_T.fallen_amount, win_x_1, win_y + (++mult * 40));
    SMGG_P::P_Graphics_Engine->text_render("Marauders: " + SMGG::R_T.marauders_amount, win_x_1, win_y + (++mult * 40));
    SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[0].mCurrentSprite = LButtonSprite::Button_Sprite_BlackBG_SilverBorder;
    SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[0].render_button_dynamic(1, 4, 0, win_x_1, win_y + (++mult * 40),
        -10, 30, 30, "Hyperlanes ", win_x_1, win_y + (mult * 40));
    SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[1].mCurrentSprite = LButtonSprite::Button_Sprite_BlackBG_SilverBorder;
    SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[1].render_button_dynamic(1, 4, 1, win_x_1, win_y + (++mult * 40),
        -10, 30, 30, "Initializers ", win_x_1, win_y + (mult * 40));
    

    // Right panel with sub-menus
    SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[2].render_button_dynamic(1, 2, 2, win_x_2 + 17, win_y + y_offset + (mult_2 * 60),
        -10, 0, 0, "Manage Galaxies", win_x_2 + 17, win_y + y_offset + (mult_2 * 60));
    SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[3].render_button_dynamic(1, 2, 3, win_x_2, win_y + y_offset + (++mult_2 * 60),
        -10, 0, 0, "Manage Hyperlanes", win_x_2, win_y + y_offset + (mult_2 * 60));
    SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[4].render_button_dynamic(1, 2, 4, win_x_2 + 12, win_y + y_offset + (++mult_2 * 60),
        -10, 0, 0, "Manage Initializers", win_x_2 + 12, win_y + y_offset + (mult_2 * 60));
}

void Application_Modules::galaxies_module_manage_galaxies()
{
    SMGG_P::P_Graphics_Engine->blank_window(1, 10, 1200, 450, 720, 630);
    int win_x_1{ SMGG::Window_Cord[10].x + 60 }, win_y{ SMGG::Window_Cord[10].y + 10 }, mult{ 0 }, mult_2{ 0 },
        win_x_2 = win_x_1 + 350, y_offset = 15;
    SMGG_P::P_Graphics_Engine->line(win_x_1 - 60, win_y - 10, win_x_1 + 710, win_y - 10);
    
    // Left Panel
    SMGG_P::P_Graphics_Engine->text_render("New Galaxy", win_x_1, win_y);
    SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[5].render_button_dynamic(1, 2, 5, win_x_1 + 5, win_y + (++mult * 55),
        -10, 0, 0, "Circle/Ring", win_x_1 + 5, win_y + (mult * 55));
    SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[6].render_button_dynamic(1, 2, 6, win_x_1 + 40, win_y + (++mult * 55),
        -10, 0, 0, "Spiral", win_x_1 + 40, win_y + (mult * 55));
    SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[7].render_button_dynamic(1, 2, 7, win_x_1 + 20, win_y + (++mult * 55),
        -10, 0, 0, "Irregular", win_x_1 + 20, win_y + (mult * 55));

    // Right Panel
    SMGG_P::P_Graphics_Engine->text_render("Edit Galaxy", win_x_2, win_y);
    SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[8].render_button_dynamic(1, 2, 8, win_x_2 + 55, win_y + (++mult_2 * 55),
        -10, 0, 0, "Edit", win_x_2 + 55, win_y + (mult_2 * 55), 1400);
    SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[9].render_button_dynamic(1, 2, 9, win_x_2 + 30, win_y + (++mult_2 * 55),
        -10, 0, 0, "Redraw", win_x_2 + 30, win_y + (mult_2 * 55), 1400);
    SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[10].render_button_dynamic(1, 2, 10, win_x_2 + 25, win_y + (++mult_2 * 55),
        -10, 0, 0, "Remove", win_x_2 + 25, win_y + (mult_2 * 55), 1400);

}

void Application_Modules::galaxies_module_manage_hyperlanes()
{

}

void Application_Modules::galaxies_module_manage_initializers()
{

}

void Application_Modules::maps_module()
{
    SMGG_P::P_Graphics_Engine->blank_window(0, 20, 1200, 0, 720, 1080);
    int win_x_1{ SMGG::Window_Cord[20].x + 10 }, win_y{ SMGG::Window_Cord[20].y + 10 }, mult{ 0 };
    SMGG_P::P_Buttons_Objects->Button_Back.mCurrentSprite = LButtonSprite::Arrow_Sprite_Left;
    SMGG_P::P_Buttons_Objects->Button_Back.render_button_dynamic(-1, 0, 0, win_x_1, win_y + 10, -10, 40, 30);
}