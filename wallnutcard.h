#pragma once
#include"card.h"
#include "ui/CocosGUI.h"
using namespace ui;
class Wallnutcard :public Card {
public:
	Wallnutcard() {
		this->card_init();
		this->scheduleUpdate();
	};
	~Wallnutcard() = default;
	virtual void card_init();//��ʼ��
	virtual void cold_animation();//��Ƭ��ȴ����
	virtual void update(float);
	float timecount;//��ʱ��
};
