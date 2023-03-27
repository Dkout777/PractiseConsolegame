#include "Tile.h"
#include<iostream>

Tile::Tile(float size) {
	tileDisplay.setSize(sf::Vector2f(size, size));
	tileDisplay.setFillColor(sf::Color::Green);
	tileDisplay.setOutlineColor(sf::Color::Red);
	tileDisplay.setOutlineThickness(0.f);
}
void Tile::setTilePosition(float x, float y) {
	tileDisplay.setPosition(x, y);
}
sf::RectangleShape Tile::getTileDisplay() {
	return tileDisplay;
}

// Modifing tile display----------
void Tile::turnOnOutline() {
	tileDisplay.setOutlineThickness(-1.f);
}
void Tile::turnOffOutline() {
	tileDisplay.setOutlineThickness(0.f);
}
void Tile::turnBlue() {
	tileDisplay.setFillColor(sf::Color::Blue);
}
void Tile::turnGreen() {
	tileDisplay.setFillColor(sf::Color::Green);
}
//-------------------------------------
void Tile::assignEntity(int player) {
	this->occupiedPlayer = player;
	this->passable = false;
}
void Tile::clearEntity() {
	this->passable = true;
	occupiedPlayer = -1;
}
bool Tile::hasPlayer() {
	if (occupiedPlayer != -1) {
		return true;
	}
	else {
		return false;
	}
}
void Tile::setIndex(int index) {
	this->index = index;
}
int Tile::getIndex() {
	return index;
}
sf::Vector2f Tile::getTilePosition() {
	return tileDisplay.getPosition();
}
int Tile::getEntity() {
	return occupiedPlayer;
}