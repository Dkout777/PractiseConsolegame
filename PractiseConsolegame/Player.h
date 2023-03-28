#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
class Player
{
	int mov;
	sf::CircleShape playerIcon;
	int occupiedTileIndex;
	bool usedAction;
public:

	bool hasAction;
	Player();
	Player(int mov);
	sf::CircleShape getPlayerIcon();
	void setDisplayPosition(sf::Vector2f);
	void setTile(int index, sf::Vector2f pos);
	int getTileIndex();
	int getMov();
};

