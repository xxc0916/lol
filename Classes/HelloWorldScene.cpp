#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include"ui/CocosGUI.h"
#include <iostream>
#include<math.h>
USING_NS_CC;
//using namespace std;


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
    if ( !Layer::init() )
    {
        return false;
    }
	speed = 1;
	
	move = false;
    visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    ///////////////////////////////
    //// 2. add a menu item with "X" image, which is clicked to quit the program
    ////    you may modify it.

    //// add a "close" icon to exit the progress. it's an autorelease object
    //auto closeItem = MenuItemImage::create(
    //                                       "CloseNormal.png",
    //                                       "CloseSelected.png",
    //                                       CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    //
    //closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
    //                            origin.y + closeItem->getContentSize().height/2));

    //// create menu, it's an autorelease object
    //auto menu = Menu::create(closeItem, NULL);
    //menu->setPosition(Vec2::ZERO);
    //this->addChild(menu, 1);

    ///////////////////////////////
    //// 3. add your codes below...

    //// add a label shows "Hello World"
    //// create and initialize a label
    //
    //auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    //
    //// position the label on the center of the screen
    //label->setPosition(Vec2(origin.x + visibleSize.width/2,
    //                        origin.y + visibleSize.height - label->getContentSize().height));

    //// add the label as a child to this layer
    //this->addChild(label, 1);

    //// add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");

    //// position the sprite on the center of the screen
    //sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    //// add the sprite as a child to this layer
    //this->addChild(sprite, 0);
	/*button = ui::Button::create("start.png", "pause.png", "stop.png");
	button->setTitleText("Button Text");
	button->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	button->addTouchEventListener([&](Ref*sender, ui::Widget::TouchEventType type){
		switch (type)
		{
		case ui::Widget ::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			std::cout << "Button 1 cliked" << std::endl;
			break;
		default:
			break;
		}
	});
	this->addChild(button);*/
	//start = Sprite::create("start.png");
	//start->setPosition(100, 100);
	//this->addChild(start);
	//dian = Sprite::create("dian1.png");
	//dian->setPosition(300, 200);
	//this->addChild(dian);
	//move = false;
	//auto listener = EventListenerTouchOneByOne::create();
	//listener->setSwallowTouches(true);
	//listener->onTouchBegan = [=](Touch*touch, Event*event){
	//	auto p1 = touch->getLocation();
	//	auto p2 = start->getPosition();
	//	auto length =  ccpDistance(p1, p2);
	//	if (length < 60)
	//	{
	//		log("onTouch");
	//		//dian ->runAction(RepeatForever::create(Sequence::create(MoveTo::create(1.0f, Point(300, 0)), MoveTo::create(1.0f, Point(300, visibleSize.height)), NULL)));
	//		//schedule(schedule_selector(HelloWorld::updateCustom), 2.0f, kRepeatForever, 0);
	//		_start();
	//	}
	//	
	//	//auto target = static_cast<Sprite*>(event->getCurrentTarget());
	//
	//	return true;
	//};
	//listener->onTouchEnded = [=](Touch*touch, Event*event)
	//{
	//	log("end");
	//	_stop();
	//	//this->unschedule(schedule_selector(HelloWorld::updateCustom));
	//};
	////schedule(schedule_selector(HelloWorld::updateCustom), 1.0f, kRepeatForever, 0);
	//Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	zou = Sprite::create("zou.png");
	zou->setPosition(300, 50);
	this->addChild(zou,1);
	you = Sprite::create("you.png");
	you->setPosition(200, 50);
	this->addChild(you,1);
	hen = Sprite::create("hen.png");
	hen->setPosition(100, 100);
	hen->setScale(0.1f,0.2f);
	this->addChild(hen,1);
	b = hen->getContentSize();
	b.width = b.width * 0.1f;
	b.height = b.height * 0.2f;
	auto di = Sprite::create("di_2.jpg");
	di->setPosition(visibleSize.width /2, 45);
	this->addChild(di, 0);
	a = di->getContentSize();
	di->setScaleX(visibleSize.width/a.width);
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = [=](Touch*touch, Event*event)
	{
		auto p1 = touch->getLocation();
		auto p2 = zou->getPosition();
		auto p3 = you->getPosition();
		auto rect1 = Rect(p2.x - 35, p2.y - 10, 70, 20);
		auto rect2 = Rect(p3.x - 35, p3.y - 10, 70, 20);
		if (rect1.containsPoint(p1))
		{
			log("you");
			_start();
			
		}
		if (rect2.containsPoint(p1))
		{
			log("zou");
		
			_start1();
			
		}
		return true;
	};
	listener->onTouchEnded = [=](Touch*touch, Event*event)
	{
		auto p1 = touch->getLocation();
		auto p2 = zou->getPosition();
		auto p3 = you->getPosition();
		auto rect1 = Rect(p2.x - 35, p2.y - 10, 70, 20);
		auto rect2 = Rect(p3.x - 35, p3.y - 10, 70, 20);
		if (rect1.containsPoint(p1))
		{
			log("youend");
			hen->runAction(EaseIn::create(MoveBy::create(0.7f, Point(50, 0)),1));
		}
		if (rect2.containsPoint(p1))
		{
			log("zouend");
			hen->runAction(EaseIn::create(MoveBy::create(0.7f, Point(-50, 0)),1));
			
		}
		
		 _stop();
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	
    return true;
}



void HelloWorld::updateCustom(float dt)
{
	
	auto p_cur = hen->getPosition();
	auto p_add = Vec2(0,speed);	
	speed = 1;
	if (p_cur.x >=visibleSize.width - b.width)
	{
		//speed = 0;
		hen->setPosition(0, p_cur.y);
		//move = false;
	}
	else
	{
		//speed = 1;
		hen->setPosition(p_cur.x + speed, p_cur.y);
		//speed = speed + 1;
		//move = true;
	}
	//speed = speed + 1;
}
void HelloWorld::updateCustom1(float dt)
{
	auto p_cur = hen->getPosition();
	auto p_add = Vec2(0, speed);
	speed = 1;
	if (p_cur.x <= b.width)
	{
		//speed = 0;
		hen->setPosition(visibleSize.width , p_cur.y);
		//move = false;
	}
	else
	{
		//speed = 1;
		hen->setPosition(p_cur.x - speed, p_cur.y);
		//speed = speed + 1;
		//move = true;
	}
	//speed = speed + 1;
}
void  HelloWorld::_start()
{
	if (!move)
	{
		schedule(schedule_selector(HelloWorld::updateCustom),0.01f,  kRepeatForever, 0);
		
		move = true;
	}
	
}
void HelloWorld::_start1()
{
	if (!move)
	{
		schedule(schedule_selector(HelloWorld::updateCustom1), 0.01f, kRepeatForever, 0);

		move = true;
	}
}
void  HelloWorld::_stop()
{
	if (move)
	{
		//this->unschedule(schedule_selector(HelloWorld::updateCustom));
		this->unscheduleAllSelectors();
		move = false;
	}
	
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
