#include "ItemPickaxe.h"

using namespace cocos2d;

bool Pickaxe::init()
{
    if( !Item::init() ) return false;
    
    auto sprite = Sprite::create("pickaxe.png");
    sprite->getTexture()->setAliasTexParameters();
    sprite->setScale(3);
    this->addChild(sprite, 0);

	initTouch(sprite);
    
    return true;
}

