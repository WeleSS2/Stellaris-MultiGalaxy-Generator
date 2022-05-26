struct Buttons_Graphics
{
public: 
    enum LButtonSprite
    {
        BUTTON_SPRITE_MOUSE_BIG = 0,
        BUTTON_SPRITE_MOUSE_BIG_PRESSED = 1,
        BUTTON_SPRITE_MOUSE_SMALL = 2,
        BUTTON_SPRITE_MOUSE_SMALL_PRESSED = 3,
        BUTTON_SPRITE_TOTAL = 4
    };

    SDL_Rect gSpriteClips[BUTTON_SPRITE_TOTAL];
protected:
    //Buttons size
    const int BUTTON_WIDTH = 180;
    const int BUTTON_WIDTH_SMALL = 45;
    const int BUTTON_HEIGHT = 45;
};