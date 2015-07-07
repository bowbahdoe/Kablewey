//
//  LevelOneScene.h
//  Rabbits
//
//  Created by Ethan McCue on 5/17/14.
//
//

#ifndef __Rabbits__LevelOneScene__
#define __Rabbits__LevelOneScene__
#include <cocos2d.h>
#include "Ship.h"
#include "EnemyShip.h"
#include "Missile.h"
#include "RoundHandler.h"
#include "RedMissile.h"
#ifndef _cplusplus
#define _cplusplus
#endif
typedef enum
{
    b1,
    b2
}backgroundState;
using namespace cocos2d;
class Missile;

class LevelOneScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    void update(float dt);
    // a selector callback
    //void menuCloseCallback(cocos2d::Ref* pSender);
    void changeScene(cocos2d::Ref* pSender);
    
    //Screen Data
    Point origin;
    Size visibleSize;
    

    void setGameOver(void);
    //add Spirtes
    void addShip();
    Ship* ship;
    void addBackground();
    Sprite* background;
    
    void addBackgroundOffScreen();
    Sprite* background_2;
    void addEnemyShip();
    EnemyShip* enemy;
    backgroundState _bs;
    float missileSpeed;
    void addRedMissile(float x, float y);
    void addMissile(float x, float y);
    //I dont even care anymore std::vector<Missile*>
    virtual void onTouchMoved(const Touch* touch,
                      const Event* touchEvent);
    bool onTap(Touch* touch,
               Event* touchEvent);
    std::vector<Missile*> listOfMissiles;
    
    std::vector<RedMissile*> listOfDangerousMissiles;
    void onTouchesMoved(const std::vector<Touch*> &touches, Event* Event);
    
    void handleDangerousMissiles(float dt);
    void handleMissiles(float dt);
    RoundHandler* getRoundHandler();
    
    void setMissileSpeed(float newSpeed);
    float getMissileSpeed(void);
    
    void addOnePointToScore(void);
    // implement the "static create()" method manually
    CREATE_FUNC(LevelOneScene);
private:
    virtual void onEnter();
    virtual void onExit();
    bool isColliding(Sprite* a, Sprite* b);
    
    RoundHandler* _RoundHandler;
    
    
    
    LabelTTF* label;
    String* labelString;
    };


#endif /* defined(__Rabbits__LevelOneScene__) */
