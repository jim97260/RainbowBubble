#include "AllIncludeHeader.h"

Point touchPosition = Point(0, 0);
bool touchBegin = false;
bool touchMove = false;
Point touchDelta = Point(0, 0);
Size visibleSize;
float tmpspd;

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto test = createLayerColorWithLabel(cocos2d::Color4B(255, 127, 127, 255), visibleSize, cocos2d::Point(0, 0), cocos2d::Point(0, 0), MainScene::title, cocos2d::Color4B(255, 255, 255, 255), 100);
    this->addChild(test, 0);

    player = new Character(this);
    player->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
    player->showLine();

    status = cocos2d::Label::createWithTTF("Stop", "fonts/Marker Felt.ttf", 50, visibleSize, cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::BOTTOM);
    this->addChild(status, 20);

    auto listener1 = EventListenerTouchOneByOne::create();
    // trigger when you push down
    listener1->onTouchBegan = [](Touch* touch, Event* event){
        // your code
    	touchBegin = true;
    	touchPosition = touch->getLocation();
    	//log("[Touch Began] at point(%f, %f)\n", touch->getLocation().x, touch->getLocation().y);
        return true; // if you are consuming it
    };
    // trigger when moving touch
    listener1->onTouchMoved = [](Touch* touch, Event* event){
        // your code
    	//log("[Touch Moved] at point(%f, %f)\n", touch->getLocation().x - touchPosition.x, touch->getLocation().y - touchPosition.y);
    	touchDelta = Point(touch->getLocation().x - touchPosition.x, touch->getLocation().y - touchPosition.y);
    	if (abs(touchDelta.x) > 10 || abs(touchDelta.y) > 10) {
    		log("%f, %f", touchDelta.x, touchDelta.y);
    		touchMove = true;
    	}
    	else {
    		touchMove = false;
    	}
    };
    // trigger when you let up
    listener1->onTouchEnded = [=](Touch* touch, Event* event){
    	touchBegin = false;
    	touchMove = false;
    	touchPosition = Point(0, 0);
    	//log("[Touch Ended]\n");

        // your code
    };
    // Add listener
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);

    this->schedule(CC_SCHEDULE_SELECTOR(MainScene::start));

    return true;
}
void MainScene::start(float delta)
{
	if (touchBegin) {
		if (touchMove) {
			player->setOrien(touchDelta);
		}
		player->upSpeed(delta);
	}
	else {
		player->downSpeed(delta);
	}
	player->move(delta);
	player->showLine();
	//log("[SPEED] %f\n", tmpspd);
}
