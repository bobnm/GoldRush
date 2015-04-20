#ifndef __CUSTOMER_DAY_END_H__
#define __CUSTOMER_DAY_END_H__

#include <cocos2d.h>
#include "Customer.h"

class Item;

class CustomerDayEnd : public Customer {

public:
    CREATE_FUNC(CustomerDayEnd);

public:
    virtual bool init();
	virtual void onPresented(Item* item);

private:
	bool mReadyToLeave;
};

#endif
