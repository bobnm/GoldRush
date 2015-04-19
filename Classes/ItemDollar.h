#ifndef __ITEM_DOLLAR_H__
#define __ITEM_DOLLAR_H__

#include <cocos2d.h>
#include "Item.h"

class Dollar : public Item {
    
public:
	static Dollar* create(int amount);
    virtual bool init(int amount);
    
	virtual const char* getItemName() const { return mItemName.c_str(); }

private:
	int mAmount;
	std::string mItemName;
};

#endif

