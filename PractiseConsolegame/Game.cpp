#include "Game.h"



//private functions
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 1080;
	this->videoMode.width = 1920;
	
	this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Close);
	this->window->setFramerateLimit(244);
}

//Game map setup
void Game::initGameMap() {
	gameMap = GameMap(this->videoMode.width / 2, 10, 10, 10, 50);
}
void Game::initTiles()
{
	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) {
			this->tiles.push_back(Tile(tileSize));
			this->tiles.back().setTilePosition(firstTilePosX + x * tileSize, firstTilePosY + y * tileSize);
			this->tiles.back().setIndex(x + y * mapWidth);
		}
		
	}
	

}
void Game::initPlayer()
{

	player1 = Player(3);
	tiles.at(20).assignEntity(0);
	player1.setTile(20, tiles.at(20).getTilePosition());
	players.push_back(player1);
	player2 = Player();
	player2.setTile(55, tiles.at(55).getTilePosition());
	tiles.at(55).assignEntity(1);
	players.push_back(player2);

}
//constructors / destructors
Game::Game()
{
	this->initVariables();
	this->initGameMap();
	this->initWindow();
	this->initTiles();
	this->initPlayer();
}

Game::~Game()
{
	delete this->window;
}


/*
*Function Used to get tiles that must be Highlighted
*
*
*
*/
std::set<int> Game::highlightMovementTiles(int  index, int mov) {
	std::set<int> validTile;
	validTile.insert(index);
	for (int i = 0; i < mov; i++) {
		std::set<int> tempSet;
		for (int testingIndex : validTile) {
			// add right tile	
			if (testingIndex + 1 < mapHeight*mapWidth && (testingIndex + 1) % mapWidth != 0 && !tiles.at(testingIndex + 1).hasPlayer()) {
				tempSet.insert(testingIndex + 1);
			}
			//add left tile
			if (testingIndex - 1 >= 0 && testingIndex % mapWidth != 0 && !tiles.at(testingIndex - 1).hasPlayer()) {
				tempSet.insert(testingIndex - 1);
			}
			//add Down tile
			if (testingIndex < mapHeight * mapWidth - mapWidth && !tiles.at(testingIndex + mapWidth).hasPlayer()) {
				tempSet.insert(testingIndex + mapWidth);
			}
			//add Up tile
			if (testingIndex >= mapWidth && !tiles.at(testingIndex - mapWidth).hasPlayer()) {
				tempSet.insert(testingIndex - mapWidth);
			}

		}
		validTile.insert(tempSet.begin(), tempSet.end());
	}
	validTile.erase(index);
	return validTile;
}



//Functions

int Game::getTile(sf::Vector2i mousePos) {
	int xPos = (mousePos.x - firstTilePosX) / tileSize;
	int yPos = (mousePos.y - firstTilePosY) / tileSize;

	return xPos + mapWidth * yPos;
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event)) {
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			
			break;
		case sf::Event::MouseButtonPressed:
			// If selected tile has player and it's not currently in a move phase
			if (tiles.at(selectedTilePosition).hasPlayer() && !playerMovPhase) {
				playerMovPhase = true;
				selectedPlayer = tiles.at(selectedTilePosition).getEntity();
				selectedTiles = highlightMovementTiles(selectedTilePosition,players.at(tiles.at(selectedTilePosition).getEntity()).getMov());
				for (int index : selectedTiles) {
					tiles.at(index).turnBlue();
				}
			}
			//If tile doesn't have player, is currently in move phase and the selected tile is not option
			else if (!tiles.at(selectedTilePosition).hasPlayer() && playerMovPhase && !selectedTiles.count(selectedTilePosition))  {
				playerMovPhase = false;
				for (int index : selectedTiles) {
					tiles.at(index).turnGreen();
				}
				selectedTiles.clear();
				selectedPlayer = -1;
				
			}
			//If tile doesn't have player, is move phase and is a valid tile
			else if (!tiles.at(selectedTilePosition).hasPlayer() && playerMovPhase && selectedTiles.count(selectedTilePosition)) {
				playerMovPhase = false;
				for (int index : selectedTiles) {
					tiles.at(index).turnGreen();
				}
				tiles.at(players.at(selectedPlayer).getTileIndex()).clearEntity();
				tiles.at(selectedTilePosition).assignEntity(selectedPlayer);
				players.at(selectedPlayer).setTile(selectedTilePosition, tiles.at(selectedTilePosition).getTilePosition());
				selectedTiles.clear();


			}
			//else if(!)
			break;
		}
		

	}

}

void Game::updateMousePositions()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}


void Game::update()
{

	this->pollEvents();

	this->updateMousePositions();

	this->updateTiles();
	

}
void Game::updateTiles()
{

	int x = getTile(mousePosWindow);
	this->tiles.at(selectedTilePosition).turnOffOutline();
	if (x < mapWidth*mapHeight && x >= 0 && mousePosWindow.x < firstTilePosX + tileSize*mapWidth && mousePosWindow.x > firstTilePosX && mousePosWindow.y >= firstTilePosY)  {
		this->selectedTilePosition = x;
		this->tiles.at(selectedTilePosition).turnOnOutline();
	}
	std::cout <<"mouse on" << x << "\n";
	

}
void Game::renderTiles()
{
	for (Tile tile : tiles) {
		this->window->draw(tile.getTileDisplay());
	}

	
}
void Game::renderPlayers() {
	for (Player player : players) {
		this->window->draw(player.getPlayerIcon());
	}
}
void Game::render()
{
	/*
	* @return void
	* 
	* -clear old frame
	* -render objects
	* -dispplay frame in window
	* Renders the Game objects
	*/
	this->window->clear();
	//Draw Game
	this->renderTiles();
	this->renderPlayers();
	this->window->display();
}


const bool Game::running() const
{
	return this->window->isOpen();
}





