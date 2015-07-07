//
//  RedMissile.cpp
//  Kablewey
//
//  Created by John McCue on 6/26/14.
//
//

#include "RedMissile.h"
#include <cmath>
extern bool gameOver;
RedMissile::RedMissile()
{
    isToBeDeleted = false;
    isOffscreen = false;
    hasFired = false;
    timeUntilFire = 0;
    initWithFile("Red_Missile.png");
}
void RedMissile::update(float dt, float missileSpeed)
{
    //this->stopAllActions();//TO be taken out
    timeUntilFire+=dt;
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    if(this->getPositionX()>visibleSize.width+this->getContentSize().width)
    {
        isOffscreen = true;
        
    }
    if(hasFired == true){
        auto moveRight = MoveTo::create(missileSpeed,
                                        Point((visibleSize.width+200),this->getPosition().y));
        this->runAction(moveRight);
    }
    if(isOffscreen)
    {
        isToBeDeleted=true;
    }
    if(timeUntilFire>1.5)
    {
        hasFired=true;
    }
}
bool RedMissile::getIsOffscreen(void)
{
    return isOffscreen;
}
