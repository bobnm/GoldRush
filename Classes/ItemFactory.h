#ifndef __ITEM_FACTORY_H__
#define __ITEM_FACTORY_H__

#include <cocos2d.h>
#include "Item.h"

class ItemFactory {
public:
    static Item* create(const std::string& id);
};

#endif

