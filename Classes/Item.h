#ifndef __ITEM_H__
#define __ITEM_H__

#include <cocos2d.h>

class Item : public cocos2d::Layer {
    
public:
    // implement the "static create()" method manually
    CREATE_FUNC(Item);
    
public:
    virtual bool init();
    
};

#endif
