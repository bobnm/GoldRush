#include "Player.h"
#include "ItemFactory.h"
#include "Util.h"
#include "MessageBalloon.h"

using namespace cocos2d;

namespace {
    Player* sInstance = nullptr;
}

Player* Player::getInstance()
{
    return sInstance;
}

bool Player::init()
{
    if( !Layer::init() ) return false;
    
    static const int cMaxItem = 32;
    mInventoryID = new std::vector<std::string>();
    mInventory = new Vector<Item*>(cMaxItem);

    mInventoryID->push_back("GoldPan");
    mInventoryID->push_back("GoldPan");
    mInventoryID->push_back("GoldPan");
    mInventoryID->push_back("GoldPan");
    
    int i = 0;
    for(auto item_id : *mInventoryID)
    {
        log("%d = %s\n", i, item_id.c_str());
        Item* item = ItemFactory::create(item_id);
        CC_ASSERT(item != nullptr);
        item->setPosition(Vec2(70 + 32 * 3 * (i % 3), 550 - (32 + 10) * 3 * (i / 3)));
        mInventory->pushBack(item);
        this->addChild(item);
        i++;
    }
    CC_ASSERT(sInstance == nullptr);
    sInstance = this;
	sInstance->retain();
    return true;
}

void Player::sell(Item* item)
{
	mInventory->eraseObject(item);
	item->sell();
}

void Player::take(Item* item)
{
	mInventory->pushBack(item);
	item->setPosition(Vec2(500 + Util::GetRand(100), 100 + Util::GetRand(80)));
	this->addChild(item);
}

void Player::sayItemName(Item* item)
{
	MessageBalloon::getInstance()->birth(item->getNameJa(), MessageBalloon::RIGHT);
}

