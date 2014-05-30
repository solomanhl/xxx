#include "Bullets.h"


Bullets::Bullets()
{
}


Bullets::~Bullets()
{
}

Vector<Bullets*> *Bullets::bullets = new Vector<Bullets*>();
Vector<Bullets*> *Bullets::getBullets(){
	return Bullets::bullets;
}

Bullets* Bullets::createWithImg(std::string img, int tag, float rotation){

	auto b = new Bullets();
	b->initWithImg(img, tag, rotation);
	b->autorelease();
	bullets->pushBack(b);
	return b;
}

bool Bullets::initWithImg(std::string img, int tag, float rotation){
	//Sprite::init();
	bool s = Sprite::initWithFile(img);
	//setScale(1);
	setTag(tag);
	setRotation(rotation);

	return true;
}

void Bullets::removeBullet(){

	removeFromParent();
	bullets->eraseObject(this);

}

void Bullets::moveBullet(int time, Point target){
	CCFiniteTimeAction *bulletMoveToRight = CCMoveTo::create(time, target);
	//增加一个回调函数，回收移动到屏幕外的精灵  
	CCFiniteTimeAction *actionMoveDone = CCCallFuncN::create(this, callfuncN_selector(Bullets::spriteMoveFinished));
	runAction(CCSequence::create(bulletMoveToRight, actionMoveDone, NULL));
}

void Bullets::spriteMoveFinished(cocos2d::CCNode *sender){
	//CCSprite *sprite = (CCSprite *)sender;
	//this->removeChild(sprite, true);
	bullet = (Bullets *)sender;
	bullet->removeBullet();
}