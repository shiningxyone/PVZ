#include"sun.h"
#include<string>
USING_NS_CC;

using namespace ui;
SUN::SUN() {
    num_sun = 0;//�Լ����������
    time_sun=0.0;//���Ᵽ��ʱ��
    collection=0;//�ռ���������
    sunsprite = Sprite::create("sun.png");//��̫��ͼƬ����spirit
    
    //Layer::getInstance()->addChild(spSun, 202);
}
SUN::SUN(int producedby) {
    num_sun = 0;//�Լ����������
    time_sun = 0.0;//���Ᵽ��ʱ��
    collection = 0;//�ռ���������
    sunsprite = Sprite::create("sun.png");//��̫��ͼƬ����spirit
  
    if (producedby == sky) {
        producesun();
        num_sun++;
    }
    if (producedby == sunflower) {

    }
}
SUN::~SUN() {
}
void SUN::jump(Vec2& position_) {
    sunsprite->setScale(0.2f);
    sunsprite->setPosition(position_.x, position_.y);
    auto fadeIn = FadeIn::create(1.0f);
    sunsprite->runAction(fadeIn);
}

void SUN::producesun() {
    sunsprite->setScale(0.2f);
    
    srand((unsigned int)(time(0)));
  
    sunsprite->setPosition(Vec2(rand()%X_MAX,Y_MAX-100));//λ��������������Ϸ�
    /*auto listener1 = EventListenerMouse::create();
    listener1->onMouseDown = CC_CALLBACK_1(SUN::onMouseDown, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);*/
}
void SUN::move_1() {

   
    Vec2 position = sunsprite->getPosition();
    auto moveTo = MoveTo::create(2, Vec2(position.x, 30));

    auto rotateBy = RotateBy::create(2.0f, 360.0f);//�涨��ʱ�䣨����������

    auto fallSpawn = Spawn::createWithTwoActions(moveTo, rotateBy);//ͬʱִ���������ת
    auto seq = Sequence::create(fallSpawn,nullptr);
    sunsprite->runAction(seq);
} //����+��ת��animate��+ֹͣ

void SUN::move_2() {
    sunsprite->stopAllActions();//ֹͣ����
    sunsprite->setScale(0.2f);
    auto moveToup = MoveTo::create(1.5f, Vec2(40, Y_MAX-35));
    auto scaleTo = ScaleTo::create(1.0f, 0.1f);
    auto fadeOut = FadeOut::create(1.0f);
    auto removeSelf = RemoveSelf::create();
  

    auto seq = Sequence::create(moveToup,scaleTo, fadeOut, nullptr);

    sunsprite->runAction(seq);
}//�ɵ����Ͻǣ�Ȼ����С�����Ͻ����꣨0��ymax��

void SUN::onMouseDown(Event* event)
{
    //��ȡ�¼�
    EventMouse* e = (EventMouse*)event;
    //��ȡԪ��
   // auto ui = this->getChildByTag(666);
   // auto button = ui->getChildByTag(4);
    //��ȡ����¼�����������->�޶���ť��Χ
   if (e->getCursorX() >= sunsprite->getPositionX() - 100 && e->getCursorX() <= sunsprite->getPositionX() + 100
        && e->getCursorY() >= sunsprite->getPositionY() - 60 && e->getCursorY() <= sunsprite->getPositionY() + 60)
    /*if (e->getCursorX() >= 0 && e->getCursorX() <= X_MAX
        && e->getCursorY() >= 0 && e->getCursorY() <= Y_MAX)*/
    {
        move_2();
        collection=1;
        num_sun--;
    }
   collection = std::min(1, collection);
}

void SUN::collectsun() {
   
}//��������¼��������+�����������Ȼ����û����¼����ռ���������+1��Ŀǰ��������-1