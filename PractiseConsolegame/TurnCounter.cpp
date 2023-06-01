#include "TurnCounter.h"

TurnCounter::TurnCounter(float xPos, float yPos, sf::Font& font) {
	turnCount = 1;
	counterDisplay.setFont(font);
	counterDisplay.setString("Turn: " + std::to_string(turnCount));
	counterDisplay.setPosition(xPos * 3, yPos);
	counterDisplay.setCharacterSize(40);
	counterDisplay.setFillColor(sf::Color::White);
}
TurnCounter::TurnCounter() {

}

int TurnCounter::getTurnCount() {
	return turnCount;
}
void TurnCounter::incrementCount() {
	turnCount++;
	counterDisplay.setString("Turn: " + std::to_string(turnCount));
}
sf::Text TurnCounter::getDisplay() {
	return counterDisplay;
}