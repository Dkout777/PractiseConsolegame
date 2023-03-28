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


	

	//Mouse positions
	sf::Vector2i mousePosWindow;
	//Game objects
	GameMap gameMap;
	std::vector<Player>players;
	int selectedTilePosition = 0;
	//gameLogic
	Player player1;
	Player player2;
	bool playerMovPhase = false;
	int selectedPlayer = -1;

	//private functions
	void initVariables();
	void initWindow();
	void initGameMap();
	void initPlayer();

public:
	//Constructors / Destructors
	Game();
	virtual ~Game();
	//Accessors 
	const bool running() const;
	//functions
	void pollEvents();
	void updateMousePositions();
	void updateTiles();
	void update();
	void renderMap();
	void renderPlayers();
	void render();

};

