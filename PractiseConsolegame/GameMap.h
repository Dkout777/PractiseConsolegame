#pragma once
#include "Tile.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include<set>
class GameMap
{
	//Map Properties
	int firstTilePosY = 10;
	int firstTilePosX = 10;
	int mapWidth = 10;
	int mapHeight = 10;
	int tileSize = 50;
	//-------------------
	std::vector<Tile> tiles;
	int selectedTilePosition = 0;
	std::set <int> selectedTiles;

public:
	GameMap(int firstTilePosY, int firstTilePosX, int mapWidth, int mapHeight, int tileSize );
	GameMap();
	void initTiles();
	std::set<int> highlightMovementTiles(int  index, int mov);
	Tile getTileAt(int index);
	int getTileIndex(sf::Vector2i mousePos);
	void handleOutline(sf::Vector2i mousePos);
	void handlePlayerMovHighlightOn(int playerMov);
	void handlePlayerMovHighlightOff();
	std::vector<Tile> getTiles();
	void assignPlayerToTile(int playerIndex, int tileIndex);
	void clearTile(int index);
	int getSelectedTilePosition();
	std::set<int> getSelectedTiles();



};

