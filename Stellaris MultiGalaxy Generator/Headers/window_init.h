class Window_Init {
public:
    SDL_Window* gWindow = NULL;

    //Initialize window
    bool init();

    //Window size/Dynamic window sizing
    void set_screen_width_height(int w, int h);
   
    //Setting a center
    void set_center();


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