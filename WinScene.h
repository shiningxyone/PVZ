
#ifndef __WINSCENE_H__
#define __WINSCENE_H__

#include "cocos2d.h"
#include "ZombieNormal.h"
#include "ZombieBase.h"
#include "ZombieFlag.h"
#include "ZombieBucket.h"
#include "Car.h"
#include "GameScene.h"

USING_NS_CC;

class WinScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuscene(cocos2d::Ref* pSender);
    void nextscene(cocos2d::Ref* pSender);


    CREATE_FUNC(WinScene);
};

#endif // __WINSCENE_H__