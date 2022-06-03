/*
Rozwiazanie do back arrow
Zrob template klasy na obiekty
Przy kazdym oknie ktore zeruje prawy panel wywolaj nowy obiekt tej klasy z lista, 
Odejmuj stopniowo liste jak zejdzie do zera zlikwiduj obiekt i wyswietl poprzedni obiekt.

*/
void Graphics_Engine::set_window_position(int window_id, int position)
{
    std::cout << SMGG::Windows_Path[SMGG::Windows_Path.size() - 1].size() << "   " << SMGG::Windows_Path.size() << "    " << window_id << "   " << position << "\n";
    if ((SMGG::Windows_Path[SMGG::Windows_Path.size() - 1].size() < position) || (position == 0))
    {
        SMGG::Windows_Path[SMGG::Windows_Path.size() - 1].push_back(window_id);
        SMGG::OpenedWindow.set(window_id);
    }
    else
    {
        std::cout << SMGG::Windows_Path[SMGG::Windows_Path.size() - 1].size() - 1 << "\n";
        SMGG::OpenedWindow.reset(SMGG::Windows_Path[SMGG::Windows_Path.size() - 1][position]);
        SMGG::Windows_Path[SMGG::Windows_Path.size() - 1].insert(SMGG::Windows_Path[SMGG::Windows_Path.size() - 1].end() - 1, window_id);
        SMGG::Windows_Path[SMGG::Windows_Path.size() - 1].erase(SMGG::Windows_Path[SMGG::Windows_Path.size() - 1].end() - 1);
    }
    SMGG::OpenedWindow.reset(0);
    SMGG::reset_window(10);
    for (int i = 0; i < SMGG::Windows_Path[SMGG::Windows_Path.size() - 1].size(); ++i)
    {
        SMGG::OpenedWindow.set(SMGG::Windows_Path[SMGG::Windows_Path.size() - 1][i]);
    }
}


