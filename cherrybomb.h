#pragma once
#include"plant.h"

#define CHERRY_BLOOD 0
#define CHERRY_RATE 0

class Cherrybomb :public Plant {
public:
	Cherrybomb() { init_plant(); };
	~Cherrybomb() = default;
	virtual void init_plant();//��ʼ��ֲ������
	virtual void init_animation();//ֲ�ﶯ��
	virtual void delete_();//ɾ��ֲ��

};
