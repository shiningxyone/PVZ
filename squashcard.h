#pragma once
#include"card.h"
#include "ui/CocosGUI.h"
using namespace ui;
class Squashcard :public Card {
public:
	Squashcard() {
		this->card_init();
		this->scheduleUpdate();
	};
	~Squashcard() = default;
	virtual void card_init();//��ʼ��
	virtual void cold_animation();//��Ƭ��ȴ����
	virtual void update(float);
	float timecount;//��ʱ��
};