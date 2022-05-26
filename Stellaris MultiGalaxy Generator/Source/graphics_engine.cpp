class Graphics_Engine
{
private:
    std::shared_ptr<Window_Init> P_Window_Init;
    std::shared_ptr<LTexture> P_LTexture;

public:
    Graphics_Engine()
    {
        P_Window_Init = std::shared_ptr<Window_Init>(std::make_shared < Window_Init >());
        P_LTexture = std::shared_ptr<LTexture>(std::make_shared < LTexture >());
    };
    SDL_Texture* gTexture = NULL;
    SDL_Texture* gBackground = NULL;

    //Texture holders
    LTexture gModulatedTexture;
    LTexture gPromptTextTexture;
    LTexture gInputTextTexture;
    LTexture gCheckboxTexture;
    LTexture gButtonSpriteSheetTexture;
    LTexture mButtonSpriteSheetTexture;

    //Load graphics
    bool loadMedia();


    void renderButtonafterText(int id, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

    void background()
    {
        SDL_RenderCopy(SMGG::gRenderer, gBackground, NULL, NULL);
    };

    int get_alpha()
    {
        return alpha;
    };

    //Load image to texture
    SDL_Texture* loadTexture(std::string path);
private:
    int alpha = 240;
};


void Graphics_Engine::renderButtonafterText(int id, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, P_LTexture->getWidth(), P_LTexture->getHeight()};

    ////Set clip rendering dimensions
    if (clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    ////Render to screen
    SDL_RenderCopyEx(SMGG::gRenderer, P_LTexture->getTexture(), clip, &renderQuad, angle, center, flip);
    //gButtons[id].setPosition(x + renderQuad.w - 3, y - 1);
    SDL_SetRenderDrawColor(SMGG::gRenderer, 177, 177, 177, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(SMGG::gRenderer, 
        P_Window_Init->get_center_width() + x + renderQuad.w, 
        P_Window_Init->get_center_height() + y + 30, 
        P_Window_Init->get_center_width() + x + renderQuad.w + 50, 
        P_Window_Init->get_center_height() + y + 30);
}

bool Graphics_Engine::loadMedia()
{
    //Loading success flag
    bool success = true;

    // Load Background
    gBackground = loadTexture("graphics/backgroundS.png");

    if (!gModulatedTexture.loadFromFile("graphics/black1.png"))
    {
        std::cout << "Error in loadFromFile black1.png" << std::endl;
        success = false;
    }
    else
    {
        gModulatedTexture.setBlendMode(SDL_BLENDMODE_BLEND);
    }


    if (!gCheckboxTexture.loadFromFile("graphics/box.png"))
    {
        std::cout << "Error in loadFromFile box.png" << std::endl;
        success = false;
    }
    else
    {
        gCheckboxTexture.setBlendMode(SDL_BLENDMODE_BLEND);
    }



    //Load sprites
    if (!mButtonSpriteSheetTexture.loadFromFile("graphics/ButtonSmall.png"))
    {
        printf("Failed to load small button sprite texture!\n");
        success = false;
    }
    if (!gButtonSpriteSheetTexture.loadFromFile("graphics/buttonBIG.png"))
    {
        printf("Failed to load button sprite texture!\n");
        success = false;
    }
    ////Set sprites
    //for (int i = 0; i < 4; ++i)
    //{

    //    gSpriteClips[i].x = 0;
    //    gSpriteClips[i].y = 0;
    //    gSpriteClips[i].h = BUTTON_HEIGHT;
    //    if (i == 0)
    //    {
    //        gSpriteClips[i].w = BUTTON_WIDTH;
    //    }
    //    else if (i == 1)
    //    {
    //        gSpriteClips[i].y = 45;
    //        gSpriteClips[i].w = BUTTON_WIDTH;
    //    }

    //}

    //gFont = TTF_OpenFont("graphics/Orbi.ttf", 24);
    //if (gFont == NULL)
    //{
    //    printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
    //    success = false;
    //}


    //Nothing to load
    return success;
}

SDL_Texture* Graphics_Engine::loadTexture(std::string path)
{
    //The final texture
    SDL_Texture* newTexture = NULL;
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(SMGG::gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}