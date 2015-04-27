#include "AllIncludeHeader.h"

Point touchPosition = Point(0, 0);
bool touchSwitch = false;
Point touchDelta = Point(0, 0);
Size visibleSize;

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


    auto listener1 = EventListenerTouchOneByOne::create();
    // trigger when you push down
    listener1->onTouchBegan = [](Touch* touch, Event* event){
        // your code
    	touchSwitch = true;
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
    	}
    };
    // trigger when you let up
    listener1->onTouchEnded = [=](Touch* touch, Event* event){
    	touchSwitch = false;
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
	if (touchSwitch) {
		Point p = player->getPosition();
		p.x += (touchDelta.x / visibleSize.width) * 50;
		p.y += (touchDelta.y / visibleSize.height) * 50;
		if (p.x < 0) {
			p.x = 0;
		}
		else if (p.x > visibleSize.width - 50) {
			p.x = visibleSize.width - 50;
		}
		if (p.y < 0) {
			p.y = 0;
		}
		else if (p.y > visibleSize.height - 50) {
			p.y = visibleSize.height - 50;
		}
		player->setPosition(p);
	}
}

