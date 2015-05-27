#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

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
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto background = Sprite::create("3.jpg");
    background->setPosition(visibleSize/2);
    this->addChild(background);
    
    schedule([visibleSize](float f){
        
        auto newScene = Scene::create();
        auto newBackGround = Sprite::create("1.jpg");
        newBackGround->setPosition(visibleSize/2);
        newScene->addChild(newBackGround);
        
        auto transition = TransitionPageTurn::create(1, newScene, false);
        Director::getInstance()->replaceScene(transition);
        
    }, 2, "test");
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
