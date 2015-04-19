#include "MessageBalloon.h"
#include "Util.h"

using namespace cocos2d;

namespace {
MessageBalloon* sInstance = nullptr;
}

MessageBalloon* MessageBalloon::getInstance()
{
    CC_ASSERT(sInstance);
    return sInstance;
}

bool MessageBalloon::init()
{
    if( !Layer::init() ) return false;
	static const int cNum = 8;
	mUseLabel = new Vector<Label*>(cNum);
	mFreeLabel = new Vector<Label*>(cNum);
	mUseBalloon = new Vector<Sprite*>(cNum);
	mFreeBalloon = new Vector<Sprite*>(cNum);
	for(int i = 0; i < cNum; i++)
	{
        mFreeLabel->pushBack(Label::createWithSystemFont("", "HiraKakuProN-W6", 22));
		auto sprite = Sprite::create("balloon.png");
		sprite->getTexture()->setAliasTexParameters();
		sprite->setScale(3);
		mFreeBalloon->pushBack(sprite);
	}
    
    sInstance = this;
	sInstance->retain();
    return true;
}

void MessageBalloon::birth(const char* message, Side side)
{
	if( mFreeLabel->empty() )
	{
		this->killOldBalloon();
	}
    
    this->moveUpwardActiveBalloon();

    auto label = mFreeLabel->front();
	auto balloon = mFreeBalloon->front();
	label->setString(message);
	if( side == LEFT )
	{
		label->setAnchorPoint(Vec2::ZERO);
		label->setAlignment(TextHAlignment::LEFT);
		label->setPosition(Vec2(350,300));
		balloon->setAnchorPoint(Vec2::ZERO);
		balloon->setPosition(Vec2(350 - 10, 300));
	}
	else
	{
		label->setAnchorPoint(Vec2(1,0));
		label->setAlignment(TextHAlignment::RIGHT);
		label->setPosition(Vec2(Util::GetScreenWidth() - 20,300));
		balloon->setAnchorPoint(Vec2(1,0));
		balloon->setPosition(Vec2(Util::GetScreenWidth() - 20 + 10, 300));
	}
	if( std::string(message) != "" )
	{
		this->addChild(balloon);
		this->addChild(label);
	}
    mUseLabel->pushBack(label);
    mUseBalloon->pushBack(balloon);
    mFreeLabel->erase(0);
    mFreeBalloon->erase(0);
}

void MessageBalloon::clear()
{
    for(auto label : *mUseLabel)
    {
        mFreeLabel->pushBack(label);
        this->removeChild(label);
    }
    for(auto balloon : *mUseBalloon)
    {
        mFreeBalloon->pushBack(balloon);
        this->removeChild(balloon);
    }
    mUseLabel->clear();
    mUseBalloon->clear();
}

void MessageBalloon::killOldBalloon()
{
	if( mUseLabel->empty() ) return;
	if( mUseBalloon->empty() ) return;
	auto label = mUseLabel->front();
	auto balloon = mUseBalloon->front();
	if( label->getParent() == this )
	{
		this->removeChild(label);
	}
	if( balloon->getParent() == this )
	{
		this->removeChild(balloon);
	}
    mFreeLabel->pushBack(label);
    mFreeBalloon->pushBack(balloon);
    mUseLabel->erase(0);
	mUseBalloon->erase(0);
}

void MessageBalloon::moveUpwardActiveBalloon()
{
    for(auto label : *mUseLabel)
    {
		if( label->getParent() != this ) continue;
        label->runAction(MoveBy::create(0.1, Vec2(0, 30)));
    }
    for(auto balloon : *mUseBalloon)
    {
		if( balloon->getParent() != this ) continue;
        balloon->runAction(MoveBy::create(0.1, Vec2(0, 30)));
    }
}

