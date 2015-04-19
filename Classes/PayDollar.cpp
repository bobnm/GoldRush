#include "PayDollar.h"
#include "Player.h"
#include "ItemFactory.h"

using namespace cocos2d;

PayDollar* PayDollar::create(int amount)
{
    PayDollar* ret = new (std::nothrow) PayDollar();
    
    if (ret) {
        ret->autorelease();
		ret->init(amount);
    }
    
    return ret;
}

void PayDollar::init(int amount)
{
	mAmount = amount;
}

void PayDollar::update(float time) {
    CC_UNUSED_PARAM(time);
	while(mAmount > 0)
	{
		if( mAmount >= 100 )
		{
			Item* pay = ItemFactory::create("Dollar100");
			Player::getInstance()->take(pay);
			mAmount -= 100;
		}
		else if( mAmount >= 50 )
		{
			Item* pay = ItemFactory::create("Dollar50");
			Player::getInstance()->take(pay);
			mAmount -= 50;
		}
		else if( mAmount >= 20 )
		{
			Item* pay = ItemFactory::create("Dollar20");
			Player::getInstance()->take(pay);
			mAmount -= 20;
		}
		else if( mAmount >= 10 )
		{
			Item* pay = ItemFactory::create("Dollar10");
			Player::getInstance()->take(pay);
			mAmount -= 10;
		}
		else if( mAmount >= 5 )
		{
			Item* pay = ItemFactory::create("Dollar5");
			Player::getInstance()->take(pay);
			mAmount -= 5;
		}
		else if( mAmount >= 2 )
		{
			Item* pay = ItemFactory::create("Dollar2");
			Player::getInstance()->take(pay);
			mAmount -= 2;
		}
		else if( mAmount >= 1 )
		{
			Item* pay = ItemFactory::create("Dollar1");
			Player::getInstance()->take(pay);
			mAmount -= 1;
		}
	}
}

ActionInstant* PayDollar::reverse() const
{
    return nullptr;
}

PayDollar * PayDollar::clone() const
{
    // no copy constructor
    auto a = new (std::nothrow) PayDollar();
    a->autorelease();
	a->init(mAmount);
    return a;
}

