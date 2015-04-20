#ifndef __ITEM_SHOVEL_H__
#define __ITEM_SHOVEL_H__

#include <cocos2d.h>
#include "Item.h"

class Shovel : public Item {
    
public:
    // implement the "static create()" method manually
    CREATE_FUNC(Shovel);
    virtual bool init();
    
	virtual const char* getItemID() const { return "Shovel"; }
};

#endif

