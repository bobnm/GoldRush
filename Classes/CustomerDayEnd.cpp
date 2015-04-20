#include "CustomerDayEnd.h"
#include "Say.h"
#include "ClearMessage.h"
#include "Player.h"
#include "Buy.h"
#include "PayDollar.h"
#include "WalkIn.h"
#include "WalkOut.h"
#include "Item.h"
#include "Margin.h"
#include "PutItem.h"

using namespace cocos2d;

bool CustomerDayEnd::init()
{
	if( !Customer::init() ) return false;

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Vec2 center(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y);
	this->setPosition(center + Vec2(150,0));

	auto sprite = Sprite::create("customer.png");
	sprite->getTexture()->setAliasTexParameters();
	sprite->setScale(3);
    this->addChild(sprite, 0);
    
    sprite->setOpacity(0);
    auto sequence = Sequence::create(
									 WalkIn::create(.5,Vec2(10,0),10,3),
                                     DelayTime::create(1),
                                     Say::create("[今日はここまで]"),
                                     DelayTime::create(2),
									 Margin::create(),
									 Player::getInstance()->hasItem("MapPickaxe") ?
									 	(Action*)Sequence::create(
											Say::create("[つるはしを3本購入]"),
											PutItem::create("Pickaxe"),
											PutItem::create("Pickaxe"),
											PutItem::create("Pickaxe"),
											DelayTime::create(0.5),
											NULL) :
										(Action*)DelayTime::create(0.0),
                                     Say::create("[追加のゴールドパン]"),
									 PutItem::create("GoldPan"),
									 PutItem::create("GoldPan"),
									 PutItem::create("GoldPan"),
									 DelayTime::create(0.5),
                                     Say::create("[おまけ]"),
									 PutItem::create("Shovel"),
									 DelayTime::create(4),
                                     ClearMessage::create(),
									 WalkOut::create(.5,Vec2(10,0),10,3),
                                     NULL);
    sprite->runAction(sequence);
	this->setAction(sequence);

	setSingleton(this);
	return true;
}

void CustomerDayEnd::onPresented(Item* item)
{
}

