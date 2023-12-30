#ifndef  _SUN_H_
#define  _SUN_H_
#include<vector>
#include "cocos2d.h"

USING_NS_CC;
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#define  X_MAX 900
#define  Y_MAX 600
#define  sky 0
#define  sunflower 1
class SUN :public cocos2d::Sprite
{
protected:
    int num_sun;//��Ļ�ϴ������������
    double time_sun;//���Ᵽ��ʱ��
    int collection;//�ռ���������
    Sprite* sunsprite;
    //�ж�̫������Ȼ��̫������
    void move_1() ;
    void producesun();
    void move_2();
    void collectsun();
public:
    void onMouseDown(Event* event);
    SUN();
    SUN(int);
    ~SUN();//�������Ᵽ��ʱ�䣬�Զ�������ʧ
    void start_move() {
        producesun();
        move_1();   //����+��ת��animate��+ֹͣ
    }
    void collected_callback()
    {
        collectsun();
    }//onMouseDown��갴�£�Ȼ��callback��֮�󲻽���
    void jump(Vec2& position_);
};

#endif