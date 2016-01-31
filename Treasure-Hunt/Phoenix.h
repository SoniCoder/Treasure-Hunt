#ifndef PHOENIX_H
#define PHOENIX_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "KeyboardHandler.h"
#include "Timer.h"
#include "Layer.h"
#include <iostream>
#include <cassert>

namespace {
	struct DisplayInformation {
		int width;
		int height;
	};
}

class Phoenix
{
	bool quit;
	
	void (*update)();

	Timer frameTimer;
	SDL_Event mainEvent;
	SDL_Window* mainWindow;

	Layer* layers[100];

	Uint32 absTime;
	Uint32 numLayers;
public:
	static Phoenix Phoenix_Instance;
	CKeyboardHandler keyHndInst;

	SDL_Renderer* renderer;

	DisplayInformation dispInst;

	bool createWindow(int w, int h, bool isWindowed);
	bool initialize();
	bool shutdown();

	void begin();
	void drawLayers();
	void setDrawFunction(void (*draw)());

	void loadSprite(char* location, int layerID, int spriteID);
	void setSpriteCoords(float x, float y, int spriteID, int layerID);
	void setSpriteWidth(float width, int spriteID, int layerID);
	void setSpriteHeight(float height, int spriteID, int layerID);
	void updateKeyHandler();

	Phoenix();
	~Phoenix();
};

#endif