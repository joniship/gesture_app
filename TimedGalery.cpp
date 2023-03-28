#include "TimedGalery.h"

void TimedGalery::initPaths()
{
	//std::experimental::filesystem = std::filesystem
	std::experimental::filesystem::path initPath = "C:\\Users\\guzst\\Documents\\Visual Studio 2022\\Projects\\gesture_apk\\dependencies\\gesture_poses";
	for (auto const& dirEntry : std::experimental::filesystem::recursive_directory_iterator(initPath))
	{
		if (std::experimental::filesystem::is_regular_file(dirEntry) &&
			dirEntry.path().extension() == ".jpg" ||
			dirEntry.path().extension() == ".jpeg" ||
			dirEntry.path().extension() == ".png"
			)
		{
			this->paths.push_back( dirEntry.path().string() );
		}

	}

}

void TimedGalery::initTexture()
{
	//sprite adjustments


	this->photoTexture.loadFromFile(this->paths[0]);
	this->photo.setTexture(this->photoTexture);
	this->photo.setScale(0.02f, 0.02f);
	this->photo.setScale(1.f,1.f);

}

void TimedGalery::update()
{
}

void TimedGalery::render(sf::RenderTarget& target)
{
	target.draw(this->photo);
}

TimedGalery::TimedGalery()
{
	this->initPaths();
	this->initTexture();
}

TimedGalery::~TimedGalery()
{
}

void TimedGalery::move(float x_mov, float y_mov)
{
}

