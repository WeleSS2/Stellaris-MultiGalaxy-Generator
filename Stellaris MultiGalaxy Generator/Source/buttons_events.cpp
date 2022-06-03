void Buttons_Objects::Buttons_Data::handle_Main_Menu_Buttons(SDL_Event& e, int id)
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	bool inside = true;

    if (x < mPosition.x)
    {
        inside = false;
    }
    else if (x > mPosition.x + getWidth())
    {
        inside = false;
    }
    else if (y < mPosition.y)
    {
        inside = false;
    }
    else if (y > mPosition.y + getHeight())
    {
        inside = false;
    }
    if(inside)
    {
        if (e.button.button == SDL_BUTTON_LEFT)
        {

            switch (id)
            {
            case 0:
                SMGG_P::P_Graphics_Engine->set_window_position(10, 2);
                SMGG_P::P_Graphics_Engine->click_effect(0, 0 ,0);
                break;
            case 1:
                SMGG::OpenedWindow.reset(0);
                SMGG::reset_window(10);
                SMGG::Windows_Path.emplace_back();
                SMGG_P::P_Graphics_Engine->set_window_position(20, 0);
                break;

            }

        }
    }
}

void Buttons_Objects::Buttons_Data::handle_Button_Back(SDL_Event& e)
{
    int x, y;
    SDL_GetMouseState(&x, &y);

    bool inside = true;

    if (x < mPosition.x)
    {
        inside = false;
    }
    else if (x > mPosition.x + getWidth())
    {
        inside = false;
    }
    else if (y < mPosition.y)
    {
        inside = false;
    }
    else if (y > mPosition.y + getHeight())
    {
        inside = false;
    }
    if (inside)
    {
        if (e.button.button == SDL_BUTTON_LEFT)
        {
            SMGG_P::P_Graphics_Engine->back_arrow();
        }
    }
}

//0 - Checkbox Show Hyperlanes
//1 - Checkbox Show Initializers
//2 - "Manage Galaxies"
//3 - "Manage Hyperlanes"
//4 - "Manage Initializers"
//5 - Circle / Ring
//6 - Spiral
//7 - Irregular

void Buttons_Objects::Buttons_Data::handle_Menu_Galaxies_Buttons(SDL_Event& e, int id)
{
    int x, y;
    SDL_GetMouseState(&x, &y);

    bool inside = true;

    if (x < mPosition.x)
    {
        inside = false;
    }
    else if (x > mPosition.x + getWidth())
    {
        inside = false;
    }
    else if (y < mPosition.y)
    {
        inside = false;
    }
    else if (y > mPosition.y + getHeight())
    {
        inside = false;
    }
    if (inside)
    {
        if (e.button.button == SDL_BUTTON_LEFT)
        {

            switch (id)
            {
            case 2:
                SMGG_P::P_Graphics_Engine->set_window_position(11, 3);
                break;
            case 3:
                SMGG_P::P_Graphics_Engine->set_window_position(12, 3);
                break;
            case 4:
                SMGG_P::P_Graphics_Engine->set_window_position(13, 3);
                break;

            }

        }
    }
}
