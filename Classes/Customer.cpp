#include "Customer.h"
#include "Say.h"

using namespace cocos2d;

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
                                     DelayTime::create(2),
                                     Say::create("俺も金を堀りに来た口さ。"),
                                     DelayTime::create(2),
                                     Say::create("でもいま着いたばかりで"),
                                     DelayTime::create(1),
                                     Say::create("まだ何もわからない。"),
                                     DelayTime::create(4),
                                     Say::create("金は、どこで採れるんだ？"),
                                     DelayTime::create(3),
                                     Say::create("どんな道具がいる？"),
                                     DelayTime::create(5),
                                     Say::create("何か見つくろってくれよ。"),
                                     DelayTime::create(4),
                                     Say::create("まずはなんでもいいんだ。"),
                                     DelayTime::create(3),
                                     Say::create("なにか道具ねえのかい？"),
                                     DelayTime::create(10),
                                     Say::create("急いでいるんだ。もういい。"),
                                     DelayTime::create(1),
                                     FadeOut::create(.5),
                                     NULL);
    sprite->runAction(sequence);
	return true;
}

