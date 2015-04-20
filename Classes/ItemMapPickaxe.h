#ifndef __ITEM_MAP_PICKAXE_H__
#define __ITEM_MAP_PICKAXE_H__

#include <cocos2d.h>
#include "Item.h"

class MapPickaxe : public Item {
    
public:
    // implement the "static create()" method manually
    CREATE_FUNC(MapPickaxe);
    virtual bool init();
    
	virtual const char* getItemID() const { return "MapPickaxe"; }
};

#endif

