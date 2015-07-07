//
//  MenuScene.h
//  Rabbits
//
//  Created by Ethan McCue on 5/17/14.
//
//

#ifndef __Rabbits__MenuScene__
#define __Rabbits__MenuScene__
#include <cocos2d.h>
#include "ScoreKeeper.h"
#ifndef _cplusplus
#define _cplusplus
#endif
using namespace cocos2d;
class MenuScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    //void menuCloseCallback(cocos2d::Ref* pSender);
    void changeScene(cocos2d::Ref* pSender);
    

    ScoreKeeper* scoreKeeper;
    


    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);
};

#endif /* defined(__Rabbits__MenuScene__) */
