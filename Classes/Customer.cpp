#include "Customer.h"

using namespace cocos2d;

namespace {
    Customer* sInstance = nullptr;
}

Customer* Customer::getInstance()
{
    CC_ASSERT(sInstance);
    return sInstance;
}

void Customer::deleteInstance()
{
	if( !sInstance ) return;
	sInstance->removeFromParent();
	sInstance->release();
	sInstance = nullptr;
}

void Customer::setSingleton(Customer* customer)
{
	sInstance = customer;
	sInstance->retain();
}

void Customer::setAction(cocos2d::FiniteTimeAction* action)
{
	mAction = action;
	mAction->retain();
}

bool Customer::init()
{
	if( !Layer::init() ) return false;
	mAction = nullptr;
	return true;
}

