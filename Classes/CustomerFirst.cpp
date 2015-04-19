#include "CustomerFirst.h"
#include "Say.h"
#include "ClearMessage.h"
#include "MessageBalloon.h"
#include "Buy.h"
#include "PayDollar.h"
#include "WalkIn.h"
#include "WalkOut.h"
#include "Item.h"

using namespace cocos2d;

bool CustomerFirst::init()
{
	if( !Customer::init() ) return false;

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Vec2 center(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y);
	this->setPosition(center + Vec2(150,0));

	auto sprite = Sprite::create("customer04.png");
	sprite->getTexture()->setAliasTexParameters();
	sprite->setScale(3);
    this->addChild(sprite, 0);
    
    sprite->setOpacity(0);
    auto sequence = Sequence::create(
									 WalkIn::create(.5,Vec2(10,0),10,3),
                                     DelayTime::create(1),
                                     Say::create("よォ。"),
                                     DelayTime::create(1),
                                     Say::create("ここは道具屋か？"),
                                     DelayTime::create(4),
                                     Say::create("俺も金を堀りに来た口さ。"),
                                     DelayTime::create(4),
                                     Say::create("でもいま着いたばかりで"),
                                     DelayTime::create(2),
                                     Say::create("まだ何もわかんねえんだ。"),
                                     DelayTime::create(4),
                                     Say::create("金は、どこで採れる？"),
                                     DelayTime::create(4),
                                     Say::create("どんな道具がいるんだい。"),
                                     DelayTime::create(8),
                                     Say::create("何か見つくろってくれよ。"),
                                     DelayTime::create(4),
                                     Say::create("まずはなんでもいいんだ。"),
                                     DelayTime::create(8),
                                     Say::create("なにか道具ねェのかい？"),
                                     DelayTime::create(10),
                                     Say::create("急いでんだ。もういい。"),
                                     DelayTime::create(1),
									 CallFunc::create([this](){ this->mDone = true; }),
                                     ClearMessage::create(),
									 WalkOut::create(.5,Vec2(10,0),10,3),
                                     NULL);
    sprite->runAction(sequence);
	mDone = false;

	setSingleton(this);
	return true;
}

void CustomerFirst::onPresented(Item* item)
{
	log("onPresented");
	if( mDone ) return;
    if( std::string(item->getItemName()) == "GoldPan" )
	{
		auto sprite = this->getChildren().at(0);
		sprite->stopAllActions();
		MessageBalloon::getInstance()->birth("ゴールドパン", MessageBalloon::RIGHT);
		auto sequence = Sequence::create(
				Say::create("これはなんだ？"),
				DelayTime::create(2),
				Say::create("すくう？"),
				DelayTime::create(3),
				Say::create("川で使うのか。"),
				DelayTime::create(2),
				Say::create("オーケー"),
				DelayTime::create(1),
				Say::create("使ってみるよ。"),
				PayDollar::create(25),
				DelayTime::create(3),
				Say::create("ありがとう。"),
				DelayTime::create(1),
				ClearMessage::create(),
				Buy::create(item),
				WalkOut::create(.5,Vec2(10,0),10,3),
				NULL);
		sprite->runAction(sequence);
		item->lock();
		mDone = true;
	}
}

