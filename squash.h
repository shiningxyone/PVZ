#pragma once
#include"plant.h"

#define SQUASH_BLOOD 300
#define SQUASH_RATE 0

class Squash :public Plant {
public:
	Squash() { init_plant(); };
	~Squash() = default;
	virtual void init_plant();//��ʼ��ֲ������
	virtual void init_animation();//ֲ�ﶯ��
	virtual void delete_();//ɾ��ֲ��
	virtual void attack_animation();//��������

};
