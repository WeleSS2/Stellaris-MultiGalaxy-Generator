namespace SMGG {
	SDL_Renderer* gRenderer = NULL;

	std::bitset<32> OpenedWindow;
    // 0 - Nothing Opened
    // 1 - Galaxies 
    // 2 - Map
    // 3 - Settings
    // 4 - NIY Load photo as map
    // 5 - Empty holder
    // 6 - Play & Exit
    // 
    // 10 - Detailed Generation
    //
    // 
    //
    std::bitset<8> SettingsWindow;
    std::bitset<8> DetailedGenerationWindow;

    void reset_window()
    {
        for (int i = 0; i < 32; ++i)
        {
            OpenedWindow.reset(i);
        }
        for (int i = 0; i < 8; ++i)
        {
            SettingsWindow.reset(i);
            DetailedGenerationWindow.reset(i);
        }
    }
};