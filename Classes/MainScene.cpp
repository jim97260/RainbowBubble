#include "AllIncludeHeader.h"

USING_NS_CC;

Scene* Main::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Main::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Main::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto test = createLayerColorWithLabel(cocos2d::Color4B(255, 127, 127, 255), visibleSize, cocos2d::Point(0, 0), cocos2d::Point(0, 0), "Main", cocos2d::Color4B(255, 255, 255, 255), 100);
    this->addChild(test, 0);

    return true;
}
