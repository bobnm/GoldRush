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
	static void deleteInstance();

	cocos2d::FiniteTimeAction* getAction() const { return mAction; }
	bool isDone() const { return !mAction || mAction->isDone(); }
	void stop() { if( mAction ) { mAction->stop(); } }

protected:
	void setSingleton(Customer* customer);
	void setAction(cocos2d::FiniteTimeAction* action);

public:
	virtual void onPresented(Item* item) { CC_UNUSED_PARAM(item); }

private:
	cocos2d::FiniteTimeAction* mAction;
};

#endif
