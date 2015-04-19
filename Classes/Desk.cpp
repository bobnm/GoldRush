#include "Desk.h"
#include "Util.h"
#include "Customer.h"

using namespace cocos2d;

namespace {
    Desk* sInstance = nullptr;
}

Desk* Desk::getInstance()
{
    CC_ASSERT(sInstance);
    return sInstance;
}

bool Desk::init()
{
    if( !Layer::init() ) return false;
    CC_ASSERT(sInstance == nullptr);
    sInstance = this;
	return true;
}

bool Desk::onDrop(Item* item)
{
	static const Rect sRect(
			130 * 3,
			0,
			Util::GetScreenWidth() - 130 * 3,
			Util::GetScreenHeight() - 180 * 3);
	if( sRect.containsPoint(item->getDragStartPos()) ) return false;
	if( !sRect.containsPoint(item->getPosition()) ) return false;
	log("drop");

	Customer::getInstance()->onPresented(item);

    return true;
}

