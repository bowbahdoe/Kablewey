//
//  EnemyShip.h
//  Kablewey
//
//  Created by Ethan McCue on 5/25/14.
//
//

#ifndef __Kablewey__EnemyShip__
#define __Kablewey__EnemyShip__
#include <cocos2d.h>

using namespace cocos2d;
typedef enum
{
    isIdle,
    isFiring,
}EnemyShipStatus;
class EnemyShip: public Sprite
{
public:
    EnemyShip();
    void changePos(float dt);
    void update(float dt);
    EnemyShipStatus status;
private:
    Animate* animationToRun;
    float timeSinceUpdate;
    void animate(float dt);
    EnemyShipStatus _status;
    Point lastLoc;
    bool isFarEnoughAway(void);
};

#endif /* defined(__Kablewey__EnemyShip__) */
