#pragma once
#include"card.h"
#include "ui/CocosGUI.h"
using namespace ui;
class Peashootercard :public Card {
public:
	Peashootercard() {
		this->card_init();
		sprite = Sprite::create();
		sprite->setColor(Color3B::GRAY);
		this->scheduleUpdate();
	};
	~Peashootercard() = default;
	virtual void card_init();//��ʼ��
	virtual void cold_animation();//��Ƭ��ȴ����
	virtual void update(float);
	float timecount;//��ʱ��
};