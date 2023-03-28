#include "App.h"
//init functions

void App::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1200, 800), "gesture_apk", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	this->window->setFramerateLimit(90);
	this->window->setVerticalSyncEnabled(false);
}

void App::initButtons()
{
	this->buttons["PAUSE"] = new Button("dependencies/textures/pause.png", 20.f, 100.f, 100.f);
	this->buttons["SKIP"] = new Button("dependencies/textures/skip.png", 20.f, 10.f, 10.f);
	this->buttons["PREVIOUS"] = new Button("dependencies/textures/previous.png", 20.f, 200.f, 200.f);

}

//construcotor / destructor
App::App()
{
	this->initWindow();
	this->initButtons();
}

App::~App()
{
	delete this->window;

	for (auto& i : this->buttons)
	{
		delete i.second;
	}
}

//update
void App::updateInput()
{
	/*for (auto& i : this->buttons)
	{
		if (i.second->isButtonSelected())
		{
			i.second->move(sf::Mouse::getPosition(*this->window).x - this->mousePosX,
				sf::Mouse::getPosition(*this->window).y - this->mousePosY);

			this->mousePosX = sf::Mouse::getPosition(*this->window).x;
			this->mousePosY = sf::Mouse::getPosition(*this->window).y;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) &&
			i.second->getBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*this->window))) &&
			!i.second->onCooldown())
		{
			i.second->resetCooldown();
			std::cout << i.second->isButtonSelected() << std::endl;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) &&
			i.second->getBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*this->window))))
		{
			if (i.second->isButtonSelected())
			{
				i.second->select(false);
			}
			else
			{
				i.second->select(true);
				this->mousePosX = sf::Mouse::getPosition(*this->window).x;
				this->mousePosY = sf::Mouse::getPosition(*this->window).y;
			}
		}
	}
	*/
	if (buttons["PAUSE"]->isButtonSelected())
	{
		this->buttons["PAUSE"]->move(sf::Mouse::getPosition(*this->window).x - this->mousePosX,
									sf::Mouse::getPosition(*this->window).y - this->mousePosY);

		this->mousePosX = sf::Mouse::getPosition(*this->window).x;
		this->mousePosY = sf::Mouse::getPosition(*this->window).y;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) &&
		buttons["PAUSE"]->getBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*this->window))) &&
		!buttons["PAUSE"]->onCooldown())
	{
		buttons["PAUSE"]->resetCooldown();
		std::cout << buttons["PAUSE"]->isButtonSelected() << std::endl;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) &&
		buttons["PAUSE"]->getBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*this->window))))
	{
		if (buttons["PAUSE"]->isButtonSelected())
		{
			buttons["PAUSE"]->select(false);
		}
		else
		{
			buttons["PAUSE"]->select(true);
			this->mousePosX = sf::Mouse::getPosition(*this->window).x;
			this->mousePosY = sf::Mouse::getPosition(*this->window).y;
		}
	}
}

void App::updatePollEvents()
{
	sf::Event e;
	while(this->window->pollEvent(e))
	{
		//exit & resizing
		if (e.Event::type == sf::Event::Resized)
		{
			// update the view to the new size of the window
			sf::FloatRect visibleArea(0.f, 0.f, e.size.width, e.size.height);
			this->window->setView(sf::View(visibleArea));
		}
		if (e.Event::type == sf::Event::Closed)
		{
			this->window->close();
		}
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
		{
			this->window->close();
		}
	}
}

void App::updateButtons()
{
	for (auto i : this->buttons)
	{
		i.second->update();
	}
}

//update - render
void App::update()
{
	this->updateInput();
	this->updatePollEvents();

	this->updateButtons();
	this->galery.update();
}

void App::render()
{
	this->window->clear();

	//something
	this->galery.render(*this->window);

	for (auto& i : this->buttons)
	{
		i.second->render(*this->window);
	}
	this->window->display();
	
}

//getters setters
bool App::isWindowOpen()
{
	return this->window->isOpen();
}
