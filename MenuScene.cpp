#include "MenuScene.h"

Scene* MenuScene::createScene()
{
    return MenuScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }
    AudioEngine::stopAll();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backgroundAudioID = AudioEngine::play2d("music/menu.mp3", true);

    auto Menubackground = Sprite::create("Menu/Menu.png");
    Menubackground->setScale(1.14f);
    Menubackground->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(Menubackground, 0);

    auto startbutton = MenuItemImage::create(
        "Menu/menu1.png",
        "Menu/menu2.png",
        CC_CALLBACK_1(MenuScene::gamescene, this));
    startbutton->setScale(1.25f);
    startbutton->setPosition(Vec2(720, 460));

    auto exitlabel = Label::createWithTTF("Exit", "fonts/Marker Felt.ttf", 30);
    auto exitbutton = MenuItemLabel::create(exitlabel, CC_CALLBACK_1(MenuScene::exit, this));
    exitbutton->setPosition(Vec2(950, 40));
    exitbutton->setColor(Color3B(75, 75, 75));

    auto menu = Menu::create(startbutton, NULL);
    menu->setPosition(Vec2::ZERO);
    menu->addChild(exitbutton);
        this->addChild(menu, 1);

    return true;
}


void MenuScene::gamescene(Ref* pSender)
{
    AudioEngine::stopAll();
Director::getInstance()->replaceScene(GameScene::createScene());
}

void MenuScene::exit(Ref* pSender)
{
    Director::getInstance()->end();
}