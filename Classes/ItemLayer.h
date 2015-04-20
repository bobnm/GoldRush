#ifndef __ITEM_LAYER_H__
#define __ITEM_LAYER_H__

#include <cocos2d.h>
#include "Item.h"

class ItemLayer : public cocos2d::Layer {
public:
    CREATE_FUNC(ItemLayer);
    static ItemLayer* getInstance();
    virtual bool init();

	void createPlayerInventoryItem();

public:
	void addItem(Item* item);
	void removeItem(Item* item);
	void unlockAll();

private:
	cocos2d::Vector<Item*>* mList;
};
#endif

