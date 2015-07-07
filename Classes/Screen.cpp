//
//  Screen.cpp
//  Kablewey
//
//  Created by Ethan McCue on 6/10/14.
//
//

#include "Screen.h"
#include <cocos2d.h>
USING_NS_CC;
bool isLandscape(void)
{
    if(!isPortrait())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isPortrait(void)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    if(visibleSize.width < visibleSize.height)
    {
        return true;
    }
    else
    {
        return false;
    }
}