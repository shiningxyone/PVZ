#include "WinScene.h"

Scene* WinScene::createScene()
{
    return WinScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool WinScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto Menubackground = Sprite::create("GameVictory.png");
    Menubackground->setScale(1.4f);
    Menubackground->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y-80));
    this->addChild(Menubackground, 0);

    auto closebutton = MenuItemImage::create(
        "Menu/close.png",
        "Menu/close.png",
        CC_CALLBACK_1(WinScene::manuscene, this));
    closebutton->setScale(1.25f);
    closebutton->setPosition(Vec2(950, 550));

    auto menu = Menu::create(closebutton, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    return true;
}


void WinScene::manuscene(Ref* pSender)
{
    Director::getInstance()->replaceScene(MenuScene::createScene());
}


