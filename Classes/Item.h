#ifndef __ITEM_H__
#define __ITEM_H__

#include <cocos2d.h>

class Item : public cocos2d::Layer {
    
public:
    // implement the "static create()" method manually
    CREATE_FUNC(Item);
    
public:
    virtual bool init();
    
protected:
	void initTouch(cocos2d::Node* node);

private:
    bool onTouchBegan_(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchMoved_(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchEnded_(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchCancelled_(cocos2d::Touch* touch, cocos2d::Event* event);

private:
	cocos2d::Node* mTouchNode;
	float mOriginalScale;
	cocos2d::Vec2 mTouchOffset;
};

#endif

