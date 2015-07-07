//
//  EnemyShip.cpp
//  Kablewey
//
//  Created by Ethan McCue on 5/25/14.
//
//

#include "EnemyShip.h"
#include "ErraticMovement.h"
#include "LevelOneScene.h"
#include "MCMacros.h"
#include "RoundHandler.h"
#include <cmath>
#include "Settings.h"
EnemyShip::EnemyShip()
{
    initWithFile("ENEMY.png");
    timeSinceUpdate=0;
    _status = isIdle;

}
void EnemyShip::changePos(float dt)
{
    
    auto parent =((LevelOneScene*)getParent());
    auto size =parent->visibleSize;
    auto height = size.height;
    
    auto newY =  (rand() % (int)(height + 1));
    
    auto round = parent->getRoundHandler()->getRound();
    if(round%2==0 and not CLASSIC_MODE)
    {//If we are on a delay round this will be true
        auto mis = new Missile();
        while((newY>height-mis->getContentSize().width or newY<(mis->getContentSize().width)) and not(isFarEnoughAway()))
        {
            newY = (rand() % (int)(height + 1));
        }
        //TODO  better random movement
        auto newLoc = Point( this->getPosition().x,(newY ));
        timeSinceUpdate +=dt;
        
        if(timeSinceUpdate>.4)
        {
            
            auto moveAction = MoveTo::create(dt*10,newLoc);
            this->runAction(moveAction);
            timeSinceUpdate = 0;
            status = isIdle;
            
        }
        
        if(round==round_1)
        {
            
            auto missiles_to_fire = 3;
        

    
            if( (timeSinceUpdate>((rand()%40+1)/10.0)) and _status==isIdle and missiles_to_fire>0)
            {
                //Fire a missile
                parent->addMissile(this->getPositionX(),this->getPositionY());
                status = isFiring;
                missiles_to_fire-=1;
            }
            lastLoc = this->getPosition();
            if(missiles_to_fire<=0)
            {
                parent->getRoundHandler()->addTime(999999);///will force switch of round
            }

        }

        else if (round==round_2)
        {
            if(timeSinceUpdate>((rand()%40+1)/10.0) and _status==isIdle)
            {
                if(isFarEnoughAway())
                {
                //Fire a missile
                    parent->addMissile(this->getPositionX(),this->getPositionY());
                    status = isFiring;
                    lastLoc = this->getPosition();
                }
    
            }
        }
        else if (round==round_3)
        {
            if(timeSinceUpdate>((rand()%25+1)/10.0) and _status==isIdle)
            {
                
                if((rand()%5+1) == 1 and isFarEnoughAway())
                {
                    parent->addRedMissile(this->getPositionX(),this->getPositionY());;
                    status = isFiring;
                    lastLoc = this->getPosition();
                }
                //Fire a missile
                else if (isFarEnoughAway())
                {
                    parent->addMissile(this->getPositionX(),this->getPositionY());
                    lastLoc = this->getPosition();
                    status = isFiring;
                    //                /CCLOG("%f",parent->getMissileSpeed());
                }
            }
        }
        else if (round==round_4)
        {
            if(timeSinceUpdate>((rand()%20+1)/10.0) and _status==isIdle)
            {
                
                if((rand()%5+1) > 3 and isFarEnoughAway())
                {
                    parent->addRedMissile(this->getPositionX(),this->getPositionY());;
                    status = isFiring;
                    lastLoc = this->getPosition();
                }
                //Fire a missile
                else if(isFarEnoughAway())
                {
                    parent->addMissile(this->getPositionX(),this->getPositionY());
                    status = isFiring;
                    lastLoc = this->getPosition();
                    //                /CCLOG("%f",parent->getMissileSpeed());
                }
            }
            
        }
        else if(round==round_5)
        {
            
            if(status == isIdle and isFarEnoughAway() and (timeSinceUpdate>((rand()%20+1)/10.0)))
            {
                if((rand()%5+1) >3)
                {
                    CCLOG("MISSILE FIRED");
                    parent->addRedMissile(this->getPositionX(),this->getPositionY());;
                    status = isFiring;
                    lastLoc = this->getPosition();
                }
                else
                {
                    parent->addMissile(this->getPositionX(),this->getPositionY());
                    status = isFiring;
                    lastLoc = this->getPosition();
                }
            }
        }
    }
    
    if(CLASSIC_MODE)
    {
        auto parent =((LevelOneScene*)getParent());
        auto size =parent->visibleSize;
        auto height = size.height;
        
        auto newY =  (rand() % (int)(height + 1));
        while(newY<height/64 or newY>(height-(height/64)))
        {
            newY = (rand() % (int)(height + 1));
        }
        //TODO  better random movement
        auto newLoc = Point( this->getPosition().x,(newY ));
        timeSinceUpdate +=dt;
        
        if(timeSinceUpdate>((rand()%40+1)/10.0))
        {
            parent->addMissile(this->getPositionX(),this->getPositionY());
        }
        if(timeSinceUpdate>.4)
        {
            
            auto moveAction = MoveTo::create(dt*10,newLoc);
            this->runAction(moveAction);
            timeSinceUpdate = 0;
            
        }
        

    }

    
}
void EnemyShip::animate(float dt)
{
    if(status==isIdle)
    {
        ;
    }elif(status==isFiring)
    {
        Vector<SpriteFrame*> animFrames(3);
        char str[100] = {0};
        sprintf(str, "ENEMY.png");
        auto frame = SpriteFrame::create(str,Rect(0,0,120,120));
        animFrames.pushBack(frame);
        
        sprintf(str, "ENEMY_FIRING.png");
        frame = SpriteFrame::create(str,Rect(0,0,120,120));
        animFrames.pushBack(frame);
        
        sprintf(str, "ENEMY_FIRING.png");
        frame = SpriteFrame::create(str,Rect(0,0,120,120));
        animFrames.pushBack(frame);
        
        
        auto animation = Animation::createWithSpriteFrames(animFrames);
        animationToRun = Animate::create(animation);
        this->runAction(animationToRun);
        status = isIdle;
        
    }
        

        
        //timeSinceUpdate = 0;
        //CCLOG("Firing");
        //Animation * anim = Animation::create();
        
        //anim->addSpriteFrameWithFile("ENEMY.png");
        //anim->addSpriteFrameWithFile("BOSS.png");
        
        //Animate* fire = Animate::create(anim);
        //fire->setDuration(1.1);
        //this->runAction(fire);
    
    
}
bool EnemyShip::isFarEnoughAway(void)
{
    auto missile = new Missile();
    auto contentWidth = missile->getContentSize().width;
    delete missile;
    if(abs(lastLoc.y - this->getPositionY())>(contentWidth*1.5))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void EnemyShip::update(float dt)
{
    changePos(dt);
    animate(dt);
}