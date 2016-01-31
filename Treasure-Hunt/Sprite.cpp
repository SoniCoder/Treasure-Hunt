#include "Sprite.h"
#include "Phoenix.h"


Sprite::Sprite(char* location)
{
	visible = true;

	texture = IMG_LoadTexture(Phoenix::Phoenix_Instance.renderer, location);
	SDL_QueryTexture(texture, NULL, NULL, &origWidth, &origHeight);
	
	origAR = (float)origWidth / origHeight;
	dispRect.x = 0;
	dispRect.y = 0;
	dispRect.w = origWidth;
	dispRect.h = origHeight;
}

Sprite::~Sprite()
{
}

bool Sprite::isVisible()
{
	return visible;
}

void Sprite::Draw()
{
	SDL_RenderCopy(Phoenix::Phoenix_Instance.renderer, texture, NULL, &dispRect);
}

void Sprite::setCoords(float x, float y)
{
	dispRect.x = (int)(x*Phoenix::Phoenix_Instance.dispInst.width);
	dispRect.y = (int)(y*Phoenix::Phoenix_Instance.dispInst.height);
}

void Sprite::setWidth(float width)
{
	dispRect.w = (int)(width*Phoenix::Phoenix_Instance.dispInst.width);
	dispRect.h = (int)(dispRect.w/origAR);
}

void Sprite::setHeight(float height)
{
	dispRect.h = (int)(height*Phoenix::Phoenix_Instance.dispInst.height);
	dispRect.w = (int)(origAR*dispRect.h);
}


