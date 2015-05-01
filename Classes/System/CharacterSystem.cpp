/*
 * CharacterSystem.cpp
 *
 *  Created on: 2015年4月26日
 *      Author: Jinyu
 */

#include "CharacterSystem.h"
Character::Character() {
	_cType = CHAR_TYPE::PLAYER;
	_cOrien = 0.0f;
	_cSpeed = 0.0f;
	_cLayer = cocos2d::LayerColor::create();
}
Character::Character(Layer* scene) {
	_cType = CHAR_TYPE::PLAYER;
	_cOrienType = ORIEN_TYPE::ORIEN_VECTOR;
	_cDimType = DIM_TYPE::ONLY_X;
	_cOrien = 0.0f;
	_cSpeed = 0.0f;
	_cMaxSpeed = 300.0f;
	_cAccSpeed = 10 * _cMaxSpeed;
	_cDecSpeed = 2 * _cMaxSpeed;
	_cTunSpeed = 30;
	_cLayer = cocos2d::LayerColor::create(Color4B(127, 255, 127, 255), 50, 50);
	char n[7];
	sprintf(n, "%3.2f",_cOrien);
	_cLabel = cocos2d::Label::createWithTTF(n, "fonts/Marker Felt.ttf", 50, _cLayer->getContentSize(), cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	_cLabel->setTextColor(Color4B::BLACK);
	_cLayer->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	_cNode = DrawNode::create();
	_cLayer->addChild(_cLabel, 10);
	_cLayer->addChild(_cNode, 9);

	scene->addChild(_cLayer);
}

Character::Character(Layer* scene, int type, Point pos, float ori, float spd, float max, float acc, float dec, Sprite* spr) {
	_cType = type;
	_cOrien = ori;
	_cSpeed = spd;
	_cMaxSpeed = max;
	_cAccSpeed = acc;
	_cDecSpeed = dec;
	_cSprite = spr;
	_cSprite->setPosition(pos);
	_cSprite->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	scene->addChild(_cSprite);
}
/*
Character::Character(Scene* scene, int type, Point pos, float ori, float spd) {
	_cType = type;
	_cPosition = pos;
	_cOrien = ori;
	_cSpeed = spd;
}
*//*
LayerColor* myCharacter() {
	return _cLayer;
}
Sprite*  myCharacter() {
	return _c;
}
*/
void Character::showLine() {

	Point tmp = Point(_cLayer->getContentSize().width * 0.5, _cLayer->getContentSize().height * 0.5);
	Point tar = Point(tmp.x + _cSpeed * cos(_cOrien), tmp.y + _cSpeed * sin(_cOrien));
	//_cNode->drawLine(tmp, tar, Color4F::WHITE);
	_cNode->clear();
	_cNode->drawSegment(tmp, tar, 3, Color4F(1, 1, 1, 1));
}
// 取得 / 設定 角色的位置
void Character::setPosition(Point pos) {
	_cLayer->setPosition(pos);
}
Point Character::getPosition() {
	return _cLayer->getPosition();
}

// 取得 / 設定 角色的方向
void Character::setOrien(Point ori) {
	setOrien(ori, _cOrienType);
}
void Character::setOrien(Point ori, int type) {
	float newori = (ori.x > 0)? (ori.y > 0)? atan(ori.y / ori.x) : 2 * PI + atan(ori.y / ori.x) : atan(ori.y / ori.x) + PI;

	if (type == ORIEN_VECTOR && _cOrien >  0) {
		float acc = _cMaxSpeed / 100 * _cTunSpeed;
		Point tar = Point(_cSpeed * cos(_cOrien) + acc * cos(newori), _cSpeed * sin(_cOrien) + acc * sin(newori));
		_cOrien = (tar.x > 0)? (tar.y > 0)? atan(tar.y / tar.x) : 2 * PI + atan(tar.y / tar.x) : atan(tar.y / tar.x) + PI;
	}
	else {
		_cOrien = newori;
	}

	char n[7];
	sprintf(n, "%3.2f",_cOrien * 180 / PI);
	_cLabel->setString(n);
}
float Character::getOrien() {
	return _cOrien;
}
// 取得 / 設定 角色的速度
void Character::setSpeed(float spd) {
	_cSpeed = spd;
	if (_cSpeed > _cMaxSpeed) {
		_cSpeed = _cMaxSpeed;
	}
	else if (_cSpeed < 0) {
		_cSpeed = 0.0f;
		_cOrien = -1;
	}
}
float Character::getSpeed() {
	return _cSpeed;
}

void Character::upSpeed(float dt){
	setSpeed(_cSpeed + dt * _cAccSpeed);
}
void Character::downSpeed(float dt) {
	setSpeed(_cSpeed - dt * _cDecSpeed);
}

void Character::move(float dt) {
	if (_cSpeed < 0.1) {
		return;
	}
	Point tmp = _cLayer->getPosition();
	Point tar = Point(dt * _cSpeed * cos(_cOrien), dt * _cSpeed * sin(_cOrien));
	switch(_cDimType) {
	case DIM_TYPE::ONLY_X:
		tar.y = 0.0f;
		break;
	case DIM_TYPE::ONLY_Y:
		tar.x = 0.0f;
		break;
	case DIM_TYPE::NO_DIM:
		tar.x = 0.0f;
		tar.y = 0.0f;
		break;
	default:
		break;
	}

	_cLayer->setPosition(tmp + tar);
}

