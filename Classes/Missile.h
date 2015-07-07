//
//  Missile.h
//  Kablewey
//
//  Created by Ethan McCue on 6/2/14.
//
//

#ifndef __Kablewey__Missile__
#define __Kablewey__Missile__
#include <cocos2d.h>

#define missileFlyDuration 1
using namespace cocos2d;
class Missile: public Sprite
{
public:
    Missile();
    //~Missile();
    virtual void update(float dt,float missileSpeed);
     bool isToBeDeleted;
private:
   
    float missileSpeed;
    bool hasFired;
    float timeUntilFire;
};


#endif /* defined(__Kablewey__Missile__) */
