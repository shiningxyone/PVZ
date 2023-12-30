#include"clickandmove.h"
USING_NS_CC;
enum
{
    kTagSprite = 1,
};

ClickAndMove::ClickAndMove()
{
   
}
bool ClickAndMove::onTouchBegan(Touch* touch, Event* event)//������ʼ
{
	auto touchpos = touch->getLocation();
	std::vector<Card*>cards;
	for (auto& t : cards) {
		if (t->is_cold()||mouse_s!=nullptr)//������ȴ���ÿ�����ѡ
			continue;
		double w = t->sprite->getContentSize().width / 2;
		double h = t->sprite->getContentSize().height / 2;
		Vec2 cardpos = t->sprite->getPosition();
		auto len = cardpos - touchpos;

		

		if (fabs(len.x) < w && fabs(len.y) < h)//����ڿ�Ƭ��
		{
			switch (t->ct)
			{
			case PEASHOOTER_CARD:
			{
				Peashooter* pea = new Peashooter;
				mouse_s = pea->run_animation(t->sprite->getPosition());
				this->addChild(mouse_s, 1);
				ptype = PlantType::PEASHOOTER;
				break;
			}
			case SUNFLOWER_CARD:
			{
				Sunflower* sunf = new Sunflower;
				mouse_s = sunf->run_animation(t->sprite->getPosition());
				this->addChild(mouse_s, 1);
				ptype = PlantType::SUNFLOWER;
				break;
			}
			case WALLNUT_CARD:
			{
				Wallnut* wal = new Wallnut;
				mouse_s = wal->run_animation(t->sprite->getPosition());
				this->addChild(mouse_s, 1);
				ptype = PlantType::WALLNUT;
				break;
			}
			case SQUASH_CARD:
			{
				Squash* squ = new Squash;
				mouse_s = squ->run_animation(t->sprite->getPosition());
				this->addChild(mouse_s, 1);
				ptype = PlantType::SQUASH;
				break;
			}
			case CHERRYBOMB_CARD:
			{
				Peashooter* che = new Peashooter;
				mouse_s = che->run_animation(t->sprite->getPosition());
				this->addChild(mouse_s, 1);
				ptype = PlantType::CHERRYBOMB;
				break;
			}
			default:
				break;
			}
			return true;
		}
	}
	return false;
}

void ClickAndMove::onTouchMove(Touch* touch, Event* event) {
	int row, col;
	mouse_s->setPosition(touch->getLocation());
}

void ClickAndMove::onTouchEnded(Touch* touch, Event* event)//��������
{
	//���λ���ڸ�����!
	//��λ����ֲ��!
	auto touchpos = touch->getLocation();
	int row, col;
	//��ȡ������Ϣ!
	plant(row,col,ptype);

	ptype = NONE;
	this->removeChild(mouse_s,1);
	mouse_s = nullptr;
   
}

void ClickAndMove::plant(int row, int col, PlantType pt) {
	//�����к��м�������!
	Vec2 plantpos;
	Card* tempcard=nullptr;
	switch (pt) {
	case SUNFLOWER:
		//tempcard=
		break;
	case PEASHOOTER:
		//tempcard=
		break;
	case WALLNUT:
		//tempcard=
		break;
	case SQUASH:
		//tempcard=
		break;
	case CHERRYBOMB:
		//tempcard=
		break;
	default:
		break;
	}
	if (tempcard->cold == 0) {//������ȴʱ��
		//if ��������>=temp->cost
		{
		//��������-=tempcard->cost;
			//���ÿ�ƬΪ��ȴ״̬��������ȴ����
			// set_cold(true);
			//cold_animation();
			Plant* tempplant=NULL;
			switch (pt) {
			case SUNFLOWER:
				tempplant = new Sunflower;
				tempplant->set_type(SUNFLOWER);
				this->addChild(tempplant->run_animation(plantpos));
				break;
			case PEASHOOTER:
				tempplant = new Peashooter;
				tempplant->set_type(PEASHOOTER);
				this->addChild(tempplant->run_animation(plantpos));
				break;
			case WALLNUT:
				tempplant = new Wallnut;
				tempplant->set_type(WALLNUT);
				this->addChild(tempplant->run_animation(plantpos));
				break;
			case SQUASH:
				tempplant = new Squash;
				tempplant->set_type(SQUASH);
				this->addChild(tempplant->run_animation(plantpos));
				break;
			case CHERRYBOMB:
				tempplant = new Cherrybomb;
				tempplant->set_type(CHERRYBOMB);
				this->addChild(tempplant->run_animation(plantpos));
				break;
			default:
				break;
			}
		}
	}
}