#include "Headers.h" // There are all needed libraries in "Headers.h"

/// Constant variable that contains screen resolution
/////////////////////////////////////////////////////
const sf::Vector2f ScreenResolution(sf::Vector2f(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height));
/// Window we will use for interaction with user
////////////////////////////////////////////////
sf::RenderWindow window(sf::VideoMode(ScreenResolution.x / 1.2, ScreenResolution.y / 1.2), "Test");

/// Default path to textures' image
/// Images loading from [Default_Textures_Path + "path/to/texture" + Default_Textures_File_Format]
/// 
/// You can change this variable everywhere of your code using
/// extern std::string Default_Textures_Path = L"default/path";
////////////////////////////////////////////////////////////////
std::string Default_Textures_Path = "Textures/";
/// Default textures' image file format
/// Images loading from [Default_Textures_Path + "path/to/texture" + Default_Textures_File_Format]
///
/// You can change this variable everywhere of your code using
/// extern std::string Default_Textures_File_Format = L".format";
//////////////////////////////////////////////////////////////////
std::string Default_Textures_File_Format = ".png";