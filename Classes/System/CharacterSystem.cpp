/*
 * CharacterSystem.cpp
 *
 *  Created on: 2015年4月26日
 *      Author: Jinyu
 */

#include "CharacterSystem.h"
Character::Character() {
	_cPara = CHAR_PLAYER | ORIEN_NORMAL | DIM_ALL;
	_cOrien = 0.0f;
	_cSpeed = 0.0f;
	_cLayer = cocos2d::LayerColor::create();
}

Character::Character(Layer* scene) {
	_cPara = CHAR_PLAYER | SHOW_SPRITE | ORIEN_NORMAL | DIM_ALL;
/*
	if ((_cPara & CHAR) == CHAR_EMPTY) {
		return;
	}*/
	_cOrien = 0.0f;
	_cSpeed = 0.0f;
	_cMaxSpeed = 100.0f;
	_cAccSpeed = 10;
	_cDecSpeed = 10;
	_cTunSpeed = 10;

	if ((_cPara & SHOW) == SHOW_LAYER) {
		_cLayer = cocos2d::LayerColor::create(Color4B(127, 255, 127, 255), 50, 50);

		char n[7];
		sprintf(n, "%3.2f",_cOrien);
		_cLabel = cocos2d::Label::createWithTTF(n, "fonts/Marker Felt.ttf", 50, _cLayer->getContentSize(), cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
		_cLabel->setTextColor(Color4B::BLACK);
		_cLayer->setAnchorPoint(Point::ANCHOR_MIDDLE);
		_cNode = DrawNode::create();
		_cLayer->addChild(_cLabel, 10);
		_cLayer->addChild(_cNode, 9);
		//_cSprite = Sprite::create("linda_map.png");

		scene->addChild(_cLayer);
		//scene->addChild(_cSprite);
	}
	else {
		_cSprite = Sprite::create("linda_map.png");
		_cSpriteX = 8;
		_cSpriteY = 4;
		_cSpriteOri.push_back(0);
		_cSpriteOri.push_back(1);
		_cSpriteOri.push_back(2);
		_cSpriteOri.push_back(3);
		_cSpriteNowY = _cSpriteOri[SPORI_DOWN];
		_cSpriteNowX = 0;
		_cSpriteWidth = _cSprite->getContentSize().width / _cSpriteX;
		_cSpriteHeight = _cSprite->getContentSize().height / _cSpriteY;
		_cSprite = Sprite::create("linda_map.png");
		_cSprite->setScale(3.0f);
		_cSprite->setTextureRect(Rect(_cSpriteWidth * _cSpriteNowX, _cSpriteHeight * _cSpriteNowY, _cSpriteWidth,_cSpriteHeight));
		_cSprite->setAnchorPoint(Point::ANCHOR_MIDDLE);

		scene->addChild(_cSprite);
	}
}

Character::Character(Layer* scene, int para, Point pos, float ori, float spd, float max, float acc, float dec, Sprite* spr) {
	_cPara = para;
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
/*
	Point tmp;
	if ((_cPara & SHOW) == SHOW_LAYER) {
		 tmp = Point(_cLayer->getContentSize().width * 0.5, _cLayer->getContentSize().height * 0.5);

		 Point tar = Point(tmp.x + _cSpeed * cos(_cOrien), tmp.y + _cSpeed * sin(_cOrien));
		//_cNode->drawLine(tmp, tar, Color4F::WHITE);
		_cNode->clear();
		_cNode->drawSegment(tmp, tar, 3, Color4F(1, 1, 1, 1));
	}
	else {
		//tmp = Point(_cSprite->getContentSize().width * 0.5, _cSprite->getContentSize().height * 0.5);
	}
*/
}
// 取得 / 設定 角色的位置
void Character::setPosition(Point pos) {
	if ((_cPara & SHOW) == SHOW_LAYER) {
		log("LAYER SETPOSITON");
		_cLayer->setPosition(pos);
	}
	else {
		log("SPRITE SETPOSITON");
		_cSprite->setPosition(pos);
	}
}
Point Character::getPosition() {
	if ((_cPara & SHOW) == SHOW_LAYER) {
		log("LAYER SETPOSITON");
		return _cLayer->getPosition();
	}
	else {
		log("SPRITE GETPOSITON");
		return _cSprite->getPosition();
	}
}

// 取得 / 設定 角色的方向
void Character::setOrien(Point ori) {
	setOrien(ori, _cPara);
}
void Character::setOrien(Point ori, int type) {
	float newori = (ori.x > 0)? (ori.y > 0)? atan(ori.y / ori.x) : 2 * PI + atan(ori.y / ori.x) : atan(ori.y / ori.x) + PI;

	if ((_cPara & ORIEN == ORIEN_VECTOR) && _cOrien >  0) {
		float acc = _cMaxSpeed / 100 * _cTunSpeed;
		Point tar = Point(_cSpeed * cos(_cOrien) + acc * cos(newori), _cSpeed * sin(_cOrien) + acc * sin(newori));
		_cOrien = (tar.x > 0)? (tar.y > 0)? atan(tar.y / tar.x) : 2 * PI + atan(tar.y / tar.x) : atan(tar.y / tar.x) + PI;
	}
	else {
		_cOrien = newori;
	}

	if ((_cPara & SHOW) == SHOW_LAYER) {
		log("LAYER SETORIEN");
		char n[7];
		sprintf(n, "%3.2f",_cOrien * 180 / PI);
		_cLabel->setString(n);
	}
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
	setSpeed(_cSpeed + dt * _cAccSpeed * _cMaxSpeed);
}
void Character::downSpeed(float dt) {
	setSpeed(_cSpeed - dt * _cDecSpeed * _cMaxSpeed);
	if (_cSpeed < 0.1) {
		stop();
	}
}

void Character::move(float dt) {
	if (_cSpeed < 0.1) {
		stop();
		return;
	}

	Point tmp;
	if ((_cPara & SHOW) == SHOW_LAYER) {
		tmp = _cLayer->getPosition();
	}
	else {
		tmp = _cSprite->getPosition();
	}

	Point tar = Point(dt * _cSpeed * cos(_cOrien), dt * _cSpeed * sin(_cOrien));
	log ("_cPara = %d", _cPara & DIM);//\n1.ALL %d\n2.OLX %d\n3. OLY %d\n4. NOD %d
	switch(_cPara & DIM) {
	case DIM_ONLY_X:
		tar.y = 0.0f;
		break;
	case DIM_ONLY_Y:
		tar.x = 0.0f;
		break;
	case DIM_NULL:
		tar.x = tar.y = 0.0f;
		break;
	default:
		break;
	}

	if ((_cPara & SHOW) == SHOW_LAYER) {
			_cLayer->setPosition(tmp + tar);
		}
		else {
			_cSpriteNowX += dt * _cSpriteX;
			log("%d\n", (int)_cSpriteNowX);
			if (_cSpriteNowX > _cSpriteX)
				_cSpriteNowX -= _cSpriteX;
			float deg = _cOrien * 180 / PI;
			if (deg < 45 || deg > 315) {
				_cSpriteNowY = _cSpriteOri[SPORI_RIGHT];
			}
			else if (deg < 135) {
				_cSpriteNowY = _cSpriteOri[SPORI_UP];
			}
			else if (deg < 225) {
				_cSpriteNowY = _cSpriteOri[SPORI_LEFT];
			}
			else {
				_cSpriteNowY = _cSpriteOri[SPORI_DOWN];
			}

			_cSprite->setTextureRect(Rect(_cSpriteWidth * (int)_cSpriteNowX, _cSpriteHeight * (int)_cSpriteNowY, _cSpriteWidth,_cSpriteHeight));
			_cSprite->setPosition(tmp + tar);

		}
}
void Character::stop() {
	_cSpriteNowX = 0.0f;
	_cSprite->setTextureRect(Rect(_cSpriteWidth * (int)_cSpriteNowX, _cSpriteHeight * (int)_cSpriteNowY, _cSpriteWidth,_cSpriteHeight));
}

