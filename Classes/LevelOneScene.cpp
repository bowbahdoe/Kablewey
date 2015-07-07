//
//  LevelOneScene.cpp
//  Rabbits
//
//  Created by Ethan McCue on 5/17/14.
//
//
#
#include "LevelOneScene.h"
#include "ScoreKeeper.h"
#include "Ship.h"
#include "ErraticMovement.h"
#include "MissileMovementLoop.h"
#include "MenuScene.h"
#include "Screen.h"
#include "GameOverScene.h"
#include "SimpleAudioEngine.h"
#include "Settings.h"
#include "RoundHandler.h"
extern ScoreKeeper* Score;
bool gameOver = false;
Scene* LevelOneScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = LevelOneScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool LevelOneScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Bloop.mp3");
    _bs = b1;
    
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
   labelString = CCString::createWithFormat("%d", Score->getScore());
    
    label = LabelTTF::create(labelString->getCString(), "", 72);
    //auto label = LabelTTF::create("Hello Woredgergeld", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - label->getContentSize().height*3));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    addBackground();
    addShip();
    addEnemyShip();
    
    this->schedule(schedule_selector(LevelOneScene::update));
    
    _RoundHandler = new RoundHandler();
    


    
    
    return true;
}
void LevelOneScene::addBackground()
{
    background = Sprite::create("Space.png");
    
    // position the sprite on the center of the screen
    background->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    //background->setPosition(Point(background->getContentSize().height*2+ origin.x, 0));
    // add the sprite as a child to this layer
    this->addChild(background, -1);
    background_2 = Sprite::create("Space.png");
    background_2->setPosition(Point(background->getBoundingBox().getMaxX(),visibleSize.height/2 + origin.y));
    this->addChild(background_2,-1);
}
void LevelOneScene::addShip()
{
    ship = new Ship();
    ship->setPosition(visibleSize.width-visibleSize.width/8,visibleSize.height/8);
    this->addChild(ship);
    CCLOG("PlayerShip Spawned");

}
void LevelOneScene::addEnemyShip()
{
    enemy = new EnemyShip();
    enemy->setPosition(origin.x+enemy->getContentSize().width/2, visibleSize.height-enemy->getContentSize().height/2);
    this->addChild(enemy);
    CCLOG("EnemyShip Spawned");
    
}
void LevelOneScene::addMissile(float x, float y)
{
    auto missile = new Missile();
    ((Node*)missile)->setPosition(x, y);
    //missile add component for movement
    listOfMissiles.push_back(missile);
    //((Node*)missile)->addComponent(new MissileMovementLoop());
    this->addChild((Node*)missile);
}
void LevelOneScene::addRedMissile(float x, float y)
{
    auto red_missile = new RedMissile();
    ((Node*)red_missile)->setPosition(x, y);
    listOfDangerousMissiles.push_back(red_missile);
    this->addChild((Node*)red_missile);
}
void LevelOneScene::onTouchesMoved(const std::vector<Touch*> &touches, Event* Event)
{
    for(Touch* ad: touches)
        onTouchMoved(ad, Event);
}
bool LevelOneScene::onTap(Touch* touch,
                          Event* touchEvent)
{
    
    CCLOG("Screen was Tapped");
    onTouchMoved(touch,touchEvent);
    return 0;
    
}
void LevelOneScene::onTouchMoved(const Touch* touch,
                                 const Event* touchEvent)
{
    //CCLOG("Touch Moved\n");
    
    ship->setPositionY(touch->getLocation().y);
}
void LevelOneScene::update(float dt)
{
    background->setAnchorPoint(Point(background->getAnchorPoint().x+.0003,
                                     background->getAnchorPoint().y));
    CCLOG("B1: %d %d",(int)background->getContentSize().width,(int)background->getAnchorPointInPoints().x);
    if ((background->getContentSize().width)<=((background->getAnchorPointInPoints().x)))
    {
        ;//addBackgroundOffScreen();
    }
    background_2->setAnchorPoint(Point(background_2->getAnchorPoint().x+.0003,
                                       background_2->getAnchorPoint().y));
    CCLOG("B2: %d %d",(int)background->getContentSize().width,(int)background->getAnchorPointInPoints().x);
    if ((background_2->getContentSize().width)==(background_2->getAnchorPointInPoints().x))
    {
        ;//addBackgroundOffScreen();
    }
    
    if(EASY_MODE)
    {
        gameOver = false;
    }
    if(gameOver)
    {
        
        //this->removeAllChildren();
        
        for(Missile* mis: listOfMissiles)
        {
            mis->isToBeDeleted= true;
            this->removeChild(mis);
            
        }
        if(Score->getScore()>Score->getHighScore())
        {
        
            Score->setHighScore( Score->getScore());Score->getHighScore();
        }
        Score->setLastScore(Score->getScore());
        Score->setScore(0);
        Director::getInstance()->replaceScene(GameOverScene::createScene());
    }
    enemy->update(dt);
    //////
    _RoundHandler->addTime(dt);

    //////
    auto round = getRoundHandler()->getRound();
    if(!(missileSpeed<100) and ((round%2)==0))
    {
        missileSpeed-=dt*5;//7.5 faster, becomes literally impssible after 200pts;//Makes it go progressively faster. Much. Much. faster.
  
    }
    handleMissiles(dt);
    handleDangerousMissiles(dt);
}
void LevelOneScene::handleMissiles(float dt)
{
    for(Missile* mis: listOfMissiles)
    {
        mis->update(dt,missileSpeed);
        if(isColliding(mis,ship))
        {
            
            //CCLOG("Ship Colliding with bullet");
            this->removeChild(mis);
            
            if(!(mis->isToBeDeleted))
            {
                CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Bloop.mp3");
                //begin cleanup fo missile array
                int x = 0;
                for(Missile* deleteCandidate: listOfMissiles)
                {
                    if(deleteCandidate->isToBeDeleted==true)
                    {
                        if(listOfMissiles[x] == deleteCandidate)
                        {
                            listOfMissiles.erase(listOfMissiles.begin()+x);
                            
                        }
                        
                        
                    }
                    x++;
                    //end cleanup of missile array
                    
                    
                }
                
                addOnePointToScore();
            }
            mis->isToBeDeleted = true;
            
        }
    }
}
void LevelOneScene::handleDangerousMissiles(float dt)
{
    //The missiles should all go off screen one at a time, so in my tradition of not giving a flying shit
    //i will just get rid of the first if there is one that is going off
    int x = 0;
    CCLOG("%d",listOfDangerousMissiles.size());
    for(auto deleteCandidate: listOfDangerousMissiles)
    {
        if(deleteCandidate->isToBeDeleted==true)
        {
            if(listOfDangerousMissiles[x] == deleteCandidate)
            {
                listOfDangerousMissiles.erase(listOfDangerousMissiles.begin()+x);
                //this->removeChild(listOfDangerousMissiles[x]);
            }
            
            
        }
        x++;
    }
    //end cleanup of missile array


    for(RedMissile* mis: listOfDangerousMissiles)
    {
        mis->update(dt,missileSpeed);
        if(isColliding(mis,ship))
        {
            gameOver = true;
            //CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Bloop.mp3");
            //Replace with error message
            this->removeChild(mis);
            
  
            mis->isToBeDeleted = true;
            
        }
        if(mis->getIsOffscreen())
        {
            addOnePointToScore();
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Bloop.mp3");
            mis->isToBeDeleted = true;
        }
    }
}

