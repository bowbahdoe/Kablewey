//
//  MissileMovementLoop.h
//  Kablewey
//
//  Created by Ethan McCue on 6/2/14.
//
//

#ifndef __Kablewey__MissileMovementLoop__
#define __Kablewey__MissileMovementLoop__


#include <cocos2d.h>
USING_NS_CC;
class MissileMovementLoop: public cocos2d::Component
{
public:
    MissileMovementLoop();
    //void update(float delta);
private:
    virtual void onEnter();
    virtual void update(float delta);
    
    void actionMove();
};
#endif /* defined(__Kablewey__MissileMovementLoop__) */
