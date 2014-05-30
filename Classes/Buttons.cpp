#include "Buttons.h"


Buttons::Buttons()
{
}

Buttons::~Buttons()
{
}

Vector<Buttons*> *Buttons::buttons = new Vector<Buttons*>();
Vector<Buttons*> *Buttons::getButtons(){
	return Buttons::buttons;
}


Buttons* Buttons::createWithImgRect(std::string img, Rect rect, int tag){

	auto b = new Buttons();
	b->initWithImgRect(img, rect, tag);
	b->autorelease();
	buttons->pushBack(b);
	return b;
}

bool Buttons::initWithImgRect(std::string img, Rect rect, int tag){
	//Sprite::init();
	Sprite::initWithFile(img, rect);

	//setContentSize(Size(64,64));
	//setTextureRect(Rect(0, 0, 64, 64));
	setScale(0.5);
	setTag(tag);
	
	return true;
}

void Buttons::removeButton(){

	removeFromParent();
	buttons->eraseObject(this);

}