/*
 * CharacterSystem.cpp
 *
 *  Created on: 2015�~4��26��
 *      Author: Jinyu
 */

#include "CharacterSystem.h"
Character::Character() {
	_characterType = TYPE::PLAYER;
	_characterOrien = 0.0f;
	_characterSpeed = 0.0f;
	_characterLayer = cocos2d::LayerColor::create(Color4B(127, 255, 127, 255), 50, 50);
}
Character::Character(Layer* scene) {
	_characterType = TYPE::PLAYER;
	_characterOrien = 0.0f;
	_characterSpeed = 0.0f;
	_characterLayer = cocos2d::LayerColor::create(Color4B(127, 255, 127, 255), 50, 50);
	scene->addChild(_characterLayer);
}
/*
Character::Character(Scene* scene, int type, Point pos, float ori, float spd) {
	_characterType = type;
	_characterPosition = pos;
	_characterOrien = ori;
	_characterSpeed = spd;
}
*//*
LayerColor* myCharacter() {
	return _characterLayer;
}
Sprite*  myCharacter() {
	return _character;
}
*/
// ���o / �]�w ���⪺��m
void Character::setPosition(Point pos) {
	_characterLayer->setPosition(pos);
}
Point Character::getPosition() {
	return _characterLayer->getPosition();
}

// ���o / �]�w ���⪺��V
void Character::setOrien(float ori) {
	if (ori < 0) {
		ori *= -1;
	}
	if (ori >= 0 || ori <= 360) {
		_characterOrien = ori;
	}
	else {
		while (ori > 360) {
			 ori -= 360;
		}
		_characterOrien = ori;
	}
}
float Character::getOrien() {
	return _characterOrien;
}
// ���o / �]�w ���⪺�t��
void Character::setSpeed(float spd) {
	_characterSpeed = spd;
}
float Character::getSpeed() {
	return _characterSpeed;
}

