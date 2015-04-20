#include "ShopScene.h"
#include "CustomerFactory.h"
#include "People.h"
#include "MessageBalloon.h"
#include "Player.h"
#include "Desk.h"
#include "ItemLayer.h"

USING_NS_CC;

Scene* Shop::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Shop::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Shop::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	srand((unsigned int)time(NULL));
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Vec2 center(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y);

    {
        auto balloon = MessageBalloon::create();
        this->addChild(balloon, 200);
    }
	{
		auto sprite = Sprite::create("bg.png");
		sprite->getTexture()->setAliasTexParameters();
		sprite->setPosition(center);
		sprite->setScale(3);
		this->addChild(sprite, 0);
	}
	{
		auto people = People::create();
		people->setPosition(center + Vec2(0, 60));
		this->addChild(people, 50);
	}

	{
		auto sprite = Sprite::create("table.png");
		sprite->getTexture()->setAliasTexParameters();
		sprite->setPosition(center);
		sprite->setScale(3);
		this->addChild(sprite, 100);
	}

	{
		auto desk = Desk::create();
		this->addChild(desk, 130);
	}

    {
        auto item_layer = ItemLayer::create();
		item_layer->createPlayerInventoryItem();
        this->addChild(item_layer, 500);
    }

	mCount = 0;
	this->scheduleUpdate();

    return true;
}

void Shop::update(float t)
{
	static const char* sSeq[] = {
		//"First",
		"Random",
		"Random",
		"Random",
		"Random",
		"Random",
		"Random",
		"InformPickaxe",
		"Random",
		"Random",
		"Random",
	};

	if( Customer* c = Customer::getInstance() )
	{
		if( c->isDone() )
		{
			mCount++;
			Customer::deleteInstance();
		}
	}
	else
	{
		if( mCount < (sizeof(sSeq) / sizeof(sSeq[0])) )
		{
			c = CustomerFactory::create(sSeq[mCount]);
			this->addChild(c, 70);
		}
	}
}


