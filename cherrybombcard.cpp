#include"cherrybombcard.h"

void Cherrybombcard::update(float tim) {
	timecount += tim;
	if (is_cold()) {//������ȴ״̬��������ȴ����
		cold_animation();
		timecount = 0;
	}
	if (timecount > card_cd) {
		cold = false;
	}
}
void Cherrybombcard::card_init() {
	card_cd = 10;//��ȴʱ��20s
	cost = 125;//125̫��
	cold = false;//������ȴ״̬
	ct = CHERRYBOMB_CARD;
}
void Cherrybombcard::cold_animation() {
	auto cd1 = FadeOut::create(0.1);
	auto cd2 = FadeIn::create(card_cd);
	auto cd_seq = Sequence::create(cd1, cd2);
	this->sprite->runAction(cd_seq);
}