#ifndef __ITEM_PICKAXE_H__
#define __ITEM_PICKAXE_H__

#include <cocos2d.h>
#include "Item.h"

class Pickaxe : public Item {
    
public:
    // implement the "static create()" method manually
    CREATE_FUNC(Pickaxe);
    virtual bool init();
    
	virtual const char* getItemID() const { return "Pickaxe"; }
};

#endif

