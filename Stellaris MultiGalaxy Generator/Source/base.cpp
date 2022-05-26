class Application_Modules
{
private:
    std::shared_ptr<Window_Init> P_Window_Init;
    std::shared_ptr<Graphics_Engine> P_Graphics_Engine;
    std::shared_ptr<Buttons_Objects> P_Buttons_Objects;
public:
    Application_Modules()
    {
        P_Window_Init = std::shared_ptr<Window_Init>(std::make_shared<Window_Init>());
        P_Graphics_Engine = std::shared_ptr<Graphics_Engine>(std::make_shared<Graphics_Engine>());
        P_Buttons_Objects = std::shared_ptr<Buttons_Objects>(std::make_shared<Buttons_Objects>());
    };

    void main_menu_module()
    {
        P_Graphics_Engine->gModulatedTexture.setAlpha(P_Graphics_Engine->get_alpha());
        P_Graphics_Engine->gModulatedTexture.render(P_Window_Init->get_center_width() + 1200, P_Window_Init->get_center_height(), 720, 150);

        /*P_Buttons_Objects->Main_Menu_Buttons[0].setPosition(P_Window_Init->get_center_width() + 1245, P_Window_Init->get_center_height() + 20);
        P_Buttons_Objects->Main_Menu_Buttons[1].setPosition(P_Window_Init->get_center_width() + 1245, P_Window_Init->get_center_height() + 85);
        P_Buttons_Objects->Main_Menu_Buttons[2].setPosition(P_Window_Init->get_center_width() + 1465, P_Window_Init->get_center_height() + 20);
        P_Buttons_Objects->Main_Menu_Buttons[3].setPosition(P_Window_Init->get_center_width() + 1465, P_Window_Init->get_center_height() + 85);
        P_Buttons_Objects->Main_Menu_Buttons[4].setPosition(P_Window_Init->get_center_width() + 1690, P_Window_Init->get_center_height() + 20);
        P_Buttons_Objects->Main_Menu_Buttons[5].setPosition(P_Window_Init->get_center_width() + 1690, P_Window_Init->get_center_height() + 85);

        for (int i = 0; i < 6; ++i)
        {
            P_Buttons_Objects->Main_Menu_Buttons[i].render();
        }*/
    };
};

class setup_app
{
private:
    std::shared_ptr<Window_Init> P_Window_Init;
    std::shared_ptr<Graphics_Engine> P_Graphics_Engine;
    std::shared_ptr<Application_Modules> P_Application_Modules;
public:
    setup_app()
    {
        P_Window_Init = std::shared_ptr<Window_Init>(std::make_shared <Window_Init>());
        P_Graphics_Engine = std::shared_ptr<Graphics_Engine>(std::make_shared <Graphics_Engine>());
        P_Application_Modules = std::shared_ptr<Application_Modules>(std::make_shared <Application_Modules>());
    }
    void app_set_screen_width_height(int x, int y)
    {
        P_Window_Init->set_screen_width_height(x, y);
        P_Window_Init->set_center();
    };

    bool get_init()
    {
        return P_Window_Init->init();
    };

    bool get_loadMedia()
    {
        return P_Graphics_Engine->loadMedia();
    };

    void app_background()
    {
        P_Graphics_Engine->loadMedia();
        P_Graphics_Engine->background();
        P_Application_Modules->main_menu_module();
        std::cout << "Work" << std::endl;
        SDL_RenderPresent(SMGG::gRenderer);
        SDL_Delay(50000);
    };
};