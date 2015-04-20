#include "CustomerArrive.h"
#include "CustomerFactory.h"
#include "Customer.h"

using namespace cocos2d;

CustomerArrive* CustomerArrive::create(const std::string& id)
{
    CustomerArrive* ret = new (std::nothrow) CustomerArrive();
    
    if (ret) {
        ret->autorelease();
		ret->init(id);
    }
    
    return ret;
}

CustomerArrive::~CustomerArrive()
{
	if( mCustomer )
	{
		mCustomer->release();
	}
}

void CustomerArrive::init(const std::string& id)
{
	ActionInterval::initWithDuration(9990);
	mID = id;
	mCustomer = nullptr;
}

void CustomerArrive::startWithTarget(Node* target)
{
	ActionInterval::startWithTarget(target);
	auto customer = CustomerFactory::create(mID);
	target->addChild(customer, 70);
	mCustomer = customer;
	mCustomer->retain();
	this->setDuration(mCustomer->getAction()->getDuration());
}
#if 0
void CustomerArrive::stop()
{
	ActionInterval::stop();
	mCustomer->stop();
}
#endif

void CustomerArrive::update(float t)
{
}

bool CustomerArrive::isDone() const
{
	log("isDone = %s", mCustomer->isDone() ? "TRUE" : "FALSE");
	return mCustomer->isDone();
}

ActionInterval* CustomerArrive::reverse() const
{
    return nullptr;
}

CustomerArrive * CustomerArrive::clone() const
{
    // no copy constructor
    auto a = new (std::nothrow) CustomerArrive();
    a->autorelease();
	a->init(mID);
    return a;
}

