#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    this->setTouchEnabled(true);

     m_pop = new PopUpView("popUpBGg.png", "Test", "Nice to meet you", "OK",menu_selector(HelloWorld::OK), "Cancel",menu_selector(HelloWorld::cancel),this);
    this->addChild(m_pop);
//    CCMessageBox("haha", "test");
    
    return true;
}

void HelloWorld::OK()
{
    CCLog("OK");
    this->removeChild(m_pop);
}

void HelloWorld::cancel()
{
    CCLog("cancel");
    this->removeChild(m_pop);
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


void HelloWorld::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
    CCLog("HelloWorld touch begin");
}

void HelloWorld::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
    CCLog("HelloWorld touch moved");
}

void HelloWorld::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
    CCLog("HelloWorld touch end");
}


