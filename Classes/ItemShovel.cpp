#include "ItemShovel.h"

using namespace cocos2d;

bool Shovel::init()
{
    if( !Item::init() ) return false;
    
    auto sprite = Sprite::create("shovel.png");
    sprite->getTexture()->setAliasTexParameters();
    sprite->setScale(3);
    this->addChild(sprite, 0);

	initTouch(sprite);
    
    return true;
}

