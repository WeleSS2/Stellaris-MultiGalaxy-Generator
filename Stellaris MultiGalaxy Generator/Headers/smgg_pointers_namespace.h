namespace SMGG_P
{
	auto P_Window_Init = std::make_shared<Window_Init>();
	auto P_LTexture = std::make_shared<LTexture>();
	auto P_Graphics_Engine = std::make_shared<Graphics_Engine>();
	auto P_Buttons_Objects = std::make_shared<Buttons_Objects>();
	auto P_Application_Modules = std::make_shared<Application_Modules>();
	auto app = std::make_shared<setup_app>();
}