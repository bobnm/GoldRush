#ifndef __DESK_H__
#define __DESK_H__

#include <cocos2d.h>
#include "Item.h"

class Desk : public cocos2d::Layer {
    
public:
    // implement the "static create()" method manually
    CREATE_FUNC(Desk);
    
    static Desk* getInstance();
    
public:
    virtual bool init();

	bool onDrop(const Item& item);

};

#endif

