#include "Button.h"



Button::Button(float xPos, float yPos, float width, float height, sf::Color color, sf::Font &font) {
	buttonDisplay.setSize(sf::Vector2f(width, height));
	buttonDisplay.setPosition(xPos, yPos);
	buttonDisplay.setFillColor(color);
	text.setFont(font);
	text.setString("End");
	text.setPosition(xPos * 3, yPos);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::White);
}
Button::Button() {

}
sf::RectangleShape Button::getDisplay() {
	return this->buttonDisplay;
}
sf::Text Button::getText() {
	return this->text;
}