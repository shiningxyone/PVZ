#pragma once
#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__
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
#include"plant.h"
#include"sunflower.h"
#include"peashooter.h"
#include"wallnut.h"
#include"cherrybomb.h"
#include"card.h"
#include"sunflowercard.h"
#include"peashootercard.h"
#include"wallnutcard.h"
#include"cherrybombcard.h"
#include"AudioEngine.h"
#include "ui/CocosGUI.h"
#include<vector>
#include"SUN.h"
#include"bullet.h"
USING_NS_CC;

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
  
    virtual bool init();
    virtual void update(float);
    // a selector callback
    void menuscene(cocos2d::Ref* pSender);
    void createcar();
    void  createplant();
    Vector<ZombieBase*> zombienumber;//���ڱ����Ѿ������Ľ�ʬ
    Vector<Car*> carnumber;//��������
    
    CREATE_FUNC(GameScene);
    int gametime = 0;
    void createzombie();
    ZombieBase* get_row_left_zombie(int row_);

    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    void plant(int row, int col, PlantType t);
    Sprite* mouse_s;
    PlantType ptype;
    // a selector callback
   
    void menuCloseCallback(Ref* pSender);
  
    std::vector<Card*>cards;
    std::vector<Plant*>plants;
    std::vector<Car*>cars;
    std::vector<Vec2>sunflowerpos;//���տ�����
    std::vector<Vec2>peashooterpos;//�㶹����
    Vec2 plant_pos[5][9];
    void compete_plant_pos();//�����к��м���Vec2
    bool compete_row_col(Vec2 vpos, int& row, int& col);//����Vec2�����к���
    double producetime;//���������ʱ��
    double producetime2;//�ӵ���ʱ��
    double producetime3;//���տ������ʱ��
    double producetime4;//��Ƭ��ȴ��ʱ��
    std::vector<SUN*> suns;
    std::vector<Bullet*> bullets;//���ӵ�
    /*Bullet* b = new Bullet;
						b->sprite_init(Vec2(ppos.x, ppos.y + 10));
						this->addChild(b->bulletsprite, 66);
						b->bullet_move(); //�ƶ������ұ�
						bullets.push_back(b);
						b->bullet_explode();//��ը����
						b->delete_sprite();//ɾ�����飬��֪����ʲô�ã��ȷ���
						bullets.pop_back();//���鵯���ӵ�Ԫ��
						����Ϊ��ȡ���ݵĺ���
						virtual Vec2 getposition() const; // ��ȡ��ά����
						virtual double getx() const; // getPositionX
						virtual double gety() const;
						virtual void set_crash(); // ����Ϊ��ײ����
						virtual bool judge_crash(); // ����bool is_crash; �Ƿ���ײ���жϱ���   true:��ײ  false��δ��ײ
						virtual void set_attack_num(double damage);// �����ӵ��˺�*/
    Label* sun_num;
};

#endif // __GAMESCENE_H__