void LevelOneScene::setMissileSpeed(float newSpeed)
{
    missileSpeed = newSpeed;
}
float LevelOneScene::getMissileSpeed(void)
{
    return missileSpeed;
}
void LevelOneScene::setGameOver(void)
{
    ;//gameOver = true;
}
void LevelOneScene::onExit()
{
    Layer::onExit();
    gameOver = false;
}
void LevelOneScene::onEnter()
{
    //gameOver = false;
    missileSpeed=600;
    Layer::onEnter();
    //this->setTouchEnabled(true);
    
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto touchListener = EventListenerTouchOneByOne::create();
    LevelOneScene* sceneArg = this;
    touchListener->setSwallowTouches(true);
    //touchListener->onTouchBegan = CC_CALLBACK_2(LevelOneScene::onTap, sceneArg);
    touchListener->onTouchBegan = [sceneArg](Touch* touch, Event* event)->bool {return sceneArg->onTap(touch, event);};
    touchListener->onTouchMoved = [sceneArg](Touch* touch, Event* event)->void {sceneArg->onTouchMoved(touch, event);};
    //touchListener->onTouchMoved = CC_CALLBACK_2(LevelOneScene::onTouchMoved, sceneArg);
    
    dispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    
    auto multiTouchListener = EventListenerTouchAllAtOnce::create();
    multiTouchListener->onTouchesMoved = CC_CALLBACK_2(LevelOneScene::onTouchesMoved,this);
    dispatcher->addEventListenerWithSceneGraphPriority(multiTouchListener, this);
}
bool LevelOneScene::isColliding(Sprite* a, Sprite* b)
{
    Rect aRect = a->boundingBox();
    Rect bRect = b->boundingBox();
    if(aRect.intersectsRect(bRect))
    {
        return true;
    }
    else
    {
        return false;
    }
}
RoundHandler* LevelOneScene::getRoundHandler()
{
    return _RoundHandler;
}
void LevelOneScene::addOnePointToScore(void)
{
    Score->addToScore(1);
    this->removeChild(label);
    labelString = CCString::createWithFormat("%d", Score->getScore());
    
    label = LabelTTF::create(labelString->getCString(), "", 72);
    //auto label = LabelTTF::create("Hello Woredgergeld", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - label->getContentSize().height*3));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
}
void LevelOneScene::addBackgroundOffScreen()
{
    auto bg = background_2;
    auto bg_2 = background;
    if(_bs==b1)
    {
         bg = background;
        bg_2 = background_2;
    }
    bg->setPosition(bg_2->getBoundingBox().getMaxX(),visibleSize.height/2 + origin.y);
        /*while(((int)bg->getAnchorPointInPoints().x)>=((int)background_2->getAnchorPointInPoints().x+background->getContentSize().width))
        {
            bg->setAnchorPoint(Point(bg->getAnchorPointInPoints().x-.001,
                                     bg->getAnchorPointInPoints().y)
                                            );
        }
        bg->setPosition(Point(bg_2->getPositionX()+bg_2->getContentSize().width/2,
                                      visibleSize.height/2 + origin.y));
        _bs=b2;*/
        
    
    if(_bs==b1)
    {
        _bs= b2;
    }else{
        _bs = b1;
    }

}