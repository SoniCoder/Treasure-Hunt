#include "Phoenix.h"

Phoenix::Phoenix()
{
}


Phoenix::~Phoenix()
{
}

bool Phoenix::createWindow(int w, int h, bool isWindowed)
{
	mainWindow = SDL_CreateWindow("Treasure Hunt", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN | ((isWindowed)?0:SDL_WINDOW_FULLSCREEN));
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
	while (mainEvent.type != SDL_QUIT){
		SDL_PollEvent(&mainEvent);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
		draw();
	}
}

void Phoenix::setDrawFunction(void(*draw)()) {
	this->draw = draw;
}