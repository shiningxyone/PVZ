#ifndef  _BULLET_H_
#define  _BULLET_H_
#include "cocos2d.h"
USING_NS_CC;

//����+ײ����ʬ��ÿһ�б������ҵ���ǰ��x_min�������ص�����+����˺�+��ʧ
//���տ��㶹����
class Bullet : public Node {
public:
	Bullet();
	~Bullet() = default;
	virtual bool bullet_init();// ��ʼ��

	virtual void bullet_move(); //�ӵ��ƶ�
	virtual void bullet_explode(); //�ӵ��ƶ�
	void sprite_init(const Vec2& pos);
	virtual Vec2 getposition() const; // ��ȡ��ά����
	virtual double getx() const; // getPositionX
	virtual double gety() const;
	virtual void set_crash(); // ����Ϊ�ж�
	virtual bool judge_crash(); // crash judgement, if ture, delete the bullet
	virtual void set_attack_num(double damage);// �����ӵ��˺�
	virtual void delete_sprite(); // ɾ������ 
	int row;
	//����
	Vec2 position; // ��ά����
	Sprite* bulletsprite; //�������
	double attack_num; // �����˺�
	bool is_crash; // �Ƿ���ײ   true:��ײ  false��δ��ײ
	Animate* bullet_explode_animate;
};



#endif