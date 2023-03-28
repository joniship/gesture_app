#pragma once
#include "Button.h"


class TimedGalery
{
private:
	std::vector<std::string> paths;

	sf::Sprite photo;
	sf::Texture photoTexture;

	int currentImg;// este neinicializovane
	
	bool isSelected;// este neinicializovane

	void initPaths();
	void initTexture();
public:
	TimedGalery();
	~TimedGalery();

	void move(float x_mov, float y_mov);

	void update();
	void render(sf::RenderTarget& target);
};

