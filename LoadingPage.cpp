//
//  LoadingPage.cpp
//  chats
//
//  Created by 付剑超 on 13-8-16.
//
//

#include "LoadingPage.h"
#include "Main.h"
#include "MessageList.h"

using namespace cocos2d;

LoadingPage:: LoadingPage(){
    
}
LoadingPage::~LoadingPage(){
    
}

void LoadingPage:: sceneWithTargetScene(const TargetScenes targetScene){

    printf("replaceScene to %d\n",targetScene);
    targetScene_=targetScene;
    
    LoadingPage::initWithTargetScene(targetScene);

    
}


void LoadingPage:: initWithTargetScene(const TargetScenes targetScene){

    targetScene_ = targetScene;
   this-> schedule (schedule_selector(LoadingPage::Chatupdate)) ;
   
    switch (targetScene_) {
        case TargetSceneMsgList:
        {

            MessageList *thelayer=MessageList::create();
            CCScene *theScene=CCScene::create();
            theScene->addChild(thelayer,0);
            
            CCDirector::sharedDirector()->replaceScene(theScene);
            break;
        }
            
        default:
            CCDirector::sharedDirector()->replaceScene(MessageList::scene());
            break;
    }

    
}

void LoadingPage::Chatupdate(float dt){
       printf("========chup========"); 
}



