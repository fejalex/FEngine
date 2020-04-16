// File that contains sprite's class
#include "Sprite.h"

/// Default constructor
///////////////////////
Sprite::Sprite()
{
	textureFilePath = "";

	size.x = 0;
	size.y = 0;

	scale.x = 1;
	scale.y = 1;
}
/// Constructor for creating simple Sprite
//////////////////////////////////////////
Sprite::Sprite(const std::string texture_path)
{
	textureFilePath = Default_Textures_Path + texture_path + Default_Textures_File_Format;
	textureImage.loadFromFile(textureFilePath);
	texture.loadFromImage(textureImage);
	sprite.setTexture(texture);

	sf::Vector2u textureSize =  texture.getSize();
	size.x = (float)textureSize.x;
	size.y = (float)textureSize.y;

	scale.x = 1;
	scale.y = 1;
}

/// Destructor
//////////////
Sprite::~Sprite()
{

}

/// Function that draws sprite on window
////////////////////////////////////////
void Sprite::Draw()
{
	if (textureFilePath != "")
	{
		window.draw(sprite);
	}
}

/// Function to set new texture for sprite
//////////////////////////////////////////
void Sprite::SetTexture(const std::string texture_path)
{
	textureFilePath = Default_Textures_Path + texture_path + Default_Textures_File_Format;
	textureImage.loadFromFile(textureFilePath);
	texture.loadFromImage(textureImage);
	sprite.setTexture(texture);

	sf::Vector2u newTextureSize = texture.getSize();
	sprite.setTextureRect(sf::IntRect(0, 0, newTextureSize.x, newTextureSize.y));

	Sprite::SetScale(scale);
	this->size = sf::Vector2f((float)newTextureSize.x, (float)newTextureSize.y);
}
/// Function that allows to change sprite's size
////////////////////////////////////////////////
void Sprite::SetSize(sf::Vector2f size)
{
	sf::Vector2u textureSize = texture.getSize();
	sprite.setScale(size.x / textureSize.x, size.y / textureSize.y);
	this->size = size;
}
/// Function that allows to change sprite's size
////////////////////////////////////////////////
void Sprite::SetSize(float width, float height)
{
	Sprite::SetSize(sf::Vector2f(width, height));
}
/// Function that allows to change sprite's size by scale
///
/// Vector2f(0.5, 0.5) means that sprite will have 50% of width and height of one's default size
////////////////////////////////////////////////////////////////////////////////////////////////
void Sprite::SetScale(const sf::Vector2f scale)
{
	sf::Vector2u textureSize = texture.getSize();
	sf::Vector2f spriteScale(size.x / textureSize.x, size.y / textureSize.y);
	sprite.setScale(sf::Vector2f(spriteScale.x * scale.x, spriteScale.y * scale.y));

	this->scale.x = scale.x;
	this->scale.y = scale.y;
}
/// Function that allows to change sprite's size by scale
///
/// scaleX = 0.5, scaleY = 0.5 means that sprite will have 50% of width and height of one's default size
////////////////////////////////////////////////////////////////////////////////////////////////////////
void Sprite::SetScale(const float scaleX, const float scaleY)
{
	Sprite::SetScale(sf::Vector2f(scaleX, scaleY));
}
/// Function that allows to change sprite's position
////////////////////////////////////////////////
void Sprite::SetPosition(const sf::Vector2f position)
{
	sprite.setPosition(position);
}
/// Function that allows to change sprite's position
////////////////////////////////////////////////
void Sprite::SetPosition(const float positionX, const float positionY)
{
	Sprite::SetPosition(sf::Vector2f(positionX, positionY));
}
/// Function for setting origin point of sprite
///////////////////////////////////////////////
void Sprite::SetOrigin(const sf::Vector2f origin)
{
	Sprite::SetOrigin(origin.x, origin.y);
}
/// Function for setting origin point of sprite
///////////////////////////////////////////////
void Sprite::SetOrigin(const float positionX, const float positionY)
{
	sf::Vector2u textureSize = texture.getSize();
	sf::Vector2f spriteScale(size.x / textureSize.x, size.y / textureSize.y);
	sprite.setOrigin(sf::Vector2f(positionX / spriteScale.x, positionY / spriteScale.y));

	origin.x = positionX;
	origin.y = positionY;
}
/// | Function for setting origin point of sprite
///
/// | percentX - parametr to set origin X position in sprite size's percent (0u is left side and 100u is right side)
/// | percentY - parametr to set origin Y position in sprite size's percent (0u is top side and 100u is bottom side)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Sprite::SetOriginPercent(const unsigned int percentX, const unsigned int percentY)
{
	Sprite::SetOrigin(size.x * ((float)percentX / 100), size.y * ((float)percentY / 100));
}
/// Function to get sprite texture's path
/////////////////////////////////////////
std::string Sprite::GetTexturePath()
{
	return textureFilePath;
}
/// Function to get sprite's size
/////////////////////////////////
sf::Vector2f Sprite::GetSize()
{
	return size;
}
/// Function to get sprite's scale
//////////////////////////////////
sf::Vector2f Sprite::GetScale()
{
	return scale;
}
/// Function to get sprite's position
/////////////////////////////////////
sf::Vector2f Sprite::GetPosition()
{
	return sprite.getPosition();
}
/// Function to get sprite's origin point
/////////////////////////////////////////
sf::Vector2f Sprite::GetOrigin()
{
	return origin;
}

/// Function to check if sprite is hovered by mouse cursor
//////////////////////////////////////////////////////////
bool Sprite::isHovered()
{
	sf::Vector2f spritePos = sprite.getPosition();
	sf::FloatRect spriteSize = sprite.getGlobalBounds();
	sf::Vector2f spriteOrigin = sprite.getOrigin();
	sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	bool isWindowFocused = window.hasFocus();

	if (spritePos.x - spriteOrigin.x < mousePos.x &&
		spritePos.x - spriteOrigin.x + spriteSize.width > mousePos.x &&
		spritePos.y - spriteOrigin.y < mousePos.y &&
		spritePos.y - spriteOrigin.y + spriteSize.height > mousePos.y &&
		isWindowFocused)
	{
		return true;
	}
	return false;
}

/// Overloaded == operator for equality check with NULL
///////////////////////////////////////////////////////
bool Sprite::operator == (const int& other)
{
	if (other == NULL)
	{
		return textureFilePath == "";
	}
	return false;
}
/// Overloaded != operator for equality check with NULL
///////////////////////////////////////////////////////
bool Sprite::operator != (const int& other)
{
	if (other == NULL)
	{
		return !(textureFilePath == "");
	}
	return true;
}
/// Overloaded == operator for equality check with NULL
///////////////////////////////////////////////////////
bool Sprite::operator == (const Sprite& other)
{
	return this->textureFilePath == other.textureFilePath;
}
/// Overloaded != operator for equality check with NULL
///////////////////////////////////////////////////////
bool Sprite::operator != (const Sprite& other)
{
	return this->textureFilePath != other.textureFilePath;
}