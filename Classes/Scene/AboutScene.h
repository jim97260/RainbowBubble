/*
 * AboutScene.h
 *
 *  Created on: 2015¦~4¤ë26¤é
 *      Author: Jinyu
 */

#ifndef SCENE_ABOUTSCENE_H_
#define SCENE_ABOUTSCENE_H_

#include "AllIncludeHeader.h"

class AboutScene : public cocos2d::Layer
{
public:
	string title = "About";
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(AboutScene);
};

#endif /* SCENE_ABOUTSCENE_H_ */
