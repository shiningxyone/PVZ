#pragma once
#include"card.h"
#include "ui/CocosGUI.h"
using namespace ui;
class Sunflowercard :public Card {
public:
	Sunflowercard() {
		this->card_init();
		this->scheduleUpdate();
	};
	~Sunflowercard() = default;
	virtual void card_init();//��ʼ��
	virtual void cold_animation();//��Ƭ��ȴ����
	virtual void update(float);
	float timecount;//��ʱ��
	
};