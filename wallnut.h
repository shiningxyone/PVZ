#pragma once
#include"plant.h"

#define WALLNUT_BLOOD 1000
#define WALLNUT_RATE 10

class Wallnut :public Plant {
public:
	Wallnut() { init_plant(); };
	~Wallnut() = default;
	virtual void init_plant();//��ʼ��ֲ������
	virtual void init_animation();//ֲ�ﶯ��
	virtual void delete_();//ɾ��ֲ��
	
};
