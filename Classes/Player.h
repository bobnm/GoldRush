#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <cocos2d.h>
#include "Item.h"

class Player : public cocos2d::Layer {
    
public:
    CREATE_FUNC(Player);
    
public:
    virtual bool init();
    
private:
    std::vector<std::string>* mInventoryID;
    cocos2d::Vector<Item*>* mInventory;
    
};
#endif

