#include "PutItem.h"
#include "Player.h"
#include "ItemFactory.h"

using namespace cocos2d;

PutItem* PutItem::create(const std::string& id)
{
    PutItem* ret = new (std::nothrow) PutItem();
    
    if (ret) {
        ret->autorelease();
		ret->init(id);
    }
    
    return ret;
}

void PutItem::init(const std::string& id)
{
	mID = id;
}

void PutItem::update(float time) {
    CC_UNUSED_PARAM(time);
	Item* item = ItemFactory::create(mID);
	Player::getInstance()->take(item);
}

ActionInstant* PutItem::reverse() const
{
    return nullptr;
}

PutItem * PutItem::clone() const
{
    // no copy constructor
    auto a = new (std::nothrow) PutItem();
    a->autorelease();
	a->init(mID);
    return a;
}

