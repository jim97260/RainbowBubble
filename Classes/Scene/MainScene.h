#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "AllIncludeHeader.h"



class MainScene : public cocos2d::Layer
{
public:
	string title = "Main";
	Character* player;
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    void start(float);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);
};

#endif // __MAIN_SCENE_H__
