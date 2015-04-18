#include "People.h"
#include "Util.h"

using namespace cocos2d;

People::People()
: Layer()
{
}

People::~People()
{
    delete mSprite;
}

bool People::init()
{
	if( !Layer::init() ) return false;
    mSprite = new Vector<Sprite*>(cSpriteNum);
    CC_ASSERT(mSprite->capacity() == cSpriteNum);
	for(int i = 0; i < cSpriteNum; i++)
	{
        auto sprite = Sprite::create("people.png");
		sprite->getTexture()->setAliasTexParameters();
        //sprite->setAnchorPoint(Vec2::ZERO);
		sprite->setScale(3);
        sprite->setPosition(Vec2(-Util::GetScreenWidth() + Util::GetScreenWidth() * i, 20));
		mSprite->pushBack(sprite);
		this->addChild(sprite);
		this->scheduleUpdate();
	}
	return true;
}

void People::update(float delta)
{
    for(auto sprite : *mSprite)
	{
		sprite->setPosition(sprite->getPosition() + Vec2(100 * delta, 0));
		if( sprite->getPosition().x > Util::GetScreenWidth() )
		{
            sprite->setPosition(Vec2(-Util::GetScreenWidth(), 20));
		}
	}
}

