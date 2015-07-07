#define _cplusplus
#include "AppDelegate.h"
#include "MenuScene.h"

#include "ScoreKeeper.h"
#include "ErraticMovement.h"
#include "SimpleAudioEngine.h"
#include <ctime>

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#include "ChartboostX.h"
#endif

USING_NS_CC;
extern int Halophile;
ScoreKeeper* Score = new ScoreKeeper();

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);
    
    //Botychy resolution hack
    //glview->setDesignResolutionSize(640,960,ResolutionPolicy::EXACT_FIT);
    director->setContentScaleFactor(1);
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 600 );
    
    //ios (or android when working) specific code for chartboost
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    // Begin a user session. This should be done once per boot
    ChartboostX::sharedChartboostX()->startSession();
    
    /*
     * Add your own app id & signature. These can be found on App Edit page for your app in the Chartboost dashboard
     *
     * Notes:
     * BE SURE YOU USE YOUR OWN CORRECT APP ID & SIGNATURE!
     */

    ChartboostX::sharedChartboostX()->setAppId("5394c291c26ee44a8036f2de");
    ChartboostX::sharedChartboostX()->setAppSignature("fc8fa44d137ee745b53637c82a86fab6f3070043");
#endif
    // create a scene. it's an autorelease object
    auto scene = MenuScene::createScene();
    Score->setScore(0);
       // run
    srand(time(NULL));
    director->runWithScene(scene);
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
    
    // if you use SimpleAudioEngine, it must be pause
     CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
