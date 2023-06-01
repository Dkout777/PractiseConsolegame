#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include<iostream>
class TurnCounter
{
public:
	TurnCounter(float xPos, float yPos, sf::Font& font);
	TurnCounter();
	sf::Text counterDisplay;
	int turnCount;
	int getTurnCount();
	void incrementCount();
	sf::Text getDisplay();
	
};
