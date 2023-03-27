#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include<queue>
#include<set>
#include "Player.h"
#include "Tile.h"
#include "GameMap.h"
class Game
{
private:

	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	int firstTilePosY = 100;
	int firstTilePosX = 100;
	int mapWidth = 12;
	int mapHeight = 12;
	int tileSize = 50;
	

	//Mouse positions
	sf::Vector2i mousePosWindow;
	//Game objects
	GameMap gameMap;
	std::vector<Tile> tiles;
	std::vector<Player>players;
	int selectedTilePosition = 0;
	std::set <int> selectedTiles;
	//gameLogic
	Player player1;
	Player player2;
	bool playerMovPhase = false;
	int selectedPlayer = -1;

	//private functions
	void initVariables();
	void initWindow();
	void initGameMap();
	void initTiles();
	void initPlayer();
	int getTile(sf::Vector2i mousePos);
	std::set<int> highlightMovementTiles(int  index, int mov);

public:
	//Constructors / Destructors
	Game();
	virtual ~Game();
	//Accessors 
	const bool running() const;
	//functions
	int getTilePosition(sf::Vector2i mousePos);
	void spawnEnemy();
	void pollEvents();
	void updateMousePositions();
	void updateTiles();
	void update();
	void renderTiles();
	void renderPlayers();
	void render();
};

