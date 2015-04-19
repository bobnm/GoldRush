#include "Player.h"
#include "ItemFactory.h"

using namespace cocos2d;

bool Player::init()
{
    if( !Layer::init() ) return false;
    
    static const int cMaxItem = 32;
    mInventoryID = new std::vector<std::string>();
    mInventory = new Vector<Item*>(cMaxItem);

    mInventoryID->push_back("GoldPan");
    mInventoryID->push_back("GoldPan");
    mInventoryID->push_back("GoldPan");
    mInventoryID->push_back("GoldPan");
    
    int i = 0;
    for(auto item_id : *mInventoryID)
    {
        log("%d = %s\n", i, item_id.c_str());
        Item* item = ItemFactory::create(item_id);
        CC_ASSERT(item != nullptr);
        item->setPosition(Vec2(70 + 32 * 3 * (i % 3), 550 - (32 + 10) * 3 * (i / 3)));
        mInventory->pushBack(item);
        this->addChild(item);
        i++;
    }
    return true;
}

