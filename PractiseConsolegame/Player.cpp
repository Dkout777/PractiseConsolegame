#include "Player.h"
Player::Player() {
	//player.setPosition(10.f, 10.f);
	playerIcon.setRadius(25.f);
	mov = 4;
}
Player::Player(int mov) {
	this->mov = mov;
	playerIcon.setRadius(25.f);
}

sf::CircleShape Player::getPlayerIcon()
{
	return playerIcon;
}
void Player::setDisplayPosition(sf::Vector2f pos) {
	playerIcon.setPosition(pos);
}
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
