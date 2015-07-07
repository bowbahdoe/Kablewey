//
//  RedMissile.h
//  Kablewey
//
//  Created by John McCue on 6/26/14.
//
//

#ifndef __Kablewey__RedMissile__
#define __Kablewey__RedMissile__
#include <cocos2d.h>
#include "Missile.h"
#define missileFlyDuration 1
using namespace cocos2d;
class RedMissile: public Missile
{
public:
    RedMissile();
    void update(float dt,float missileSpeed);
    bool isToBeDeleted;
    bool getIsOffscreen(void);
private:
    bool isOffscreen;
    float missileSpeed;
    bool hasFired;
    float timeUntilFire;
};


#endif /* defined(__Kablewey__RedMissile__) */
