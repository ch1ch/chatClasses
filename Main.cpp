//
//  Main.cpp
//  chats
//
//  Created by 付剑超 on 13-8-12.
//
//

#include "Main.h"
#include "MessageHandle.h"
#include "SimpleAudioEngine.h"
#include "MessageList.h"


using namespace cocos2d;
using namespace CocosDenshion;

CCScene* Main::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Main *layer = Main::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Main::init()
{

    if ( !CCLayer::init() )
    {
        return false;
    }
        
    this->schedule(schedule_selector(Main::update));
    
    return true;
}

void Main::update(float dt){
    printf("====main update======\n");
    
   LoadingPage *loadingPage=new LoadingPage;
    
   loadingPage->sceneWithTargetScene(TargetSceneMsgList);
    delete loadingPage;
    loadingPage=NULL;

}



void Main::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
