Buttons_Objects::Buttons_Data::Buttons_Data()
{
    mPosition.x = -1000;
    mPosition.y = -1000;
}

void Buttons_Objects::Buttons_Data::setWidth(double value)
{
    B_width = value;
}

void Buttons_Objects::Buttons_Data::setHeight(double value)
{
    B_height = value;
}

double Buttons_Objects::Buttons_Data::getWidth()
{
    return B_width;
}

double Buttons_Objects::Buttons_Data::getHeight()
{
    return B_height;
}

void Buttons_Objects::Buttons_Data::setPosition(int x, int y)
{
    mPosition.x = SMGG_P::P_Window_Init->get_center_width() + x;
    mPosition.y = SMGG_P::P_Window_Init->get_center_height() + y;
    //std::cout << "Button setted on " << mPosition.x << " " << mPosition.y << "\n";
};

void Buttons_Objects::Buttons_Data::render_button_dynamic(int button_class, int mode, int button_id, int button_x, int button_y, int button_id_2, int width, int height, std::string tekst, int text_x, int text_y, int center)
{
    if (button_class == -1)
    {
        SMGG_P::P_Buttons_Objects->Button_Back.setPosition(button_x, button_y);
        SMGG_P::P_Buttons_Objects->Button_Back.setWidth(width);
        SMGG_P::P_Buttons_Objects->Button_Back.setHeight(height);
        SMGG_P::P_Buttons_Objects->Button_Back.renderDynamic(0, width, height);
    }
    else if (button_class == 0)
    {
        SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[button_id].setPosition(button_x, button_y);
        SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[button_id].setWidth(width);
        SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[button_id].setHeight(height);        

        if (tekst != "")
        {
            SMGG_P::P_Graphics_Engine->gPromptTextTexture.loadFromRenderedText(tekst, SMGG::SilverTextColor);
        }
        SDL_Rect temp = SMGG_P::P_Graphics_Engine->gPromptTextTexture.text_return_w_h(0, 0);

        switch (mode)
        {
        case 0:
            SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[button_id].renderDynamic(0, width, height);
            break;

        case 1:

            break;

        case 2:
            if (tekst != "")
            {
                SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[button_id].setPosition(button_x - 4, button_y);
                SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[button_id].renderDynamic(2, temp.w + 20, temp.h + 6);
                SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[button_id].setWidth(temp.w + 20);
                SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[button_id].setHeight(temp.h + 6);
            }
            break;

        case 3:
            SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[button_id].setPosition(button_x + temp.w, button_y);
            break;

        case 4:
            SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[button_id].setPosition(button_x + temp.w + 5, button_y);
            SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[button_id].renderDynamic(0, width, height);
            break;
        }
        if (center != -10)
        {
            SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[button_id].mPosition.x = SMGG_P::P_Window_Init->get_center_width() + center - (SMGG_P::P_Buttons_Objects->Main_Menu_Buttons[button_id].B_width / 2);
        }
    }
    else if (button_class == 1)
    {
        SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[button_id].setPosition(button_x, button_y);
        SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[button_id].setWidth(width);
        SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[button_id].setHeight(height);
        if (tekst != "")
        {
            SMGG_P::P_Graphics_Engine->gPromptTextTexture.loadFromRenderedText(tekst, SMGG::SilverTextColor);
        }
        SDL_Rect temp = SMGG_P::P_Graphics_Engine->gPromptTextTexture.text_return_w_h(0, 0);

        if (center != -10)
        {
            SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[button_id].mPosition.x = SMGG_P::P_Window_Init->get_center_width() + center - (B_width / 2);

        }

        switch (mode)
        {
        case 0:
            SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[button_id].renderDynamic(0, width, height);
            break;

        case 1:

            break;

        case 2:
            if (tekst != "")
            {
                SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[button_id].setPosition(mPosition.x - 4, button_y);
                SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[button_id].renderDynamic(2, temp.w + 20, temp.h + 6);
                SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[button_id].setWidth(temp.w + 20);
                SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[button_id].setHeight(temp.h + 6);
            }
            break;

        case 3:
            SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[button_id].setPosition(mPosition.x + temp.w, button_y);
            break;

        case 4:
            SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[button_id].setPosition(mPosition.x + temp.w + 5, button_y);
            SMGG_P::P_Buttons_Objects->Menu_Galaxies_Buttons[button_id].renderDynamic(0, width, height);
            break;
        }
    }
    if (tekst != "")
    {
        SMGG_P::P_Graphics_Engine->text_render(tekst, text_x, text_y);
    }
}

void Buttons_Objects::Buttons_Data::renderDynamic(int mode, int w, int h)
{
    switch (mode)
    {
    case 0:
        SMGG_P::P_Graphics_Engine->gButtonSpriteSheetTexture.renderButtonDynamicSize(mPosition.x, mPosition.y, w, h, &SMGG::gSpriteClips[mCurrentSprite]);
        break;
    case 2:
        SMGG_P::P_Graphics_Engine->gButtonSpriteSheetTexture.renderButtonDynamicSize(mPosition.x - 6, mPosition.y - 2, w, h, &SMGG::gSpriteClips[mCurrentSprite]);
        break;
    }
};

void Buttons_Objects::build_Buttons_Objects()
{
    // Create buttons holders

    for (int i = 0; i < 11; ++i)
    {
        Main_Menu_Buttons.emplace_back();
    }
    for (int i = 0; i < 50; ++i)
    {
        Menu_Galaxies_Buttons.emplace_back();
    }
    for (int i = 0; i < 50; ++i)
    {
        Menu_Map_Buttons.emplace_back();
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