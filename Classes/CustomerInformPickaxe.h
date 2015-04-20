#ifndef __CUSTOMER_INFORM_PICKAXE_H__
#define __CUSTOMER_INFORM_PICKAXE_H__

#include <cocos2d.h>
#include "Customer.h"

class Item;

class CustomerInformPickaxe : public Customer {

public:
    CREATE_FUNC(CustomerInformPickaxe);

public:
    virtual bool init();
	virtual void onPresented(Item* item);

private:
	bool mReadyToLeave;
	int mPrice;
};

#endif
