#include "Customer.h"

using namespace cocos2d;

bool Customer::init()
{
	if( !Layer::init() ) return false;
	auto sprite = Sprite::create("customer.png");
	sprite->getTexture()->setAliasTexParameters();
	sprite->setScale(3);
	this->addChild(sprite, 0);
	return true;
}

