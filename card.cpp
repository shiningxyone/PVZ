#include"card.h"




void Card::getsun(int s) {
	sunnum = s;
}
void Card::set_cold(bool c) {
	cold = c;
}
void Card::set_choose(bool c) {
	choose = c;
}
bool Card::is_choose() {
	return choose;
}
bool Card::is_cold() {
	return cold;
}
Rect Card::getrect() {
	//���Ͻ�x����
	float cardx = this->sprite->getPosition().x -
		this->sprite->getContentSize().width * this->sprite->getAnchorPoint().x;
	//���Ͻ�y����
	float cardy = this->sprite->getPosition().y -
		this->sprite->getContentSize().height * this->sprite->getAnchorPoint().y;
	float w = this->sprite->getContentSize().width;//���
	float h = this->sprite->getContentSize().height;//�߶�
	return Rect(cardx, cardy, w, h);
}
void Card::move_animation(Vec2& des) {
	auto moveTo = MoveTo::create(0.1, des);
	this->runAction(moveTo);
}
