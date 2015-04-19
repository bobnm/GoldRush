#ifndef __CUSTOMER_FIRST_H__
#define __CUSTOMER_FIRST_H__

#include <cocos2d.h>
#include "Customer.h"

class Item;

class CustomerFirst : public Customer {

public:
    CREATE_FUNC(CustomerFirst);

public:
    virtual bool init();
	virtual void onPresented(Item* item);

private:
	bool mDone;
};

#endif
