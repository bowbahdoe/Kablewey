//
//  MenuScene.cpp
//  Rabbits
//
//  Created by Ethan McCue on 5/17/14.
//
//

#include "MenuScene.h"
#include "LevelOneScene.h"
#include "ScoreKeeper.h"
USING_NS_CC;
extern int Halophile;
Scene* MenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MenuScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto changeScene = MenuItemImage::create("START_BUTTON__NOT_CLICKED.png",
                                             "START_BUTTON_CLICKED.png",
                                             CC_CALLBACK_1(MenuScene::changeScene,this));
    //auto closeItem = MenuItemImage::create(
    //                                       "CloseNormal.png",
     //                                      "CloseSelected.png",
     //                                      CC_CALLBACK_1(MenuScene::menuCloseCallback, this));
    changeScene->setPosition(Point(origin.x + visibleSize.width/2 ,
                                   origin.y + visibleSize.height/4));
	//closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
    //                             origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(changeScene, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    
    auto label = LabelTTF::create("KABLEWEY", "", 48);//    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("MenuBackground.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

    

    
    return true;
}


//MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");

void MenuScene::changeScene(cocos2d::Ref* pSender)
{
    Director::getInstance()->replaceScene(LevelOneScene::createScene());
    
}
