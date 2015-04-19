#include "Buy.h"
#include "Player.h"

using namespace cocos2d;

Buy* Buy::create(Item* item)
{
    Buy* ret = new (std::nothrow) Buy();
    
    if (ret) {
        ret->autorelease();
		ret->init(item);
    }
    
    return ret;
}

void Buy::init(Item* item)
{
	mItem = item;
}

void Buy::update(float time) {
    CC_UNUSED_PARAM(time);
	Player::getInstance()->sell(mItem);
}

ActionInstant* Buy::reverse() const
{
    return nullptr;
}

Buy * Buy::clone() const
{
    // no copy constructor
    auto a = new (std::nothrow) Buy();
    a->autorelease();
	a->init(mItem);
    return a;
}

