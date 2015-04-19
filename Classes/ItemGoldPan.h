#ifndef __ITEM_GOLD_PAN_H__
#define __ITEM_GOLD_PAN_H__

#include <cocos2d.h>
#include "Item.h"

class GoldPan : public Item {
    
public:
    // implement the "static create()" method manually
    CREATE_FUNC(GoldPan);
    virtual bool init();
    
	virtual const char* getItemName() const { return "GoldPan"; }
};

#endif

