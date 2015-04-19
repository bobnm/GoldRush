#ifndef __CUSTOMER_RANDOM_H__
#define __CUSTOMER_RANDOM_H__

#include <cocos2d.h>
#include "Customer.h"

class Item;

class CustomerRandom : public Customer {

public:
    CREATE_FUNC(CustomerRandom);

public:
    virtual bool init();
	virtual void onPresented(Item* item);

private:
	std::string mNeedItemID;
	std::string mMessageKure;
	std::string mMessageDa;
	bool mDone;
};

#endif
