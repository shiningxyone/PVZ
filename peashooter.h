#pragma once
#include"plant.h"

#define PEASHOOTER_RATE 1.5f
#define PEASHOOTER_BLOOD 300

class Peashooter :public Plant {
public:
	Peashooter() { init_plant(); };
	~Peashooter() = default;
	virtual void init_plant();//��ʼ��ֲ������
	virtual void init_animation();//ֲ�ﶯ��
	virtual void delete_(float);//ɾ��ֲ��

};
