#include"card.h"

void Card::sprite_init(std::string name, Vec2 pos)
{
	sprite = Sprite::create(name + "_card.png");
	sprite->setPosition(pos);

}
void Card::cd_sprite_init(std::string name, Vec2 pos)
{
	cd_sprite = Sprite::create(name + "_card.png");
	cd_sprite->setPosition(pos);

}
void Card::getsun(int s) {
	sunnum = s;
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