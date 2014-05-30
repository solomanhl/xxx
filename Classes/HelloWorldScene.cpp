#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = LabelTTF::create("Hello World", "Arial", 24);

	// position the label on the center of the screen
	label->setPosition(Point(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("HelloWorld.png");

	// position the sprite on the center of the screen
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

	//加入自定义精灵
	auto spriteWanxianghao = Sprite::create("wangxianghao.jpg");
	spriteWanxianghao->setTag(0);
	spriteWanxianghao->setAnchorPoint(ccp(0, 0));
	spriteWanxianghao->setContentSize(CCSize(150, 210)); //定义精灵大小为150，210
	spriteWanxianghao->setScaleX(150 / spriteWanxianghao->getTextureRect().size.width);
	spriteWanxianghao->setScaleY(210 / spriteWanxianghao->getTextureRect().size.height);
	spriteWanxianghao->setPosition(Point(origin.x, visibleSize.height + origin.y - spriteWanxianghao->getContentSize().height));
	this->addChild(spriteWanxianghao, 0);

	auto spriteChenhao = Sprite::create("chenhao.jpg");
	spriteChenhao->setTag(1);
	spriteChenhao->setAnchorPoint(ccp(0, 0));
	spriteChenhao->setContentSize(CCSize(150, 210)); //定义精灵大小为150，210
	spriteChenhao->setScaleX(150 / spriteChenhao->getTextureRect().size.width);
	spriteChenhao->setScaleY(210 / spriteChenhao->getTextureRect().size.height);
	spriteChenhao->setPosition(Point(visibleSize.width + origin.x - spriteChenhao->getContentSize().width, origin.y + visibleSize.height - spriteChenhao->getContentSize().height));
	this->addChild(spriteChenhao, 0);



	//创建两个button
	Buttons *leftButton, *rightButton;

	leftButton = Buttons::createWithImgRect("button.jpg", Rect(512, 0, 256, 256), L_FireButton);
	this->addChild(leftButton);
	leftButton->setPosition(Point(origin.x + leftButton->getContentSize().width * leftButton->getScale() / 2, origin.y + visibleSize.height / 2));

	rightButton = Buttons::createWithImgRect("button.jpg", Rect(512, 256 + 32, 256, 256), R_FireButton);
	this->addChild(rightButton);
	rightButton->setPosition(Point(origin.x + visibleSize.width - rightButton->getContentSize().width * leftButton->getScale() / 2, origin.y + visibleSize.height / 2));

	log("left,right(%f,%f)", leftButton->getContentSize().width, rightButton->getContentSize().width);//输出是原始的256，而不是0.25倍之后的64

	

	//button触摸
	auto listener = EventListenerTouchOneByOne::create();
	
	listener->onTouchBegan = [this](Touch* t, Event* e){
		//log("onTouch");

		auto bs = Buttons::getButtons();
		Buttons *b;

		for (auto it = bs->begin(); it != bs->end(); it++){
			b = *it;
			if (b->getBoundingBox().containsPoint(t->getLocation())){
				if (b->getTag() == L_FireButton){
					log("L_FireButton Pressed");
					//创建子弹
					Bullets *bl_l;
					CCSize size = CCDirector::sharedDirector()->getWinSize();

					bl_l = Bullets::createWithImg("bullet.png", L_Bullet, 0);
					this->addChild(bl_l);

					Point p = Point(this->getChildByTag(0)->getContentSize().width + bl_l->getContentSize().width / 2.0 //左侧图片右边
						, size.height - this->getChildByTag(1)->getContentSize().height / 2);//高度是2个人物中间
					bl_l->setPosition(p);
					//移动子弹
					Point t = Point(size.width - this->getChildByTag(1)->getContentSize().width - bl_l->getContentSize().width / 2.0, size.height - this->getChildByTag(1)->getContentSize().height / 2);//到右侧图片左边
					bl_l->moveBullet(2, t);
				}
				else if (b->getTag() == R_FireButton){
					log("R_FireButton Pressed");
					//创建子弹
					Bullets *bl_r;
					CCSize size = CCDirector::sharedDirector()->getWinSize();

					bl_r = Bullets::createWithImg("bullet.png", L_Bullet, 180);
					this->addChild(bl_r);

					Point p = Point(size.width - this->getChildByTag(1)->getContentSize().width - bl_r->getContentSize().width / 2.0 //右侧图片左边
						, size.height - this->getChildByTag(1)->getContentSize().height / 2);//高度是2个人物中间
					bl_r->setPosition(p);
					//移动子弹
					Point t = Point(this->getChildByTag(0)->getContentSize().width + bl_r->getContentSize().width / 2.0, size.height - this->getChildByTag(1)->getContentSize().height / 2);//到左侧图片右边
					bl_r->moveBullet(2, t);
				}
				
			}
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	//子弹
	auto spriteBullet = Sprite::create("bullet.png");
	spriteBullet->setAnchorPoint(ccp(0.5, 0.5));
	spriteBullet->setPosition(Point(origin.x + spriteWanxianghao->getContentSize().width + spriteBullet->getContentSize().width / 2.0 //左侧图片右边
		, origin.y + visibleSize.height - spriteChenhao->getContentSize().height / 2));//高度是2个人物中间
	this->addChild(spriteBullet, 0);
	
	CCFiniteTimeAction *bulletMoveToRight = CCMoveTo::create(1, //1秒
		ccp(origin.x + visibleSize.width - spriteChenhao->getContentSize().width - spriteBullet->getContentSize().width / 2.0, origin.y + visibleSize.height - spriteChenhao->getContentSize().height / 2));//到右侧图片左边
	//增加一个回调函数，回收移动到屏幕外的精灵  
	CCFiniteTimeAction *actionMoveDone = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::spriteMoveFinished));
	spriteBullet->runAction(CCSequence::create(bulletMoveToRight, actionMoveDone, NULL));


	return true;
}



void HelloWorld::spriteMoveFinished(cocos2d::CCNode *sender){
	CCSprite *sprite = (CCSprite *)sender;
	this->removeChild(sprite, true);
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
