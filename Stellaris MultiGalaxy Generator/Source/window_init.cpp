class Window_Init {
public:
    SDL_Window* gWindow = NULL;

    //Initialize window
    bool init();

    //Window size/Dynamic window sizing
    void set_screen_width_height(int w, int h)
    {
        SCREEN_WIDTH = w;
        SCREEN_HEIGHT = h;
    }

    //Setting a center
    void set_center()
    {
        center_width = ((SCREEN_WIDTH - 1920) / 2);
        center_height = ((SCREEN_HEIGHT - 1080) / 2);
    }

    virtual int get_center_width()
    {
        return center_width;
    }

    virtual int get_center_height()
    {
        return center_height;
    }
private:
    //Screen size
    int SCREEN_WIDTH = 0,
        SCREEN_HEIGHT = 0,
        center_width = 0,
        center_height = 0;
};


// Initialize Window body
bool Window_Init::init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
            std::cout << "Filtering to linear not enabled" << std::endl;
        //Create window
        gWindow = SDL_CreateWindow("Stellaris MultiGalaxy Generator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            SMGG::gRenderer = SDL_CreateRenderer(gWindow, 0, SDL_RENDERER_ACCELERATED);
            if (SMGG::gRenderer == NULL)
                std::cout << "Error in init - > gRenderer" << std::endl;

            else
            {
                SDL_SetRenderDrawColor(SMGG::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
                //Get window surface
                if (TTF_Init() == -1)
                {
                    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
};