#ifndef __ITEM_H__
#define __ITEM_H__

#include <cocos2d.h>
#include "ItemDB.h"

class Item : public cocos2d::Layer {
    
public:
    // implement the "static create()" method manually
    CREATE_FUNC(Item);
    
public:
    virtual bool init();
	const cocos2d::Vec2& getDragStartPos() const { return mDragStartPos; }
    virtual const char* getItemID() const { return "Item"; }
	int getPrice() const { return ItemDB::getPrice(this->getItemID()); }
    const char* getNameJa() const { return ItemDB::getNameJa(this->getItemID()); }

	void lock() { mLock = true; }
	void unlock() { mLock = false; }
	void sell();
	void take();
    
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

