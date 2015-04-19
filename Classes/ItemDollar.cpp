#include "ItemDollar.h"

using namespace cocos2d;

Dollar* Dollar::create(int amount)
{
    Dollar* ret = new (std::nothrow) Dollar();
    
    if (ret) {
        ret->autorelease();
		ret->init(amount);
    }
    
    return ret;
}

bool Dollar::init(int amount)
{
    if( !Item::init() ) return false;
    
	mAmount = amount;
	mItemID = StringUtils::format("Dollar%d", amount);
    auto sprite = Sprite::create(StringUtils::format("dollar%d.png", amount));
    sprite->getTexture()->setAliasTexParameters();
    this->addChild(sprite, 0);

	initTouch(sprite);
    
    return true;
}

