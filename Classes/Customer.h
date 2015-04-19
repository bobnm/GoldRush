#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include <cocos2d.h>

class Item;
class Customer : public cocos2d::Layer {

public:
    CREATE_FUNC(Customer);

public:
    virtual bool init();

    static Customer* getInstance();

protected:
	void setSingleton(Customer* customer);

public:
	virtual void onPresented(Item* item) { CC_UNUSED_PARAM(item); }
};

#endif
