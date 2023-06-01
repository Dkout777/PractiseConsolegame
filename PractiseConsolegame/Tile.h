#pragma once
#include<iostream>
#include "Entity.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>

class Tile
{
	sf::RectangleShape tileDisplay;	
	int occupiedPlayer = -1;
	bool passable = true;
	int index;
	
public:

	Tile(float size);
	sf::RectangleShape getTileDisplay();
	void setTilePosition(float x, float y);
	void turnOnOutline();
	void turnOffOutline();
	void turnBlue();
	void turnGreen();
	void assignEntity(int player);
	void clearEntity();
	bool hasPlayer();
	void setIndex(int index);
	int getIndex();
	sf::Vector2f getTilePosition();
	int getEntity();
	
	
};

