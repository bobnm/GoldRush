#include "CustomerFirst.h"
#include "Say.h"
#include "ClearMessage.h"
#include "Player.h"
#include "Buy.h"
#include "PayDollar.h"
#include "WalkIn.h"
#include "WalkOut.h"
#include "Item.h"
#include "Margin.h"

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
    
	mReadyToLeave = false;
    sprite->setOpacity(0);
    auto sequence = Sequence::create(
									 WalkIn::create(.5,Vec2(10,0),10,3),
                                     DelayTime::create(1),
                                     Say::create("よォ"),
                                     DelayTime::create(1),
                                     Say::create("ここは道具屋か？"),
                                     DelayTime::create(3),
									 Margin::create(),
                                     Say::create("俺も金を堀りに来た口さ"),
                                     DelayTime::create(2),
									 Margin::create(),
                                     Say::create("いま着いたばかりで"),
                                     DelayTime::create(.5),
                                     Say::create("まだ何もわかんねえんだ"),
                                     DelayTime::create(3),
									 Margin::create(),
                                     Say::create("どんな道具がいるんだい"),
                                     DelayTime::create(6),
									 Margin::create(),
                                     Say::create("何か見つくろってくれよ"),
                                     DelayTime::create(6),
									 Margin::create(),
                                     Say::create("まずはなんでもいいんだ"),
                                     DelayTime::create(1),
                                     Say::create("机の上に出してみてくれよ"),
                                     DelayTime::create(7),
									 Margin::create(),
                                     Say::create("なんか道具ねェのか？"),
                                     DelayTime::create(10),
									 Margin::create(),
                                     Say::create("急いでんだ。もういい"),
                                     DelayTime::create(1),
									 CallFunc::create([this](){ this->mReadyToLeave = true; }),
                                     ClearMessage::create(),
									 WalkOut::create(.5,Vec2(10,0),10,3),
                                     NULL);
    sprite->runAction(sequence);
	this->setAction(sequence);

	setSingleton(this);
	return true;
}

void CustomerFirst::onPresented(Item* item)
{
	log("onPresented");
	if( mReadyToLeave ) return;
    if( std::string(item->getItemID()) == "GoldPan" )
	{
		auto sprite = this->getChildren().at(0);
		sprite->stopAllActions();
		auto sequence = Sequence::create(
				DelayTime::create(2),
				Say::create("……"),
				DelayTime::create(1),
				Say::create("なんだこの皿は？"),
				DelayTime::create(2),
				Margin::create(),
				Say::create("すくう？"),
				DelayTime::create(3),
				Say::create("川で使うのか"),
				DelayTime::create(2),
				Margin::create(),
				Say::create("オーケー"),
				DelayTime::create(1),
				Say::create("使ってみるよ"),
				PayDollar::create(25),
				DelayTime::create(3),
				Margin::create(),
				Say::create("ありがとう"),
				DelayTime::create(1),
				ClearMessage::create(),
				Buy::create(item),
				WalkOut::create(.5,Vec2(10,0),10,3),
				NULL);
		sprite->runAction(sequence);
		this->setAction(sequence);
		item->lock();
		mReadyToLeave = true;
	}
}

