#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>

class Sprite
{
	bool visible;

	int origWidth;
	int origHeight;
	float origAR;

	SDL_Texture* texture;
	SDL_Rect dispRect;
public:
	Sprite(char* location);
	~Sprite();

	bool isVisible();

	void Draw();
	void setCoords(float x, float y);
	void setWidth(float width);
	void setHeight(float height);
};

#endif