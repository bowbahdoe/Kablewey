//
//  GameOverScene.h
//  Kablewey
//
//  Created by Ethan McCue on 6/15/14.
//
//

#ifndef __Kablewey__GameOverScene__
#define __Kablewey__GameOverScene__
#include "MenuScene.h"

//Chartboost wont work on android right now. so all code should be ios only
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#include "ChartboostX.h"
#endif
#include <cocos2d.h>
class GameOverScene:public cocos2d::Layer

//if cahrtboost, this inherits from ChartboostXDelegate
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
,public ChartboostXDelegate
#endif


{
public:
    virtual bool init();
     static cocos2d::Scene* createScene();
    
    std::vector<std::string> gameOverMessages;
    void onTouchesBegan(const std::vector<Touch*> &touches, Event* event);
    
    // ChartboostXDelegate method
    bool shouldDisplayInterstitial(const char* location);
    void didCacheInterstitial(const char* location);
    void didFailToLoadInterstitial(const char* location);
    void didCloseInterstitial(const char* location);
    void didClickInterstitial(const char* location);
    
    
    CREATE_FUNC(GameOverScene);
private:
    void populateGameOverMessages(void);
    std::string getMessage(void);
    bool shouldContinue;

};

#endif /* defined(__Kablewey__GameOverScene__) */
