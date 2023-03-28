#include "Player.h"
Player::Player() {
	//player.setPosition(10.f, 10.f);
	playerIcon.setRadius(16.f);
	mov = 4;
}
Player::Player(int mov) {
	this->mov = mov;
	playerIcon.setRadius(16.f);
}

sf::CircleShape Player::getPlayerIcon()
{
	return playerIcon;
}
//sets physical position on screen
void Player::setDisplayPosition(sf::Vector2f pos) {
	playerIcon.setPosition(pos);
}//sets which tile it's on
void Player::setTile(int index, sf::Vector2f pos) {
	this->occupiedTileIndex = index;
	playerIcon.setPosition(pos);
}
int Player::getTileIndex() {
	return occupiedTileIndex;
}
int Player::getMov() {
	return this->mov;
}
