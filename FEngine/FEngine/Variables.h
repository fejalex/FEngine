// Code will be executed only one time
#pragma once


#include "Headers.h"// There are all needed libraries in "Headers.h"


/* Creating constants */

/// | Constant variable that contains screen resolution
/////////////////////////////////////////////////////
extern const sf::Vector2f ScreenResolution;
/// | Window we will use for interaction with user
////////////////////////////////////////////////
extern sf::RenderWindow window;

/// | Default path to textures' image
/// | Images loading from [Default_Textures_Path + "path/to/texture" + Default_Textures_File_Format]
/// | 
/// | You can change this variable using
/// | Default_Textures_Path = L"default/path";
////////////////////////////////////////////////////////////////
extern std::string Default_Textures_Path;
/// | Default textures' image file format
/// | Images loading from [Default_Textures_Path + "path/to/texture" + Default_Textures_File_Format]
/// |
/// | You can change this variable using
/// | Default_Textures_File_Format = L".format";
//////////////////////////////////////////////////////////////////
extern std::string Default_Textures_File_Format;