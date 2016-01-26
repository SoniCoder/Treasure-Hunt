#ifndef PHOENIX_H
#define PHOENIX_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

class Phoenix
{
	void (*draw)();

	Uint32 absTime;

	SDL_Event mainEvent;
	SDL_Renderer* renderer;
	SDL_Window* mainWindow;
public:
	bool createWindow(int w, int h, bool isWindowed);
	bool initialize();
	bool shutdown();

	void begin();
	void setDrawFunction(void (*draw)());
	Phoenix();
	~Phoenix();
};

#endif