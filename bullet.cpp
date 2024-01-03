#include"bullet.h"

USING_NS_CC;


Bullet::Bullet() {
    bullet_init();
}

bool Bullet::bullet_init() {
    if (!Node::init())
        return false;
    // ��ʼ���ӵ�
    attack_num = 0;
    is_crash = false;
    sprite_init(position);
    scheduleUpdate();
    return true;

}


void Bullet::bullet_explode() {
    bulletsprite->stopAllActions();//ֹͣ����
    Animation* animation = Animation::create();
    animation->addSpriteFrameWithFile("pea.png");
    animation->addSpriteFrameWithFile("peaexplode.png");
    animation->setDelayPerUnit(0.1f);
    bullet_explode_animate = Animate::create(animation);
    bulletsprite->runAction(Repeat::create(bullet_explode_animate,1));
}//���ײ������ը����

void Bullet::bullet_move() {
    bulletsprite->runAction(MoveTo::create(3.0f, Vec2(1000, position.y)));//һֱ�ƶ�
}

void Bullet::sprite_init(const Vec2& pos) {
    // ��ʼ������
    bulletsprite = Sprite::create("pea.png");
    position = pos;
    bulletsprite->setPosition(position);
  
}

Vec2 Bullet::getposition() const {
    // ��ȡ�ӵ���λ��
    return this->getPosition();
}

double Bullet::getx() const {
    // ��ȡ�ӵ���x����
    return this->getPositionX();
}

double Bullet::gety() const {
    // ��ȡ�ӵ���y����
    return this->getPositionY();
}

void Bullet::set_crash() {
    // �����ӵ�����ײ״̬
    is_crash = true;
}

bool Bullet::judge_crash() {
    // �ж��ӵ��Ƿ���ײ
    return is_crash;
}

void Bullet::set_attack_num(double damage) {
    // �����ӵ����˺�ֵ
    attack_num = damage;
}

void Bullet::delete_sprite() {
    // ɾ������
    bulletsprite->runAction( RemoveSelf::create());
    
}


