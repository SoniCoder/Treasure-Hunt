#include "test.h"

namespace Test_Scene {
	bool initialized = false;
	void executeScene() {
		if (!initialized) {
			initialize();
			initialized = true;
		}
		updateScene();
	}
	void initialize()
	{
		Phoenix::Phoenix_Instance.loadSprite("Data/drawables/marker.png", 0, 0);
		Phoenix::Phoenix_Instance.loadSprite("Data/drawables/glass.png", 0, 1);
		
	}

	void updateScene()
	{
		Phoenix::Phoenix_Instance.setSpriteWidth(0.5, 0, 0);
		Phoenix::Phoenix_Instance.setSpriteWidth(0.2, 1, 0);
		Phoenix::Phoenix_Instance.setSpriteCoords(0.5, 0.5, 1, 0);
	}

}