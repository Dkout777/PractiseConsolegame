#include "GameMap.h"

GameMap::GameMap(int firstTilePosY, int firstTilePosX, int mapWidth, int mapHeight, int tileSize){
	this->firstTilePosY = firstTilePosY;
	this->firstTilePosX = firstTilePosX;
	this->mapWidth = mapWidth;
	this->mapHeight = mapHeight;
	this->tileSize = tileSize;


}
GameMap::GameMap() {
}
void GameMap::initTiles()
{
	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) {
			this->tiles.push_back(Tile(tileSize));
			this->tiles.back().setTilePosition(firstTilePosX + x * tileSize, firstTilePosY + y * tileSize);
			this->tiles.back().setIndex(x + y * mapWidth);
		}

	}


}

Tile GameMap :: getTileAt(int index) {
	return tiles.at(index);
}




std::set<int> GameMap::highlightMovementTiles(int  index, int mov) {
	std::set<int> validTile;
	validTile.insert(index);
	for (int i = 0; i < mov; i++) {
		std::set<int> tempSet;
		for (int testingIndex : validTile) {
			// add right tile	
			if (testingIndex + 1 < mapHeight * mapWidth && (testingIndex + 1) % mapWidth != 0 && !tiles.at(testingIndex + 1).hasPlayer()) {
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
int GameMap::getTile(sf::Vector2i mousePos){
	int xPos = (mousePos.x - firstTilePosX) / tileSize;
	int yPos = (mousePos.y - firstTilePosY) / tileSize;

	return xPos + mapWidth * yPos;
}

