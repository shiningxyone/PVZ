#ifndef __ZOMBIEBASE_H__
#define __ZOMBIEBASE_H__
#include "cocos2d.h"
USING_NS_CC;

enum ZombieType {
    zombienormal, // ��ͨ��ʬ
    zombiebucket,// ��Ͱ��ʬ
    zombieflag //���Ľ�ʬ
};

class ZombieBase : public Node
{
public:
    ZombieBase() = default;
    ~ZombieBase() = default;
    virtual bool init();//��ʼ��
    void setstate(int);//����״̬
    void setmoverate(float);//�����ƶ��ٶ�
    void setrow(int);//������
    void setmovelength(int);//�����ƶ�����
     Vec2 getposiition() const;//����vec2����
     float getx() const;//����x
     float gety() const;//����y
     double gethp() const;//��������ֵ
     double getattack() const;//���ع���ֵ
     double getstate() const;//����״̬
     int getrow() const;//������
    virtual ZombieType gettype() const;//���ؽ�ʬ����
     void runaction();//���Ŷ���
    void takedamagefromcar();//�ܵ��˺���С��
    void takedamagefromplant(int value);//�ܵ��˺���ֲ��
    virtual void initmove();//��ʼ�ƶ�����
    virtual void initattack();//��ʼ��������
    virtual void initdie();//��ʼ��������
    CREATE_FUNC(ZombieBase);

    Sprite* zombie;//����
    double hp;//����ֵ
    float moverate;//�ƶ��ٶ�
    float movetime;//�ƶ�ʱ��
    int movelength;//�ƶ�����
    int attack;//����ֵ
    int state=1;//״̬ 1���ƶ�  2������  3������
    Vector<SpriteFrame*> moveanimFrames;//�ƶ�����֡
    Vector<SpriteFrame*> attackanimFrames;//��������֡
    Vector<SpriteFrame*>dieanimFrames;//��������֡

    ZombieType type;//��ʬ����
    int row;//��
};




#endif // __ZOMBIEBASE_H__
