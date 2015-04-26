/*
 * GameModeScene.h
 *
 *  Created on: 2015�~4��26��
 *      Author: Jinyu
 */

#ifndef SCENE_GAMEMODESCENE_H_
#define SCENE_GAMEMODESCENE_H_

#include "AllIncludeHeader.h"

class GameModeScene : public cocos2d::Layer
{
public:
	string title = "Game Mode";
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(GameModeScene);
};

#endif /* SCENE_GAMEMODESCENE_H_ */
