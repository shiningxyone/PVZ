#include"peashootercard.h"

void Peashootercard::update(float tim) {
	timecount += tim;
	if (is_cold()) {//������ȴ״̬��������ȴ����
		cold_animation();
		timecount = 0;
	}
	if (timecount > card_cd) {
		cold = false;
	}
}
void Peashootercard::card_init() {
	card_cd = 20;//��ȴʱ��20s
	cost = 100;//50̫��
	cold = false;//������ȴ״̬
	ct = PEASHOOTER_CARD;
}
void Peashootercard::cold_animation() {
	auto cd1 = FadeOut::create(0.1);
	auto cd2 = FadeIn::create(card_cd);
	auto cd_seq = Sequence::create(cd1, cd2, nullptr);
	this->sprite->runAction(cd_seq);
}