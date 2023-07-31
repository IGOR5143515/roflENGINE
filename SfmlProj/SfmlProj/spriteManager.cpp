#include "spriteManager.h"

spriteManager::spriteManager(std::string ref,
	Vector2f scale,
	Vector2f position):ofstrX("testX.txt"),ofstrY("testY.txt"){

	texture.loadFromFile(ref);
	sprite.setTexture(texture);
	sprite.setScale(scale);
	sprite.setOrigin(500, 500);
	sprite.setPosition(position);
	
	
	
}

sf::Sprite spriteManager::getSprite() {
	return sprite;
}
