#pragma once
#include"plant.h"

#define SUNFLOWER_BLOOD 300
#define SUNFLOWER_RATE 10

class Sunflower :public Plant {
public:
	Sunflower() { init_plant(); };
	~Sunflower() = default;
	virtual void init_plant();//��ʼ��ֲ������
	virtual void init_animation();//ֲ�ﶯ��
	virtual void delete_();//ɾ��ֲ��


};
