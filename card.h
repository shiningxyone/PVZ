#pragma once
/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#include "cocos2d.h"
#include<string>
#include "ui/CocosGUI.h"
//#include"plant.h"
USING_NS_CC;

enum CardType {
	SUNFLOWER_CARD,//̫����0
	PEASHOOTER_CARD,//�㶹����1
	WALLNUT_CARD,//���ǽ2
	CHERRYBOMB_CARD//ӣ��ը��3
};

class Card :public Sprite {
public:
	//��Ա
	float card_cd;//��Ƭ��ȴʱ��
	Sprite* sprite;//����
	Sprite* cd_sprite;
	int sunnum;//��������
	int cost;//�۸�
	FadeIn* cardfade;//��Ƭ��ȴ����
	bool choose;//�Ƿ�ѡ��
	Rect rect;
	bool cold;//�ж���ȴ
	CardType ct;//��Ƭ����
	Vec2 pos;
	//����
	Card() = default;
	~Card() = default;
	bool is_choose();//�ж��Ƿ�ѡ��
	bool is_cold();//�ж��Ƿ�����ȴ״̬
	Rect getrect();//��ȡ��Ƭ��Χ
	void getsun(int);//��ȡ��������

	Sprite* sprite_init(const std::string name, Vec2 pos0) {
		sprite = Sprite::create("card_" + name + ".png");
		//sprite->setScale(0.9f);
		sprite->setPosition(pos0);
		pos = pos0;
		return sprite;
	};//��ʼ������
	Sprite* cd_sprite_init(const std::string name, Vec2 pos0) {
		cd_sprite = Sprite::create("card_" + name + ".png");
		cd_sprite->setPosition(pos0);
		return cd_sprite;
	};
	virtual void card_init() {};
	virtual void cold_animation() {};
	virtual void move_animation(Vec2&);//��Ƭ�ƶ�����
	virtual void set_cold(bool);//�����Ƿ���ȴ
	virtual void set_choose(bool);//�����Ƿ���ȴ
};
