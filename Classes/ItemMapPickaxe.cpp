#include "ItemMapPickaxe.h"

using namespace cocos2d;

bool MapPickaxe::init()
{
    if( !Item::init() ) return false;
    
    auto sprite = Sprite::create("map_pickaxe.png");
    sprite->getTexture()->setAliasTexParameters();
    sprite->setScale(3);
    this->addChild(sprite, 0);

	initTouch(sprite);
    
    return true;
}

