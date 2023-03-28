#pragma once
//silencing warning
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include <filesystem>
#include <experimental/filesystem>
#include <iostream>
#include <string>
#include <map>

class Button
{
private:
	sf::CircleShape buttonBackground;
	sf::Sprite buttonInsignia;

	float cooldownMax;
	float cooldown;

	bool isSelected;

	sf::Texture texture;

public:
	Button();
	Button(std::string path, float radius, float x_mov, float y_mov);
	~Button();

	void update();
	void render(sf::RenderTarget& target);

	bool onCooldown();
	bool isButtonSelected();
	sf::FloatRect getBounds();
	void select(bool selected);

	void resetCooldown();
	void move(float x_mov, float y_mov);

};

