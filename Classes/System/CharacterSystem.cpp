/*
 * CharacterSystem.cpp
 *
 *  Created on: 2015年4月26日
 *      Author: Jinyu
 */

#include "CharacterSystem.h"
Character::Character() {
	_characterType = TYPE::PLAYER;
	_characterOrien = 0.0f;
	_characterSpeed = 0.0f;
	_characterLayer = cocos2d::LayerColor::create();
}
Character::Character(Layer* scene) {
	_characterType = TYPE::PLAYER;
	_characterOrien = 0.0f;
	_characterSpeed = 100.0f;
	_characterLayer = cocos2d::LayerColor::create(Color4B(127, 255, 127, 255), 50, 50);
	char n[7];
	sprintf(n, "%3.2f",_characterOrien);
	_characterLabel = cocos2d::Label::createWithTTF(n, "fonts/Marker Felt.ttf", 50, _characterLayer->getContentSize(), cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	_characterLabel->setTextColor(Color4B::BLACK);
	_characterLayer->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	_characterNode = DrawNode::create();
	_characterLayer->addChild(_characterLabel, 10);
	_characterLayer->addChild(_characterNode, 9);

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
void Character::showLine() {
	float theta = _characterOrien / 180 * PI;
	Point tmp = Point(_characterLayer->getContentSize().width * 0.5, _characterLayer->getContentSize().height * 0.5);
	Point tar = Point(tmp.x + _characterSpeed * cos(theta), tmp.y + _characterSpeed * sin(theta));
	//_characterNode->drawLine(tmp, tar, Color4F::WHITE);
	_characterNode->clear();
	_characterNode->drawSegment(tmp, tar, 3, Color4F(1, 1, 1, 1));
}
// 取得 / 設定 角色的位置
void Character::setPosition(Point pos) {
	_characterLayer->setPosition(pos);
}
Point Character::getPosition() {
	return _characterLayer->getPosition();
}

// 取得 / 設定 角色的方向
void Character::setOrien(float ori) {
	_characterOrien = ori;
	char n[7];
	sprintf(n, "%3.2f",_characterOrien);
	_characterLabel->setString(n);
}
float Character::getOrien() {
	return _characterOrien;
}
// 取得 / 設定 角色的速度
void Character::setSpeed(float spd) {
	_characterSpeed = spd;
}
float Character::getSpeed() {
	return _characterSpeed;
}

