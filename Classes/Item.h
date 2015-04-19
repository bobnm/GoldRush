#ifndef __ITEM_H__
#define __ITEM_H__

#include <cocos2d.h>

class Item : public cocos2d::Layer {
    
public:
    // implement the "static create()" method manually
    CREATE_FUNC(Item);
    
public:
    virtual bool init();
	const cocos2d::Vec2& getDragStartPos() const { return mDragStartPos; }
    virtual const char* getItemName() const { return "Item"; }

	void lock() { mLock = true; }
	void sell();
    
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
	float mOriginalOpacity;
	cocos2d::Vec2 mTouchOffset;
	cocos2d::Vec2 mDragStartPos;
	bool mLock;
};

#endif

