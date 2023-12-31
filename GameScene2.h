
#ifndef __GAMESCENE2_H__
#define __GAMESCENE2_H__

#include "cocos2d.h"
#include "ZombieNormal.h"
#include "ZombieBase.h"
#include "ZombieFlag.h"
#include "ZombieBucket.h"
#include "Car.h"
#include "MenuScene.h"
#include"sunflower.h"
#include"sunflowercard.h"
#include "WinScene.h"
#include "LoseScene.h"

USING_NS_CC;

class GameScene2 : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    virtual void update(float);
    // a selector callback
    void createcar();
    void  createplant();
    Vector<ZombieBase*> zombienumber;//���ڱ����Ѿ������Ľ�ʬ
    Vector<Car*> carnumber;//��������
    CREATE_FUNC(GameScene2);
    int gametime = 0;
    void createzombie();
    ZombieBase* get_row_left_zombie(int row_);

};

#endif // __GAMESCENE2_H__
