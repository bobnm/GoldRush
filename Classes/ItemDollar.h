#ifndef __ITEM_DOLLAR_H__
#define __ITEM_DOLLAR_H__

#include <cocos2d.h>
#include "Item.h"

class Dollar : public Item {
    
public:
	static Dollar* create(int amount);
    virtual bool init(int amount);
    
	virtual const char* getItemID() const { return mItemID.c_str(); }

private:
	int mAmount;
	std::string mItemID;
};

#endif

