namespace SMGG {
	SDL_Renderer* gRenderer = NULL;
    SDL_Color SilverTextColor = { 172, 172, 172, 0xFF };
    TTF_Font* gFont = NULL;
    SDL_Rect gSpriteClips[TOTAL_SPRITES];

    struct random_things
    {
        int system_amount{ 0 },
            empires_amount{ 0 },
            fallen_amount{ 0 },
            marauders_amount{ 0 };
    };
    random_things R_T;



	std::bitset<1000> OpenedWindow;

    struct window_coordinates
    {
        int x, y;
    };
    std::vector <window_coordinates> Window_Cord;
    std::deque<std::deque <int>> Windows_Path;
    // 0 - Main Menu
    // 1 - Left map
    // 10 - Galaxies main
    // 20 - Maps main
    // 30 - Settings main
    // 40 - Empty holder
    // 50 - Empty holder
    // 60 - Play & Exit main
    // 
    // 100 - Galaxies
    // 200 - Maps
    // 
    //
    void reset_window(int from)
    {
        for (int i = from; i < 1000; ++i)
        {
            OpenedWindow.reset(i);
        }
    };
};