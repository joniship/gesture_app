#include "Button.h"

//constructors
Button::Button()
{

}

Button::Button(std::string path, float radius, float x_mov, float y_mov)
{
	isSelected = false;
	this->cooldownMax = 30.f;
	this->cooldown = this->cooldownMax;

	this->buttonBackground.setFillColor(sf::Color::Color(50, 145, 89, 255));
	this->buttonBackground.setOutlineColor(sf::Color::Color(50, 145, 89, 255));
	this->buttonBackground.setRadius(radius);
	this->buttonBackground.setOutlineThickness(radius / 10.f);
	this->buttonBackground.setPosition(x_mov, y_mov);

	this->texture.loadFromFile(path);//.loadFromFile("dependencies/textures/pause.png");
	this->buttonInsignia.setTexture(this->texture);
	this->buttonInsignia.setScale(radius / this->buttonInsignia.getGlobalBounds().width, radius / this->buttonInsignia.getGlobalBounds().height);
	this->buttonInsignia.setPosition(this->buttonBackground.getGlobalBounds().width / 2 + this->buttonBackground.getGlobalBounds().left - this->buttonInsignia.getGlobalBounds().width / 2, this->buttonBackground.getGlobalBounds().height / 2 + this->buttonBackground.getGlobalBounds().top - this->buttonInsignia.getGlobalBounds().height / 2);
	this->buttonBackground.setPosition(x_mov, y_mov);
}

Button::~Button()
{

}

void Button::update()
{
	if(this->cooldown + 0.5f <= this->cooldownMax)
		this->cooldown += 0.5f;

}

void Button::render(sf::RenderTarget& target)
{
	target.draw(this->buttonBackground);
	target.draw(this->buttonInsignia);
}

bool Button::onCooldown()
{
	if (this->cooldown == this->cooldownMax)
	{
		return false;
	}
	return true;
}

bool Button::isButtonSelected()
{
	return this->isSelected;
}

sf::FloatRect Button::getBounds()
{
	return this->buttonBackground.getGlobalBounds();
}

void Button::select(bool selected)
{
	this->isSelected = selected;
}

void Button::resetCooldown()
{
	this->cooldown = 0.0f;
}

void Button::move(float x_mov, float y_mov)
{
	this->buttonBackground.move(x_mov, y_mov);
	this->buttonInsignia.move(x_mov, y_mov);
}

