//
//  Ship.h
//  Kablewey
//
//  Created by Ethan McCue on 5/24/14.
//
//

#ifndef __Kablewey__Ship__
#define __Kablewey__Ship__
#include<cocos2d.h>
using namespace cocos2d;
class Ship: public Sprite
{
public:
    Ship();
    void changePos();
};

#endif /* defined(__Kablewey__Ship__) */
