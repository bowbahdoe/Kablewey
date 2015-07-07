//
//  GameOverScene.cpp
//  Kablewey
//
//  Created by Ethan McCue on 6/15/14.
//
//

#include "GameOverScene.h"
#include "LevelOneScene.h"
#include "ScoreKeeper.h"
#include <cocos2d.h>
#include <stdlib.h>
extern ScoreKeeper* Score;
bool GameOverScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    shouldContinue = true;
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    shouldContinue = false;
    ChartboostX::sharedChartboostX()->setDelegate(this);
    
#endif
    
    
    populateGameOverMessages();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    //GameOver Message
    auto label = LabelTTF::create(getMessage(), "", 72);//    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    
    label->setPosition(Point(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 3);
    
    auto restart = LabelTTF::create("Restart?", "comic_sans", 48);//    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    restart->setPosition(Point(origin.x + visibleSize.width/2,
                             origin.y  +visibleSize.width/4 - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(restart, 2);
    
    auto labelString = CCString::createWithFormat("High Score: %d. Your Score: %d", Score->getHighScore(), Score->getLastScore());
    
    auto scorelabel = LabelTTF::create(labelString->getCString(), "", 48);
    //auto label = LabelTTF::create("Hello Woredgergeld", "Arial", 24);
    
    // position the label on the center of the screen
    scorelabel->setPosition(Point(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - label->getContentSize().height*3));
    
    // add the label as a child to this layer
    this->addChild(scorelabel, 1);
    
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto multiTouchListener = EventListenerTouchAllAtOnce::create();
    multiTouchListener->onTouchesBegan = CC_CALLBACK_2(GameOverScene::onTouchesBegan,this);
    dispatcher->addEventListenerWithSceneGraphPriority(multiTouchListener, this);
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

    ChartboostX::sharedChartboostX()->hasCachedInterstitial();
    ChartboostX::sharedChartboostX()->showInterstitial();
#endif
    
    return true;

    
}
void GameOverScene::onTouchesBegan(const std::vector<Touch *> &touches, Event* event)
{

    if(shouldContinue)
    {
        Director::getInstance()->replaceScene(LevelOneScene::createScene());
    }
}
Scene* GameOverScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameOverScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}
void GameOverScene::populateGameOverMessages(void)
{
    gameOverMessages.push_back("You lost");
    gameOverMessages.push_back("You can do better than that");
    gameOverMessages.push_back("Catch Them!");
    //gameOverMessages.push_back("YOU SUCK!");
    gameOverMessages.push_back("Better luck next time");
    gameOverMessages.push_back("Mwahahahaha");
    //gameOverMessages.push_back("All your base are belong to us!");
    gameOverMessages.push_back("Be better than that");
    gameOverMessages.push_back("Good job...?");
    gameOverMessages.push_back("Failed You Have");
    gameOverMessages.push_back("Nice try");
    gameOverMessages.push_back("Get a different hobby");
    gameOverMessages.push_back("You missed a spot");
    gameOverMessages.push_back("Great job");
    gameOverMessages.push_back("Wax on. Wax off.");
    
}
std::string GameOverScene::getMessage(void)
{
    int randomIndex = rand() % gameOverMessages.size();
    return gameOverMessages[randomIndex];
}




bool GameOverScene::shouldDisplayInterstitial(const char* location)
{
    CCLOG("about to display interstitial at location %s", location);
    shouldContinue = false;
    return true;
}

void GameOverScene::didCacheInterstitial(const char* location)
{
    CCLOG("did cache interstitial at location %s", location);
}

void GameOverScene::didFailToLoadInterstitial(const char* location)
{
    CCLOG("did fail to load interstitial at location %s", location);
    shouldContinue = true;

}

void GameOverScene::didCloseInterstitial(const char* location)
{
    CCLOG("did close interstitial at location %s", location);
    shouldContinue = true;
}

void GameOverScene::didClickInterstitial(const char* location)
{
    CCLOG("did click interstitial at location %s", location);
    shouldContinue = true;

}