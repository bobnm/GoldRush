#include "Item.h"
#include "Desk.h"
#include "Util.h"

using namespace cocos2d;

bool Item::init()
{
    if( !Layer::init() ) return false;
	return true;
}

void Item::initTouch(Node* node)
{
    auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

    listener->onTouchBegan = CC_CALLBACK_2(Item::onTouchBegan_, this);
    listener->onTouchMoved = CC_CALLBACK_2(Item::onTouchMoved_, this);
    listener->onTouchEnded = CC_CALLBACK_2(Item::onTouchEnded_, this);
    listener->onTouchCancelled = CC_CALLBACK_2(Item::onTouchCancelled_, this);

    node->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, node);
	mTouchNode = node;
	mTouchNode->retain();
}

bool Item::onTouchBegan_(Touch* touch, Event* event)
{
	if( !mTouchNode ) return false;
	if( mLock ) return false;
	Vec2 local = mTouchNode->convertToNodeSpaceAR(touch->getLocation()) * mTouchNode->getScale();
	Rect rect = mTouchNode->getBoundingBox();
	//log("(%f, %f) -> (%f, %f) / (%f, %f, %f, %f)",
	//		touch->getLocation().x, touch->getLocation().y,
	//		local.x, local.y,
	//		rect.getMinX(), rect.getMinY(), rect.getMaxX(), rect.getMaxY());
    if( !mTouchNode->getBoundingBox().containsPoint(local) ) return false;
	mOriginalScale = mTouchNode->getScale();
	mOriginalOpacity = mTouchNode->getOpacity();
	mTouchNode->setScale(mOriginalScale * 0.8f);
	mTouchNode->setOpacity(mOriginalOpacity * 0.6f);
	mTouchOffset = local;
	mDragStartPos = touch->getLocation();
	//log("sprite onToucheBegan.. ");
    return true;
}

void Item::onTouchMoved_(Touch* touch, Event* event)
{
	//log("sprite onTouchesMoved.. ");
	this->setPosition(touch->getLocation() - mTouchOffset);
}

void Item::onTouchEnded_(Touch* touch, Event* event)
{
	//log("sprite onTouchesEnded.. ");
	mTouchNode->setScale(mOriginalScale);
	mTouchNode->setOpacity(mOriginalOpacity);
    
    Desk::getInstance()->onDrop(this);
}

void Item::onTouchCancelled_(Touch* touch, Event* event)
{
	//log("sprite onTouchesCancelled.. ");
	mTouchNode->setScale(mOriginalScale);
	mTouchNode->setOpacity(mOriginalOpacity);
}

void Item::sell()
{
	auto sprite = this->getChildren().at(0);
	sprite->stopAllActions();
	auto sequence = Sequence::create(
			FadeOut::create(.5),
			CallFunc::create([this](){ this->removeFromParent(); }),
			NULL);
	sprite->runAction(sequence);
}

void Item::take()
{
	this->setPosition(Vec2(500 + Util::GetRand(100), 100 + Util::GetRand(80)));
}

