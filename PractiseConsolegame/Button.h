#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include<iostream>
class Button
{
	sf::RectangleShape buttonDisplay;
	sf::Text text;
	sf::Texture btnTexture;
	sf::Sprite btnSprite;
public:
	Button();
	Button(float xPos, float yPos, float width, float height, sf::Color color, sf::Font &font, sf::Texture &tex);
	sf::Sprite getDisplay();
	sf::Vector2f centerTextPos();
	sf::Color originalColor;
	
	sf::Text getText();
	void handleHover(sf::Vector2f mousePos);
};

