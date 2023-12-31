#include"sunflowercard.h"

void Sunflowercard::update(float tim) {
	timecount += tim;
	if (is_cold()) {//������ȴ״̬��������ȴ����
		cold_animation();
		timecount = 0;
	}
	if (timecount > card_cd) {
		cold = false;
	}
}
void Sunflowercard::card_init() {
	card_cd = 20;//��ȴʱ��20s
	cost = 50;//50̫��
	cold = false;//������ȴ״̬
	ct = SUNFLOWER_CARD;
}
void Sunflowercard::cold_animation() {
	//cold = true;
	auto cd1 = FadeOut::create(0.1);
	auto cd2 = FadeIn::create(card_cd);
	auto cd_seq = Sequence::create(cd1, cd2,nullptr);
	this->sprite->runAction(cd_seq);
	cold = false;
}