void Graphics_Engine::line(int start_x, int start_y, int end_x, int end_y)
{
    SDL_SetRenderDrawColor(SMGG::gRenderer, 122, 122, 122, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(SMGG::gRenderer, start_x, start_y, end_x, end_y);
}

void Graphics_Engine::back_arrow()
{
    if (SMGG::Windows_Path[SMGG::Windows_Path.size() - 1].size() - 1 > 0)
    {
        SMGG::OpenedWindow.reset(SMGG::Windows_Path[SMGG::Windows_Path.size() - 1].back());
        SMGG::Windows_Path[SMGG::Windows_Path.size() - 1].pop_back();
        SMGG::OpenedWindow.set(SMGG::Windows_Path[SMGG::Windows_Path.size() - 1].back());
    }
    else
    {
        SMGG::OpenedWindow.reset(SMGG::Windows_Path[SMGG::Windows_Path.size() - 1].back());
        SMGG::Windows_Path.pop_back();
        for (int i = 0; i < SMGG::Windows_Path[SMGG::Windows_Path.size() - 1].size(); ++i)
        {
            SMGG::OpenedWindow.set(SMGG::Windows_Path[SMGG::Windows_Path.size() - 1].at(i));
        }
    }
}

void Graphics_Engine::click_effect(int button_class, int mode, int button_id)
{
    if (button_class == 0)
    {
        if (mode == 0)
        {
            SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[button_id].mCurrentSprite = BUTTON_SPRITE_MOUSE_BIG_PRESSED;
            SMGG_P::app->rerender();
            SDL_Delay(60);
            SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[button_id].mCurrentSprite = BUTTON_SPRITE_MOUSE_BIG;
        }
    }
}

void Graphics_Engine::text_render(std::string tekst, int x, int y)
{
    gPromptTextTexture.loadFromRenderedText(tekst, SMGG::SilverTextColor);
    gPromptTextTexture.renderButton(SMGG_P::P_Window_Init->get_center_width() + x, SMGG_P::P_Window_Init->get_center_height() + y);
}

void Graphics_Engine::blank_window(int mode, int id, int x = 0, int y = 0, int width = 0, int height = 0)
{
    SMGG::Window_Cord[id].x = SMGG_P::P_Window_Init->get_center_width() + x;
    SMGG::Window_Cord[id].y = SMGG_P::P_Window_Init->get_center_height() + y;
    if (mode == 0)
    {
        gModulatedTexture.setAlpha(get_alpha());
        gModulatedTexture.render(SMGG_P::P_Window_Init->get_center_width() + x, SMGG_P::P_Window_Init->get_center_height() + y, width, height);
    }
    else if (mode == 1)
    {

    }
}

void Graphics_Engine::renderButtonafterText(int id, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, SMGG_P::P_LTexture->getWidth(), SMGG_P::P_LTexture->getHeight()};

    ////Set clip rendering dimensions
    if (clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    ////Render to screen
    SDL_RenderCopyEx(SMGG::gRenderer, SMGG_P::P_LTexture->getTexture(), clip, &renderQuad, angle, center, flip);
    //gButtons[id].setPosition(x + renderQuad.w - 3, y - 1);
    SDL_SetRenderDrawColor(SMGG::gRenderer, 177, 177, 177, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(SMGG::gRenderer, 
        SMGG_P::P_Window_Init->get_center_width() + x + renderQuad.w, 
        SMGG_P::P_Window_Init->get_center_height() + y + 30, 
        SMGG_P::P_Window_Init->get_center_width() + x + renderQuad.w + 50, 
        SMGG_P::P_Window_Init->get_center_height() + y + 30);
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



    //Load sprites
    if (!gButtonSpriteSheetTexture.loadFromFile("graphics/buttons.png"))
    {
        printf("Failed to load button sprite texture!\n");
        success = false;
    }
    else
    {
        // Normal
        SMGG::gSpriteClips[0].x = 0;
        SMGG::gSpriteClips[0].y = 0;
        SMGG::gSpriteClips[0].w = 180;
        SMGG::gSpriteClips[0].h = 45;

        // Normal Pressed
        SMGG::gSpriteClips[1].x = 0;
        SMGG::gSpriteClips[1].y = 45;
        SMGG::gSpriteClips[1].w = 180;
        SMGG::gSpriteClips[1].h = 45;


        // Arrows, TOP
        SMGG::gSpriteClips[2].x = 185;
        SMGG::gSpriteClips[2].y = 0;
        SMGG::gSpriteClips[2].w = 130;
        SMGG::gSpriteClips[2].h = 160;
        // Bottom
        SMGG::gSpriteClips[3].x = 315;
        SMGG::gSpriteClips[3].y = 0;
        SMGG::gSpriteClips[3].w = 135;
        SMGG::gSpriteClips[3].h = 170;
        // Left
        SMGG::gSpriteClips[4].x = 0;
        SMGG::gSpriteClips[4].y = 100;
        SMGG::gSpriteClips[4].w = 170;
        SMGG::gSpriteClips[4].h = 120;
        // Right
        SMGG::gSpriteClips[5].x = 5;
        SMGG::gSpriteClips[5].y = 230;
        SMGG::gSpriteClips[5].w = 170;
        SMGG::gSpriteClips[5].h = 120;

        // Black BG silver border
        SMGG::gSpriteClips[6].x = 450;
        SMGG::gSpriteClips[6].y = 0;
        SMGG::gSpriteClips[6].w = 30;
        SMGG::gSpriteClips[6].h = 30;

        // Small button
        SMGG::gSpriteClips[7].x = 480;
        SMGG::gSpriteClips[7].y = 0;
        SMGG::gSpriteClips[7].w = 45;
        SMGG::gSpriteClips[7].h = 45;
    }                      

    SMGG::gFont = TTF_OpenFont("graphics/Orbi.ttf", 24);
    if (SMGG::gFont == NULL)
    {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        success = false;
    }


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