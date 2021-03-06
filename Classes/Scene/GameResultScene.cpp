/*
 * GameResultScene.cpp
 *
 *  Created on: 2015�~4��26��
 *      Author: Jinyu
 */

#include "GameResultScene.h"

Scene* GameResultScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = GameResultScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameResultScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto test = createLayerColorWithLabel(cocos2d::Color4B(255, 127, 127, 255), visibleSize, cocos2d::Point(0, 0), cocos2d::Point(0, 0), GameResultScene::title, cocos2d::Color4B(255, 255, 255, 255), 100);
    this->addChild(test, 0);

    return true;
}
