#pragma once
#include "Button.h"
#include "TimedGalery.h"

class App
{
private:
	sf::RenderWindow* window;

	std::map<std::string, Button*> buttons;
	TimedGalery galery;

	//click / click&drag actions
	int mousePosX;
	int mousePosY;


	void initWindow();
	void initButtons();
public:

	App();
	~App();

	void updateInput();
	void updatePollEvents();

	void updateButtons();

	void update();
	void render();

	bool isWindowOpen();
};

