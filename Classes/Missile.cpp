//
//  Missile.cpp
//  Kablewey
//
//  Created by Ethan McCue on 6/2/14.
//
//

#include "Missile.h"
#include "LevelOneScene.h"
extern bool gameOver;

Missile::Missile()
{

    initWithFile("MISSILE_FIRED.png");
    timeUntilFire = 0;
    isToBeDeleted=false;
    
}
void Missile::update(float dt, float missileSpeed)
{
    
    
    
    timeUntilFire+=dt;
    //this->stopAllActions();//TO be taken out
    auto visibleSize = Director::getInstance()->getVisibleSize();
    if(this->getPositionX()>visibleSize.width+this->getContentSize().width)
    {
        auto parent = getParent();
        if(!isToBeDeleted){
            parent->removeChild(this);
            isToBeDeleted= true;
            //this->release();
            //(LevelOneScene*)parent->getParent();
            //delete this;
            gameOver = true;
        }else{
            gameOver=false;}
        
    }
    if(hasFired == true){
        auto moveRight = MoveTo::create(missileSpeed, Point((visibleSize.width+200),this->getPosition().y));
        this->runAction(moveRight);
        hasFired = true;
        
    }
    if(timeUntilFire>.75)
    {
        hasFired=true;
    }
}

