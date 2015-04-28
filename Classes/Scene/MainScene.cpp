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
	if (touchMove) {
		tmpspd += touchDelta.distance(touchPosition) / 50;
		float newori = (touchDelta.x > 0)? (touchDelta.y > 0)? atan(touchDelta.y / touchDelta.x) : 2 * PI + atan(touchDelta.y / touchDelta.x) : atan(touchDelta.y / touchDelta.x) + PI;
		player->setOrien(newori * 180 / PI);
	}
	else {
		if (tmpspd > 0)
				tmpspd -= delta * 1000;
			else if (tmpspd < 0)
				tmpspd = 0;
	}
	player->setSpeed(tmpspd);
	player->showLine();
	//log("[SPEED] %f\n", tmpspd);
}
