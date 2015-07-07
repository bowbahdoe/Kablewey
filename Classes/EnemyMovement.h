//
//  EnemyMovement.h
//  Kablewey
//
//  Created by Ethan McCue on 5/25/14.
//
//

#ifndef __Kablewey__EnemyMovement__
#define __Kablewey__EnemyMovement__

#include <cocos2d.h>
using namespace cocos2d;

class EnemyMovement: public Component
{
public:
   // EnemyMovement();
private:
    Node* parent;
    virtual void update(float delta);
};

#endif /* defined(__Kablewey__EnemyMovement__) */
