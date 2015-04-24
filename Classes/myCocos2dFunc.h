/*
 * myCocos2dFunc.h
 *
 *  Created on: 2015¦~4¤ë24¤é
 *      Author: Jinyu
 */

#ifndef __MY_COCOS2D_FUNC_H__
#define __MY_COCOS2D_FUNC_H__

#include "AllIncludeHeader.h"

cocos2d::LayerColor* createLayerColorWithLabel(	const cocos2d::Color4B color = cocos2d::Color4B(127, 127, 127, 255),
												const cocos2d::Size size = cocos2d::Size(50, 50),
												const cocos2d::Point anchor = cocos2d::Point(0, 0),
												const cocos2d::Point pos = cocos2d::Point(0, 0),
												const std::string title = "",
												const cocos2d::Color4B lc = cocos2d::Color4B(255, 255, 255, 255),
												const int font_size = 60);
//cocos2d::LayerColor* createLayerColorWithLabel(cocos2d::Color4B, cocos2d::Size, cocos2d::Point, cocos2d::Point, string, cocos2d::Color4B);
//cocos2d::LayerColor* createLayerColorWithLabel(cocos2d::Color4B, cocos2d::Size, cocos2d::Point, cocos2d::Point, string);
cocos2d::Sprite* createSpriteWithLabel(string, cocos2d::Size, cocos2d::Point, cocos2d::Point, string, cocos2d::Color4B, int);
cocos2d::Sprite* createSpriteWithLabel(string, cocos2d::Size, cocos2d::Point, cocos2d::Point, string, cocos2d::Color4B);

#endif // __MY_COCOS2D_FUNC_H__
