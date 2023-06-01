#include "Button.h"



Button::Button(float xPos, float yPos, float width, float height, sf::Color color, sf::Font &font, sf::Texture &tex) {
	if (!btnTexture.loadFromFile("./images/EndTurnBtn.png")) {
	
	}
	btnSprite.setTexture(tex);
	btnSprite.setScale(sf::Vector2f(width, height));
	btnSprite.setPosition(xPos, yPos);
	originalColor = btnSprite.getColor();
	//buttonDisplay.setSize(sf::Vector2f(width, height));
	//buttonDisplay.setPosition(xPos, yPos);
	//buttonDisplay.setFillColor(color);
//	text.setFont(font);
	//text.setString("End");
	//sf::Vector2f textPos = this->centerTextPos();
	//text.setPosition(textPos);
	//text.setCharacterSize(40);
	//text.setFillColor(sf::Color::White);
}
Button::Button() {

}
sf::Vector2f Button::centerTextPos() {
	const sf::FloatRect bounds(text.getLocalBounds());
	const sf::Vector2f box(buttonDisplay.getSize());
	text.setOrigin((bounds.width - box.x) / 2 + bounds.left, (bounds.height - box.y) / 2 + bounds.top);

	float posX = buttonDisplay.getPosition().x + (buttonDisplay.getGlobalBounds().width - text.getGlobalBounds().width)/2.f;
	float posY = buttonDisplay.getPosition().y - (buttonDisplay.getGlobalBounds().height - text.getLocalBounds().height)/2.f;	
	return sf::Vector2f(posX, posY);
}
sf::Sprite Button::getDisplay() {
	return this->btnSprite;
}
sf::Text Button::getText() {
	return this->text;
}
void Button::handleHover(sf::Vector2f mousePos) {
	if (btnSprite.getGlobalBounds().contains(mousePos)) {
		btnSprite.setColor(sf::Color(originalColor - sf::Color(0,0,0,100)));
	}
	else {
		btnSprite.setColor(originalColor);
	}
}
