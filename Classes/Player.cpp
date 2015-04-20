#include "Player.h"
#include "MessageBalloon.h"

using namespace cocos2d;

namespace {
    Player* sInstance = nullptr;
}

Player* Player::create()
{
	auto player = new(std::nothrow) Player();
	if( player )
	{
		//player->autorelease();
		player->init();
	}
	return player;
}
Player* Player::getInstance()
{
    return sInstance;
}

bool Player::init()
{
    mInventory = new std::vector<std::string>();

#if 0
    mInventory->push_back("GoldPan");
    mInventory->push_back("GoldPan");
    mInventory->push_back("GoldPan");
    mInventory->push_back("GoldPan");
    mInventory->push_back("Pickaxe");
    mInventory->push_back("Pickaxe");
    mInventory->push_back("Shovel");
    mInventory->push_back("Dollar1");
    mInventory->push_back("Dollar1");
    mInventory->push_back("Dollar10");
    mInventory->push_back("Dollar10");
    mInventory->push_back("Dollar20");
    mInventory->push_back("Dollar20");
    mInventory->push_back("Dollar20");
    mInventory->push_back("Dollar50");
#else
    mInventory->push_back("GoldPan");
    mInventory->push_back("GoldPan");
    mInventory->push_back("GoldPan");
#endif
    
    CC_ASSERT(sInstance == nullptr);
    sInstance = this;
	//sInstance->retain();
    return true;
}

void Player::sell(Item* item)
{
    mInventory->erase(std::remove(mInventory->begin(), mInventory->end(), item->getItemID()));
	item->sell();
}

void Player::take(Item* item)
{
	mInventory->push_back(item->getItemID());
	item->take();
}

void Player::sayItemName(Item* item)
{
	MessageBalloon::getInstance()->birth(item->getNameJa(), MessageBalloon::RIGHT);
}

