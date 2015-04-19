#include "ShopScene.h"
#include "Customer.h"
#include "People.h"
#include "MessageBalloon.h"
#include "Player.h"

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
		auto customer = Customer::create();
		customer->setPosition(center + Vec2(150,0));
		this->addChild(customer, 70);
	}
    {
        auto player = Player::create();
        this->addChild(player, 500);
    }

#if 0
	{
		auto listener = EventListenerTouchOneByOne::create();
		//listener->setSwallowTouches(true);

		listener->onTouchBegan = CC_CALLBACK_2(Shop::onTouchBegan_, this);
		listener->onTouchMoved = CC_CALLBACK_2(Shop::onTouchMoved_, this);
		listener->onTouchEnded = CC_CALLBACK_2(Shop::onTouchEnded_, this);
		listener->onTouchCancelled = CC_CALLBACK_2(Shop::onTouchCancelled_, this);

		this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	}
#endif

    return true;
}

#if 0
bool Shop::onTouchBegan_(Touch* touch, Event* event)
{
	auto target = event->getCurrentTarget();
	if( target != this ) return false;
	log("%f, %f", touch->getLocation().x, touch->getLocation().y);
	Vec2 local = target->convertToNodeSpace(touch->getLocation());
	log("  -> %f, %f", local.x, local.y);
    return true;
}

void Shop::onTouchMoved_(Touch* touch, Event* event)
{
	log("sprite onTouchesMoved.. ");
}

void Shop::onTouchEnded_(Touch* touch, Event* event)
{
	log("sprite onTouchesEnded.. ");
}

void Shop::onTouchCancelled_(Touch* touch, Event* event)
{
	log("sprite onTouchesCancelled.. ");
}

#endif

