#pragma once // Code will be executed only one time

#include "Headers.h" // There are all needed libraries in "Headers.h"
#include "Variables.h"

/// Sprite class alows to create and control 2D objects with textures
/////////////////////////////////////////////////////////////////////
class Sprite
{
protected:
	/// Variable that contains SFML image of sprite's texture
	/////////////////////////////////////////////////////////
	sf::Image textureImage;
	/// Variable that contains SFML texture of sprite
	/////////////////////////////////////////////////
	sf::Texture texture;
	/// Variable that contains SFML sprite
	//////////////////////////////////////
	sf::Sprite sprite;

	/// Variable that contains path to texture's image
	//////////////////////////////////////////////////
	std::string textureFilePath;
	/// Variable that contains sprite's size
	////////////////////////////////////////
	sf::Vector2f size;
	/// Variable that contains sprite's scale
	////////////////////////////////////////
	sf::Vector2f scale;
	/// Variable that contains sprite origin's position
	////////////////////////////////////////
	sf::Vector2f origin;
public:
	/// Default constructor
	///////////////////////
	Sprite();
	/// Constructor for creating simple Sprite
	//////////////////////////////////////////
	Sprite(const std::string texture_path);
	/// Destructor
	//////////////
	~Sprite();

	/// Function that draws sprite on window
	////////////////////////////////////////
	void Draw();

	/// Function to set new texture for sprite
	//////////////////////////////////////////
	void SetTexture(const std::string texture_path);
	/// Function that allows to change sprite's size
	////////////////////////////////////////////////
	void SetSize(const sf::Vector2f size);
	/// Function that allows to change sprite's size
	////////////////////////////////////////////////
	void SetSize(const float width, const float height);
	/// Function that allows to change sprite's size by scale
	///
	/// Vector2f(0.5, 0.5) means that sprite will have 50% of width and height of one's default size
	////////////////////////////////////////////////////////////////////////////////////////////////
	void SetScale(const sf::Vector2f scale);
	/// Function that allows to change sprite's size by scale
	///
	/// scaleX = 0.5, scaleY = 0.5 means that sprite will have 50% of width and height of one's default size
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	void SetScale(const float scaleX, const float scaleY);
	/// Function that allows to change sprite's position
	////////////////////////////////////////////////////
	void SetPosition(const sf::Vector2f position);
	/// Function that allows to change sprite's position
	////////////////////////////////////////////////////
	void SetPosition(const float positionX, const float positionY);
	/// Function for setting origin point of sprite
	///////////////////////////////////////////////
	void SetOrigin(const sf::Vector2f origin);
	/// Function for setting origin point of sprite
	///////////////////////////////////////////////
	void SetOrigin(const float positionX, const float positionY);
	/// | Function for setting origin point of sprite
	///
	/// | percentX - parametr to set origin X position in sprite size's percent (0u is left side and 100u is right side)
	/// | percentY - parametr to set origin Y position in sprite size's percent (0u is top side and 100u is bottom side)
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void SetOriginPercent(const unsigned int percentX, const unsigned int percentY);

	/// Function to get sprite texture's path
	/////////////////////////////////////////
	std::string GetTexturePath();
	/// Function to get sprite's size
	/////////////////////////////////
	sf::Vector2f GetSize();
	/// Function to get sprite's scale
	//////////////////////////////////
	sf::Vector2f GetScale();
	/// Function to get sprite's position
	/////////////////////////////////////
	sf::Vector2f GetPosition();
	/// Function to get sprite's origin point
	/////////////////////////////////////////
	sf::Vector2f GetOrigin();

	/// Function to check if sprite is hovered by mouse cursor
	//////////////////////////////////////////////////////////
	bool isHovered();

	/// Overloaded == operator for equality check with NULL
	///////////////////////////////////////////////////////
	bool operator == (const int& other);
	/// Overloaded != operator for equality check with NULL
	///////////////////////////////////////////////////////
	bool operator != (const int& other);
	/// Overloaded == operator for equality check textures of two sprites
	/////////////////////////////////////////////////////////////////////
	bool operator == (const Sprite& other);
	/// Overloaded != operator for equality check textures of two sprites
	/////////////////////////////////////////////////////////////////////
	bool operator != (const Sprite& other);
};