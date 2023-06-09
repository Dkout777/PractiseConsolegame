#include "Game.h"



//private functions
void Game::initVariables()
{
	this->window = nullptr;
	if (!font.loadFromFile("./Fonts/OpenSans-Regular.ttf"))
	{
	}
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
	gameMap = GameMap(10, videoMode.width/4, 20, 20, 50);
}

void Game::initPlayer()
{

	player1 = Player(3);
	player1.setTile(30, gameMap.getTileAt(30).getTilePosition());
	gameMap.assignPlayerToTile(0, 30);
	
	players.push_back(player1);
	player2 = Player(4);
	player2.setTile(55, gameMap.getTileAt(55).getTilePosition());
	gameMap.assignPlayerToTile(1, 55);
	players.push_back(player2);

}

void Game::initUi() {
	if (!endTurnTexture.loadFromFile("./images/EndTurnBtn.png")) {

	}
	endTurnTexture.setSmooth(true);
	endTurnBut = Button(10.f,10.f,0.5f, 0.5f, sf::Color::Red, font, endTurnTexture);
	turnCounter = TurnCounter(500, 500, font);

}
//constructors / destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initGameMap();
	this->initPlayer();
	this->initUi();
}

Game::~Game()
{
	delete this->window;
}


//Functions
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
			if (endTurnBut.getDisplay().getGlobalBounds().contains(mousePosWindow.x, mousePosWindow.y)) {
				this->nextTurn();
				std::cout << turnCount;
			}
			else {
				std::cout << gameMap.getSelectedTilePosition() << "\n";
				// If selected tile has player and it's not currently in a move phase
				if (gameMap.getTileAt(gameMap.getSelectedTilePosition()).hasPlayer() && !playerMovPhase &&
					players.at(gameMap.getTileAt(gameMap.getSelectedTilePosition()).getEntity()).getHasAction()) {

					playerMovPhase = true;
					selectedPlayer = gameMap.getTileAt(gameMap.getSelectedTilePosition()).getEntity();
					gameMap.handlePlayerMovHighlightOn(players.at(selectedPlayer).getMov());

				}
				//If tile doesn't have player, is currently in move phase and the selected tile is not option
				else if (!gameMap.getTileAt(gameMap.getSelectedTilePosition()).hasPlayer() && playerMovPhase && !gameMap.getSelectedTiles().count(gameMap.getSelectedTilePosition())) {
					playerMovPhase = false;
					gameMap.handlePlayerMovHighlightOff();
					selectedPlayer = -1;

				}
				//If tile doesn't have player, is move phase and is a valid tile
				else if (!gameMap.getTileAt(gameMap.getSelectedTilePosition()).hasPlayer() && playerMovPhase && gameMap.getSelectedTiles().count(gameMap.getSelectedTilePosition())) {
					playerMovPhase = false;
					gameMap.handlePlayerMovHighlightOff();
					//tiles.at(players.at(selectedPlayer).getTileIndex()).clearEntity();
					//tiles.at(selectedTilePosition).assignEntity(selectedPlayer);
					gameMap.clearTile(players.at(selectedPlayer).getTileIndex());
					gameMap.assignPlayerToTile(selectedPlayer, gameMap.getSelectedTilePosition());
					players.at(selectedPlayer).setTile(gameMap.getSelectedTilePosition(), gameMap.getTileAt(gameMap.getSelectedTilePosition()).getTilePosition());
					players.at(selectedPlayer).useAction();


				}
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

void Game::updateTiles()
{
	gameMap.handleOutline(mousePosWindow);
}
void Game::updateButtons() {
	endTurnBut.handleHover(sf::Vector2f(mousePosWindow.x, mousePosWindow.y));
}
void Game::update()
{

	this->pollEvents();

	this->updateMousePositions();

	this->updateTiles();
	this->updateButtons();
	

}

void Game::renderMap()
{
	for (Tile tile : gameMap.getTiles()) {
		this->window->draw(tile.getTileDisplay());
	}
}
void Game::renderPlayers() {
	for (Player player : players) {
		this->window->draw(player.getPlayerIcon());
	}
}
void Game::renderUI() {
	this->window->draw(endTurnBut.getDisplay());
	this->window->draw(endTurnBut.getText());
	this->window->draw(turnCounter.getDisplay());
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
	this->renderMap();
	this->renderPlayers();
	this->renderUI();
	this->window->display();
}


const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::nextTurn() {
	turnCounter.incrementCount();
	for (int x = 0; x < players.size(); x++) {
		players.at(x).resetAction();
	}
	
	std::cout << players.at(0).getHasAction();
}





