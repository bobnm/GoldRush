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

void Customer::setSingleton(Customer* customer)
{
	sInstance = customer;
	sInstance->retain();
}

bool Customer::init()
{
	if( !Layer::init() ) return false;
	return true;
}

