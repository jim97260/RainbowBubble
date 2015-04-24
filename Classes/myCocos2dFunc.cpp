#include "myCocos2dFunc.h"

cocos2d::LayerColor* createLayerColorWithLabel(	cocos2d::Color4B color,
												cocos2d::Size size,
												cocos2d::Point anchor,
												cocos2d::Point pos,
												string title,
												cocos2d::Color4B lc,
												int fontsize) {
    auto lbanchor = cocos2d::Point(0.5, 0.5);
    auto ly = cocos2d::LayerColor::create(color, size.width, size.height);
    ly->ignoreAnchorPointForPosition(false);
    ly->setAnchorPoint(anchor); // (0~1, 0~1)
    ly->setPosition(pos);

    auto lb = cocos2d::Label::createWithTTF(title, "fonts/Marker Felt.ttf", fontsize, size, cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
    lb->ignoreAnchorPointForPosition(false);
    lb->setAnchorPoint(lbanchor); // (0~1, 0~1)
    lb->setTextColor(lc);

    //nGameBackGroundLayer->getContentSize().width/2

    lb->setPosition(cocos2d::Point(ly->getContentSize().width / 2, ly->getContentSize().height / 2));

    ly->addChild(lb, 1);

    return ly;
}
/*
cocos2d::LayerColor* createLayerColorWithLabel(cocos2d::Color4B color, cocos2d::Size size, cocos2d::Point anchor, cocos2d::Point pos, string title, cocos2d::Color4B lc) {
	auto lbanchor = cocos2d::Point(0.5, 0.5);
	auto ly = cocos2d::LayerColor::create(color, size.width, size.height);
    ly->ignoreAnchorPointForPosition(false);
    ly->setAnchorPoint(anchor);
    ly->setPosition(pos);

	auto lb = cocos2d::Label::createWithTTF(title, "fonts/Marker Felt.ttf", 60, size, cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	lb->ignoreAnchorPointForPosition(false);
	lb->setAnchorPoint(lbanchor);
    lb->setTextColor(lc);

	lb->setPosition(cocos2d::Point(ly->getContentSize().width / 2, ly->getContentSize().height / 2));

	ly->addChild(lb, 1);

	return ly;
}

cocos2d::LayerColor* createLayerColorWithLabel(cocos2d::Color4B color, cocos2d::Size size, cocos2d::Point anchor, cocos2d::Point pos, string title) {
    auto lbanchor = cocos2d::Point(0.5, 0.5);
    auto ly = cocos2d::LayerColor::create(color, size.width, size.height);
    ly->ignoreAnchorPointForPosition(false);
    ly->setAnchorPoint(anchor);
    ly->setPosition(pos);

    auto lb = cocos2d::Label::createWithTTF(title, "fonts/Marker Felt.ttf", 60, size, cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
    lb->ignoreAnchorPointForPosition(false);
    lb->setAnchorPoint(lbanchor);

    lb->setPosition(cocos2d::Point(ly->getContentSize().width / 2, ly->getContentSize().height / 2));

    ly->addChild(lb, 1);

    return ly;
}
*/
cocos2d::Sprite* createSpriteWithLabel(string filename, cocos2d::Size size, cocos2d::Point anchor, cocos2d::Point pos, string title, cocos2d::Color4B lc) {
    auto lbanchor = cocos2d::Point(0.5, 0.5);
    auto sp = cocos2d::Sprite::create(filename/*, Rect(0, 0, size.width, size.height)*/);
    sp->ignoreAnchorPointForPosition(false);
    sp->setAnchorPoint(anchor);
    sp->setPosition(pos);

    auto lb = cocos2d::Label::createWithTTF(title, "fonts/Marker Felt.ttf", 60, size, cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
    lb->ignoreAnchorPointForPosition(false);
    lb->setAnchorPoint(lbanchor);
    lb->setTextColor(lc);

    lb->setPosition(cocos2d::Point(sp->getContentSize().width / 2, sp->getContentSize().height / 2));

    sp->addChild(lb, 1);

    return sp;
}

cocos2d::Sprite* createSpriteWithLabel(string filename, cocos2d::Size size, cocos2d::Point anchor, cocos2d::Point pos, string title, cocos2d::Color4B lc, int fontsize) {
    auto lbanchor = cocos2d::Point(0.5, 0.5);
    auto sp = cocos2d::Sprite::create(filename/*, Rect(0, 0, size.width, size.height)*/);
    sp->ignoreAnchorPointForPosition(false);
    sp->setAnchorPoint(anchor);
    sp->setPosition(pos);


    auto lb = cocos2d::Label::createWithTTF(title, "fonts/Marker Felt.ttf", fontsize, size, cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
    lb->ignoreAnchorPointForPosition(false);
    lb->setAnchorPoint(lbanchor);
    lb->setTextColor(lc);

    lb->setPosition(cocos2d::Point(sp->getContentSize().width / 2, sp->getContentSize().height / 2));

    sp->addChild(lb, 1);

    return sp;
}
