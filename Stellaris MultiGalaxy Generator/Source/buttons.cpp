class Buttons_Objects
{
public:
    class Buttons_Data
    {
    private:
        std::shared_ptr<LTexture> P_LTexture;
        std::shared_ptr<Graphics_Engine> P_Graphics_Engine;
        std::shared_ptr<Buttons_Graphics> P_Buttons_Graphics;

    public:
        void handleEvent(SDL_Event* e, int id, int id_2);
        Buttons_Graphics::LButtonSprite mCurrentSprite = Buttons_Graphics::BUTTON_SPRITE_MOUSE_BIG;

        Buttons_Data()
        {
            mPosition.x = -1000;
            mPosition.y = -1000;
            P_LTexture = std::shared_ptr<LTexture>(std::make_shared < LTexture > ());
            P_Graphics_Engine = std::shared_ptr<Graphics_Engine>(std::make_shared < Graphics_Engine > ());
            P_Buttons_Graphics = std::shared_ptr<Buttons_Graphics>(std::make_shared < Buttons_Graphics > ());
        };


        void setPosition(int x, int y)
        {
            mPosition.x = x;
            mPosition.y = y;
        };


        void render()
        {
            P_Graphics_Engine->gButtonSpriteSheetTexture.renderButton(mPosition.x, mPosition.y, &P_Buttons_Graphics->gSpriteClips[mCurrentSprite]);
        };

        void renderDynamic(int mode, int w, int h)
        {
            if (mode == 0)
            {
                P_Graphics_Engine->gButtonSpriteSheetTexture.renderButtonDynamicSize(mPosition.x, mPosition.y, w, h, &P_Buttons_Graphics->gSpriteClips[mCurrentSprite]);
            }
        };

    private:
        SDL_Point mPosition;
    };

    void build_Buttons_Objects();

    std::vector<Buttons_Data> Main_Menu_Buttons;
    std::vector<Buttons_Data> Galaxies_Buttons;
    std::vector<Buttons_Data> Main_Detailed_Generation_Buttons;
    std::vector<Buttons_Data> Initializers_Buttons;
    std::vector<Buttons_Data> Map_Buttons;
    std::vector<Buttons_Data> Settings_Buttons;
    std::vector<std::vector <Buttons_Data>> Mod_Initializers_Buttons; //Created dynamically from user mods
    std::vector<std::vector <Buttons_Data>> SystemButtons; //Created dynamically from map
};

void Buttons_Objects::build_Buttons_Objects()
{
    // Create buttons holders

    for (int i = 0; i <= 10; ++i)
    {
        Main_Menu_Buttons.emplace_back();
    }
    for (int i = 0; i < 50; ++i)
    {
        Galaxies_Buttons.emplace_back();
    }
    for (int i = 0; i < 50; ++i)
    {
        Main_Detailed_Generation_Buttons.emplace_back();
    }
    for (int i = 0; i < 150; ++i)
    {
        Initializers_Buttons.emplace_back();
    }
    for (int i = 0; i < 50; ++i)
    {
        Map_Buttons.emplace_back();
    }
    for (int i = 0; i < 150; ++i)
    {
        Settings_Buttons.emplace_back();
    }
}