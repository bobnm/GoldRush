#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include <cocos2d.h>

class Customer : public cocos2d::Layer {

public:
    // implement the "static create()" method manually
    CREATE_FUNC(Customer);

public:
    virtual bool init();

public:
	//const Item& getNeedItem() const;
	int getMoney() const { return mMoney; }

private:
	int mMoney;
};

#endif
