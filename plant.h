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
USING_NS_CC;

enum PlantType {
    NONE = -1,//û��ֲ��
    SUNFLOWER,//̫����0
    PEASHOOTER,//�㶹����1
    WALLNUT,//���ǽ2
    CHERRYBOMB//ӣ��ը��3
};

class Plant :public Sprite {
public:
    Plant() = default;
    ~Plant() = default;
    virtual void init_plant() {};//��ʼ��ֲ����Ϣ
    virtual Sprite* init_sprite(Vec2);//�����ʼ��
    virtual void set_blood(int);//����Ѫ��
    virtual void set_interval(float);//����ʱ����
    virtual float get_interval();//��ȡʱ����
    virtual void is_plant(bool);//�����Ƿ���ֲ
    virtual void is_shoot(bool);//�Ƿ����ӵ�
    virtual void attacked(int);//��������۳�Ѫ��
    virtual int get_blood();//��ȡ��ǰѪ��
    virtual void set_type(PlantType);//����ֲ������
    virtual PlantType get_type();//��ȡֲ������
    virtual void init_animation();//��ʼ��ֲ�ﶯ��
    virtual void set_firstframe(SpriteFrame*);//���õ�һ֡����
    virtual void load_animation(std::string, int, cocos2d::Vector<cocos2d::SpriteFrame*>&);//���ض���
    virtual void set_animation(Animate*);//��ȡֲ�ﶯ��
    virtual Sprite* run_animation(Vec2);//ֲ�����º�Ķ���
    virtual Animate* get_animation() { return panimate; };
    virtual void set_size(double);//���ô�С
    virtual void set_rate(double);
    virtual double get_rate();
    virtual int get_row() { return row; };
    virtual int get_col() { return col; };
    virtual float get_x() { return pos.x; };
    virtual float get_y() { return pos.y; };
    virtual Vec2 get_pos() { return pos; };
    virtual Rect get_rect();
    virtual Sprite* get_sprite() { return this->sprite; };
    double time_count;
    double rate_time;
    int row;
    int col;
private:
    int blood;//Ѫ��
    bool planted;//�Ƿ���ֲ
    bool shooted;//�Ƿ����ӵ�
    Sprite* sprite;//����
    PlantType pt;//ֲ������
    SpriteFrame* firstframe;//��һ֡����
    Animate* panimate;//ֲ�ﶯ��
    Vec2 pos;//λ��
    Rect rect;
    float interval;//ʱ����
 
   
   
};