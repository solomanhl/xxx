#pragma once

#include <cocos2d.h>
USING_NS_CC;

#define L_Bullet 20
#define R_Bullet 21

class Bullets :public Sprite
{
private:
	static Vector<Bullets*> *bullets;


public:
	Bullets();
	~Bullets();

	static Vector<Bullets *> *getBullets();

	static Bullets* createWithImg(std::string img, int tag, float rotation);

	virtual bool initWithImg(std::string img, int tag, float rotation);

	void moveBullet(int time, Point target);//�ƶ��ӵ�
	void spriteMoveFinished(cocos2d::CCNode *sender);//�Ƴ��ӵ��ص�����

	void removeBullet();//�Ƴ��ӵ�

protected:
	//CCSprite *m_pSprite;	///<����
	Bullets *bullet;	///<����
};

