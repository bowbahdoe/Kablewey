//
//  MissileMovementLoop.cpp
//  Kablewey
//
//  Created by Ethan McCue on 6/2/14.
//
//

#include "MissileMovementLoop.h"
#include "Missile.h"
void MissileMovementLoop::update(float delta){
Missile* parent = (Missile*)getOwner();
if(parent==NULL)
{
    return;
}else{
    auto moveDown = MoveTo::create(missileFlyDuration, Point(0,parent->getPosition().x));
    parent->runAction(moveDown);
}
}