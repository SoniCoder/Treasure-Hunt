#include "Layer.h"



Layer::Layer()
{
	visible = true;
	numSprites = 0;
}

Layer::~Layer()
{
}

bool Layer::isVisible()
{
	return visible;
}

void Layer::drawLayer()
{
	for (int i = 0; i < numSprites; i++) {
		if(layerSprites[i]->isVisible())
			layerSprites[i]->Draw();
	}
}

void Layer::loadSprite(char * location, int spriteID)
{
	layerSprites[numSprites++] = new Sprite(location);
}

void Layer::setSpriteCoords(float x, float y, int spriteID)
{
	layerSprites[spriteID]->setCoords(x, y);
}

void Layer::setSpriteWidth(float width, int spriteID)
{
	layerSprites[spriteID]->setWidth(width);
}

void Layer::setSpriteHeight(float height, int spriteID)
{
	layerSprites[spriteID]->setHeight(height);
}
