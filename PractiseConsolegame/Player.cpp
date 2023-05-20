#include "Player.h"
Player::Player() {
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
void Player::useAction() {
	hasAction = false;
}
void Player::resetAction() {
	hasAction = true;
}

bool Player::getHasAction() {
	return hasAction;
};
