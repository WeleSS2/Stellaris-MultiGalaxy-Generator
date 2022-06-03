class Graphics_Engine
{
public:
    SDL_Texture* gTexture = NULL;
    SDL_Texture* gBackground = NULL;

    //Texture holders
    LTexture gModulatedTexture;
    LTexture gPromptTextTexture;
    LTexture gInputTextTexture;
    LTexture gButtonSpriteSheetTexture;

    //Load graphics
    bool loadMedia();

    void back_arrow();

    void blank_window(int mode, int id, int x_pos, int y_pos, int width, int height);
    
    void set_window_position(int window_id, int position);

    void text_render(std::string tekst, int x, int y);

    void line(int x_1, int y_1, int x_2, int y_2);

    void renderButtonafterText(int id, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

    void click_effect(int button_class, int mode, int button_id);

    void background()
    {
        SDL_RenderCopy(SMGG::gRenderer, gBackground, NULL, NULL);
    };

    int get_alpha()
    {
        return alpha;
    };

    void set_alpha(int alpha_in)
    {
        alpha = alpha_in;
    }

    void reset_alpha()
    {
        alpha = 240;
    }

    //Load image to texture
    SDL_Texture* loadTexture(std::string path);
private:
    int alpha = 240;
};