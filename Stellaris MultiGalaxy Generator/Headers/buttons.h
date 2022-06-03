#pragma once
/*
Buttons modes
0 - Set position, with graphics
1 - Set position, no graphics
2 - Auto button size around text
3 - Render button AFTER text without a graphics
4 - Render button AFTER text with a graphics

*/

class Buttons_Objects
{
public:
    class Buttons_Data
    {
    public:
        LButtonSprite mCurrentSprite = LButtonSprite::BUTTON_SPRITE_MOUSE_BIG;

        Buttons_Data();

        void handle_Main_Menu_Buttons(SDL_Event& e, int id);
        void handle_Button_Back(SDL_Event& e);
        void handle_Menu_Galaxies_Buttons(SDL_Event& e, int id);

        void setPosition(int x, int y);
        void setWidth(double value);
        void setHeight(double value);

        double getWidth();
        double getHeight();

        void renderDynamic(int mode, int w = 180, int h = 45);

        void render_button_dynamic(int button_class, int mode, int button_id, int button_x, int button_y,
            int button_id_2 = -10, int width = 180, int height = 45, std::string tekst = "", int text_x = 0, int text_y = 0, int center_pos = -10);

    private:
        SDL_Point mPosition;
        double B_width, B_height;
    };

    void build_Buttons_Objects();
    Buttons_Data Button_Back;
    std::vector<Buttons_Data> Main_Menu_Buttons;
    std::vector<Buttons_Data> Menu_Galaxies_Buttons;
    std::vector<Buttons_Data> Menu_Map_Buttons;

    std::vector<Buttons_Data> Galaxies_Buttons;
    std::vector<Buttons_Data> Main_Detailed_Generation_Buttons;
    std::vector<Buttons_Data> Initializers_Buttons;
    std::vector<Buttons_Data> Map_Buttons;
    std::vector<Buttons_Data> Settings_Buttons;
    std::vector<std::vector <Buttons_Data>> Mod_Initializers_Buttons; //Created dynamically from user mods
    std::vector<std::vector <Buttons_Data>> SystemButtons; //Created dynamically from map
};


/*
Main_Menu_Buttons
0 - Galaxies
1 - Maps
2 - Settings
3 - Nothing
4 - Nothing
5 - Play & Exit

10 - Back buttons UNIVERSAL

Menu_Galaxies_Buttons
0 - Checkbox Show Hyperlanes
1 - Checkbox Show Initializers
2 - "Manage Galaxies"
3 - "Manage Hyperlanes"
4 - "Manage Initializers"
5 - Circle/Ring
6 - Spiral
7 - Irregular
8 - Edit
9 - Redraw
10 - Remove
*/