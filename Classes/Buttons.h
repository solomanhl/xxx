#pragma once

#include <cocos2d.h>
USING_NS_CC;

#define L_FireButton 10
#define R_FireButton 11

class Buttons :public Sprite
{
private:
	static Vector<Buttons*> *buttons;
	

public:
	Buttons();
	~Buttons();

	static Vector<Buttons *> *getButtons();

	static Buttons* createWithImgRect(std::string img, Rect rect, int tag);

	virtual bool initWithImgRect(std::string img, Rect rect, int tag);

	void removeButton();
};

