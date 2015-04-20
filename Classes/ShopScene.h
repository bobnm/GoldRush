#ifndef __SHOP_SCENE_H__
#define __SHOP_SCENE_H__

#include "cocos2d.h"

class Shop : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Shop);

	virtual void update(float t);
    
private:
    bool onTouchBegan_(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchMoved_(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchEnded_(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchCancelled_(cocos2d::Touch* touch, cocos2d::Event* event);

private:
	int mCount;
};

#endif // __SHOP_SCENE_H__

