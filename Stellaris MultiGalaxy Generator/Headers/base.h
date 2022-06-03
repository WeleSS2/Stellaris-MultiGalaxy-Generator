class setup_app
{
public:
    setup_app()
    {
        SMGG_P::P_Buttons_Objects->build_Buttons_Objects();
    };

    void app_set_screen_width_height(int x, int y);

    bool get_init();

    bool get_loadMedia();

    void app_background();

    void rerender();

    void throw_out_buttons();
};