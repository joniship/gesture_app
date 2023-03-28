#include "App.h"
#include <time.h>

int main() {

	App gestureApp;

	while (gestureApp.isWindowOpen())
	{
		gestureApp.update();

		gestureApp.render();
	}

	return 0;
}