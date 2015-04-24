#include "AppDelegate.h"

USING_NS_CC;

AppDelegate::AppDelegate() {
}
AppDelegate::~AppDelegate() 
{
}
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages, 
// don't modify or remove this function
static int register_all_packages()
{
    return 0;
}

bool AppDelegate::applicationDidFinishLaunching() {
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("RainbowBubble");
        director->setOpenGLView(glview);
    }

    director->getInstance()->getOpenGLView()->setDesignResolutionSize(1280, 800, ResolutionPolicy::EXACT_FIT);

    director->setDisplayStats(true);

    director->setAnimationInterval(1.0 / 60);

    register_all_packages();

    auto scene = Main::createScene();
    director->runWithScene(scene);

    return true;
}

// 等同於onPause
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// 等同於onResume
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
    //Director::getInstance()->drawScene();

    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
