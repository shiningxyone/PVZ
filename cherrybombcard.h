#pragma once
#include"card.h"
#include "ui/CocosGUI.h"
using namespace ui;
class Cherrybombcard :public Card {
public:
	Cherrybombcard() {
		this->card_init();
		this->scheduleUpdate();
	};
	~Cherrybombcard() = default;
	virtual void card_init();//��ʼ��
	virtual void cold_animation();//��Ƭ��ȴ����
	virtual void update(float);
	float timecount;//��ʱ��
};