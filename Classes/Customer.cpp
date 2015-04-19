#include "Customer.h"
#include "Say.h"
#include "ClearMessage.h"
#include "MessageBalloon.h"

using namespace cocos2d;

namespace {
    Customer* sInstance = nullptr;
}

Customer* Customer::getInstance()
{
    CC_ASSERT(sInstance);
    return sInstance;
}

bool Customer::init()
{
	if( !Layer::init() ) return false;
	auto sprite = Sprite::create("customer.png");
	sprite->getTexture()->setAliasTexParameters();
	sprite->setScale(3);
    this->addChild(sprite, 0);
    
    sprite->setOpacity(0);
    auto sequence = Sequence::create(
                                     FadeIn::create(.5),
                                     DelayTime::create(1),
                                     Say::create("よう。"),
                                     DelayTime::create(1),
                                     Say::create("ここは道具屋か。"),
                                     DelayTime::create(4),
                                     Say::create("俺も金を堀りに来た口さ。"),
                                     DelayTime::create(4),
                                     Say::create("でもいま着いたばかりで"),
                                     DelayTime::create(6),
                                     Say::create("まだ何もわからない。"),
                                     DelayTime::create(8),
                                     Say::create("金は、どこで採れるんだ？"),
                                     DelayTime::create(4),
                                     Say::create("どんな道具がいる？"),
                                     DelayTime::create(8),
                                     Say::create("何か見つくろってくれよ。"),
                                     DelayTime::create(4),
                                     Say::create("まずはなんでもいいんだ。"),
                                     DelayTime::create(8),
                                     Say::create("なにか道具ねえのかい？"),
                                     DelayTime::create(10),
                                     Say::create("急いでいるんだ。もういい。"),
                                     DelayTime::create(1),
                                     ClearMessage::create(),
                                     FadeOut::create(.5),
                                     NULL);
    sprite->runAction(sequence);

	CC_ASSERT(!sInstance);
	sInstance = this;
	return true;
}

void Customer::onPresented(const Item& item)
{
    if( std::string(item.getItemName()) == "GoldPan" )
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
				DelayTime::create(3),
				Say::create("ありがとう。"),
				DelayTime::create(1),
				ClearMessage::create(),
				FadeOut::create(.5),
				NULL);
		sprite->runAction(sequence);
	}
}

