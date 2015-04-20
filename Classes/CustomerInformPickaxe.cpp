#include "CustomerInformPickaxe.h"
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

bool CustomerInformPickaxe::init()
{
	if( !Customer::init() ) return false;

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Vec2 center(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y);
	this->setPosition(center + Vec2(150,0));

	auto sprite = Sprite::create("informer.png");
	sprite->getTexture()->setAliasTexParameters();
	sprite->setScale(3);
    this->addChild(sprite, 0);
    
	mReadyToLeave = false;
	mPrice = 0;
    sprite->setOpacity(0);
    auto sequence = Sequence::create(
									 WalkIn::create(.5,Vec2(10,0),10,3),
                                     DelayTime::create(1),
                                     Say::create("元気かァ"),
                                     DelayTime::create(2),
                                     Say::create("俺はァ元気さ"),
                                     DelayTime::create(2),
									 Margin::create(),
                                     Say::create("今日は気分がいい"),
                                     DelayTime::create(1),
                                     Say::create("いいこと教えてやろう"),
                                     DelayTime::create(3),
									 Margin::create(),
                                     Say::create("砂金の時代は終わりだ"),
                                     DelayTime::create(2),
									 Margin::create(),
                                     Say::create("人が増えすぎて"),
                                     DelayTime::create(1),
                                     Say::create("量が激減してんだ"),
                                     DelayTime::create(3),
									 Margin::create(),
                                     Say::create("だからよォ"),
                                     DelayTime::create(1),
									 Say::create("これからは岩を掘るしかねえ"),
									 CallFunc::create([this](){ this->mPrice = 20; }),
                                     DelayTime::create(3),
									 Margin::create(),
									 Say::create("岩を掘る道具でもありゃあ"),
                                     DelayTime::create(1),
									 Say::create("儲かるかもなァ"),
                                     DelayTime::create(3),
									 Margin::create(),
									 Say::create("情報料でも出せば"),
									 CallFunc::create([this](){ this->mPrice = 30; }),
                                     DelayTime::create(1),
									 Say::create("つるはしの仕入れ先"),
                                     DelayTime::create(1),
									 Say::create("教えてやるぜェ"),
                                     DelayTime::create(3),
									 Margin::create(),
									 Say::create("ま、いらねえならいいさ"),
                                     DelayTime::create(2),
									 Say::create("あばヨ"),
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

void CustomerInformPickaxe::onPresented(Item* item)
{
	log("onPresented");
	if( mReadyToLeave ) return;
	if( mPrice == 0 ) return;
    if( std::string(item->getItemID()).find("Dollar") == 0 )
	{
		if( mPrice <= item->getPrice() )
		{
			mPrice = 0;
			auto sprite = this->getChildren().at(0);
			sprite->stopAllActions();
			auto sequence = Sequence::create(
					DelayTime::create(2),
					Say::create("……"),
					DelayTime::create(1),
					Say::create("オーケイ"),
					DelayTime::create(1),
					Margin::create(),
					Say::create("ここにいけ"),
					PutItem::create("MapPickaxe"),
					DelayTime::create(1),
					Margin::create(),
					Say::create("うまくやれよォ"),
					DelayTime::create(1),
					Say::create("またな"),
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
		else
		{
			mPrice -= item->getPrice();
			item->lock();
			auto sprite = this->getChildren().at(0);
			sprite->stopAllActions();
			auto sequence = Sequence::create(
					DelayTime::create(2),
					Say::create("……"),
					DelayTime::create(1),
					Say::create("すくねェな"),
					DelayTime::create(1),
					Say::create("もっとだ"),
					DelayTime::create(2),
					Margin::create(),
					Say::create("もっとくれりゃァ"),
					DelayTime::create(1),
					Say::create("つるはしの仕入れ先"),
					DelayTime::create(1),
					Say::create("教えてやるぜェ"),
					DelayTime::create(3),
					Margin::create(),
					Say::create("ま、いらねえならいいさ"),
					DelayTime::create(2),
					Say::create("あばヨ"),
					DelayTime::create(1),
					CallFunc::create([this](){ this->mReadyToLeave = true; }),
					CallFunc::create([item](){ item->unlock(); }),
					ClearMessage::create(),
					WalkOut::create(.5,Vec2(10,0),10,3),
					NULL);
			sprite->runAction(sequence);
			this->setAction(sequence);
		}
	}
}

