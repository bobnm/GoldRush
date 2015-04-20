#include "ItemLayer.h"
#include "Player.h"
#include "ItemFactory.h"

using namespace cocos2d;

namespace {
    ItemLayer* sInstance = nullptr;
}

ItemLayer* ItemLayer::getInstance()
{
    return sInstance;
}

bool ItemLayer::init()
{
    if( !Layer::init() ) return false;
    
	static const int cMaxItem = 128;
	mList = new Vector<Item*>(cMaxItem);

    CC_ASSERT(sInstance == nullptr);
    sInstance = this;
    sInstance->retain();
	return true;
}

void ItemLayer::createPlayerInventoryItem()
{
    int i = 0;
    for(auto item_id : *Player::getInstance()->getInventory())
    {
        log("%d = %s\n", i, item_id.c_str());
        auto item = ItemFactory::create(item_id);
        CC_ASSERT(item != nullptr);
        item->setPosition(Vec2(70 + 32 * 3 * (i % 3), 550 - (32 + 10) * 3 * (i / 3)));
        i++;
    }
}

void ItemLayer::unlockAll()
{
	for(auto item : *mList)
	{
		item->unlock();
	}
}

void ItemLayer::addItem(Item* item)
{
	mList->pushBack(item);
	this->addChild(item);
}

void ItemLayer::removeItem(Item* item)
{
	this->removeChild(item);
	mList->eraseObject(item);
}

