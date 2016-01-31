#ifndef LAYER_H
#define LAYER_H
#include "Sprite.h"
class Layer
{
	unsigned int numSprites;

	bool visible;

public:
	Sprite* layerSprites[100];

	Layer();
	~Layer();

	bool isVisible();

	void drawLayer();
	void loadSprite(char * location, int spriteID);
	void setSpriteCoords(float x, float y, int spriteID);
	void setSpriteWidth(float width, int spriteID);
	void setSpriteHeight(float height, int spriteID);

};

#endif