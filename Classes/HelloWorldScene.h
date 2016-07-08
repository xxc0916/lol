#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include"ui/CocosGUI.h"

#include "cocos2d.h"
USING_NS_CC;
class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
	Sprite* start;
	Sprite* pause;
	Sprite* stop;
	Sprite*dian;
	Sprite*zou;
	Sprite*you;
	Sprite*hen;
	void updateCustom(float dt);
	void updateCustom1(float dt);
	bool move;
	void _start();
	void _start1();
	void _stop();
	int i;
	int speed;
	//ui::Button* button;
};

#endif // __HELLOWORLD_SCENE_H__
