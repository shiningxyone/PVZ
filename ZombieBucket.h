#ifndef __ZOMBIEBUCKET_H__
#define __ZOMBIEBUCKET_H__

#include "cocos2d.h"
#include "ZombieBase.h"
USING_NS_CC;

class ZombieBucket : public ZombieBase
{
public:
    virtual bool init();
    virtual void initmove();//��ʼ�ƶ�����
    virtual void initattack();//��ʼ��������
    virtual void initdie();//��ʼ��������
    CREATE_FUNC(ZombieBucket);

};




#endif // __ZOMBIEBUCKET_H__
