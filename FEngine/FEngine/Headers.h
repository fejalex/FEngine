// Code will be executed only one time
#pragma once


/* Including needed libraries */

// Console I/O for debug
#include <iostream>
// For STL-container "vector" (dynamic array)
#include <vector>
// For drawing graphics using SFML
#include <SFML\Graphics.hpp>


/* Creating constants */

// Constant variable that contains screen resolution
const sf::Vector2f ScreenResolution(sf::Vector2f(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height));
// Window we will use for interaction with user
sf::RenderWindow window(sf::VideoMode(ScreenResolution.x / 1.2, ScreenResolution.y / 1.2), "Test");