#include "CustomerRandom.h"
#include "Say.h"
#include "ClearMessage.h"
#include "MessageBalloon.h"
#include "Buy.h"
#include "PayDollar.h"
#include "WalkIn.h"
#include "WalkOut.h"
#include "Item.h"
#include "Margin.h"
#include "ItemDB.h"
#include "Util.h"
#include "Player.h"

using namespace cocos2d;

bool CustomerRandom::init()
{
	if( !Customer::init() ) return false;

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Vec2 center(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y);
	this->setPosition(center + Vec2(150,0));

	auto sprite = Sprite::create(StringUtils::format("customer%02d.png", Util::GetRand(1,3)));
	sprite->getTexture()->setAliasTexParameters();
	sprite->setScale(3);
    this->addChild(sprite, 0);
    
	mNeedItemID = ItemDB::getRandomItemID();
	const std::string& ja = ItemDB::getNameJa(mNeedItemID);
	mMessageKure = StringUtils::format("%sをくれ", ja.c_str());
	mMessageDa = StringUtils::format("%sだ", ja.c_str());
    sprite->setOpacity(0);
    auto sequence = Sequence::create(
									 WalkIn::create(.5,Vec2(10,0),10,3),
                                     DelayTime::create(1),
                                     Say::create(mMessageKure.c_str()),
                                     DelayTime::create(5),
									 Margin::create(),
                                     Say::create("さっさとしろ"),
                                     DelayTime::create(2),
                                     Say::create(mMessageDa.c_str()),
                                     DelayTime::create(5),
									 Margin::create(),
                                     Say::create("いつまで待たせんだ"),
                                     DelayTime::create(1),
                                     Say::create(mMessageDa.c_str()),
                                     DelayTime::create(5),
									 Margin::create(),
                                     Say::create("チッ"),
                                     DelayTime::create(.5),
									 CallFunc::create([this](){ this->mDone = true; }),
                                     ClearMessage::create(),
									 WalkOut::create(.5,Vec2(10,0),10,3),
                                     NULL);
    sprite->runAction(sequence);
	setAction(sequence);
	mDone = false;

	setSingleton(this);
	return true;
}

void CustomerRandom::onPresented(Item* item)
{
	if( mDone ) return;
    if( std::string(item->getItemID()) == mNeedItemID )
	{
		auto sprite = this->getChildren().at(0);
		sprite->stopAllActions();
		auto sequence = Sequence::create(
				DelayTime::create(1),
				Say::create("……"),
				DelayTime::create(1),
				Margin::create(),
				Say::create("ああこれだ"),
				DelayTime::create(2),
				PayDollar::create(item->getPrice()),
				DelayTime::create(1),
				Margin::create(),
				Say::create("またな"),
				DelayTime::create(1),
				ClearMessage::create(),
				Buy::create(item),
				WalkOut::create(.5,Vec2(10,0),10,3),
				NULL);
		sprite->runAction(sequence);
		setAction(sequence);
		item->lock();
		mDone = true;
	}
}

