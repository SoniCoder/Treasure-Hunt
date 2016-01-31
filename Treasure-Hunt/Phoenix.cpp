#include "Phoenix.h"

Phoenix Phoenix::Phoenix_Instance;

void Phoenix::loadSprite(char * location, int layerID, int spriteID)
{
	assert(layerID < numLayers);
	layers[layerID]->loadSprite(location, spriteID);
}

void Phoenix::setSpriteCoords(float x, float y, int spriteID, int layerID)
{
	layers[layerID]->setSpriteCoords(x, y, spriteID);
}

void Phoenix::setSpriteWidth(float width, int spriteID, int layerID)
{
	layers[layerID]->setSpriteWidth(width, spriteID);
}

void Phoenix::setSpriteHeight(float height, int spriteID, int layerID)
{
	layers[layerID]->setSpriteHeight(height, spriteID);
}

void Phoenix::updateKeyHandler()
{
	if (mainEvent.type == SDL_KEYDOWN)
	{
		keyHndInst.setstate(mainEvent.key.keysym.scancode, SDL_PRESSED);
	}
	if (mainEvent.type == SDL_KEYUP)
	{
		keyHndInst.setstate(mainEvent.key.keysym.scancode, SDL_RELEASED);
	}
}

Phoenix::Phoenix()
{
	numLayers = 1;
	quit = false;
	frameTimer.setTimeOutPeriod(16);

	layers[0] = new Layer();
}


Phoenix::~Phoenix()
{
}

bool Phoenix::createWindow(int w, int h, bool isWindowed)
{
	mainWindow = SDL_CreateWindow("Treasure Hunt", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN | ((isWindowed)?0:SDL_WINDOW_FULLSCREEN));
	dispInst.height = h;
	dispInst.width = w;
	renderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
	return true;
}

bool Phoenix::initialize() {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}
	return true;
}

bool Phoenix::shutdown() {
	Mix_CloseAudio();
	TTF_Quit();
	SDL_Quit();
	return true;
}

void Phoenix::begin() {
	while (!quit && mainEvent.type != SDL_QUIT){
		absTime = SDL_GetTicks();
		if (SDL_PollEvent(&mainEvent) || frameTimer.isTimeOut(absTime)) {
			frameTimer.setTimeOut(absTime);
			SDL_RenderClear(renderer);
			drawLayers();
			SDL_RenderPresent(renderer);
			updateKeyHandler();
			update();
		}
	}
}

void Phoenix::drawLayers()
{
	for (int i = 0; i < numLayers; i++)
	{	
		if(layers[i]->isVisible())
			layers[i]->drawLayer();
	}
}

void Phoenix::setDrawFunction(void(*update)()) {
	this->update = update;
}