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
    mUnlockedItem = new std::vector<std::string>();

    mUnlockedItem->push_back("Dollar1");
    mUnlockedItem->push_back("Dollar2");
    mUnlockedItem->push_back("Dollar5");
    mUnlockedItem->push_back("Dollar10");
    mUnlockedItem->push_back("Dollar20");
    mUnlockedItem->push_back("Dollar50");
    mUnlockedItem->push_back("Dollar100");
	mUnlockedItem->push_back("GoldPan");
#if 0
	mUnlockedItem->push_back("Pickaxe");
	mUnlockedItem->push_back("Shovel");
#endif

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
	// 全部消したらダメ
    //mInventory->erase(std::remove(mInventory->begin(), mInventory->end(), item->getItemID()));
	for(auto it = mInventory->begin(), end = mInventory->end();
		it != end;
		++it)
	{
		if( *it == item->getItemID() )
		{
			mInventory->erase(it);
			break;
		}
	}
	item->sell();
}

void Player::take(Item* item)
{
	mInventory->push_back(item->getItemID());
	if( !isUnlockedItem(item->getItemID()) )
	{
		mUnlockedItem->push_back(item->getItemID());
	}
	item->take();
}

void Player::sayItemName(Item* item)
{
	MessageBalloon::getInstance()->birth(item->getNameJa(), MessageBalloon::RIGHT);
}

bool Player::isUnlockedItem(const std::string& item_id)
{
	return std::find(mUnlockedItem->begin(), mUnlockedItem->end(), item_id) != std::end(*mUnlockedItem);
}

bool Player::hasItem(const std::string& item_id)
{
	return std::find(mInventory->begin(), mInventory->end(), item_id) != std::end(*mInventory);
}
