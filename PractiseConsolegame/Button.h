#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include<iostream>
class Button
{
	sf::RectangleShape buttonDisplay;
	sf::Text text;
	
public:
	Button();
	Button(float xPos, float yPos, float width, float height, sf::Color color, sf::Font &font);
	sf::RectangleShape getDisplay();
	sf::Text getText();
};

