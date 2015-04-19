#include "ItemGoldPan.h"

using namespace cocos2d;

bool GoldPan::init()
{
    if( !Item::init() ) return false;
    
    auto sprite = Sprite::create("goldpan.png");
    sprite->getTexture()->setAliasTexParameters();
    sprite->setScale(3);
    this->addChild(sprite, 0);

	initTouch(sprite);
    
    return true;
}

