#ifndef __CUSTOMERARRIVE_H__
#define __CUSTOMERARRIVE_H__

#include <cocos2d.h>

class Customer;
class CC_DLL CustomerArrive : public cocos2d::ActionInterval
{
public:
    /** Allocates and initializes the action.
     *
     * @return  An autoreleased Show object.
     */
    static CustomerArrive * create(const std::string& id);
    
    //
    // Overrides
    //
    /**
     * @param time In seconds.
     */
    virtual void startWithTarget(cocos2d::Node *target) override;
    virtual cocos2d::ActionInterval* reverse() const override;
    virtual CustomerArrive* clone() const override;
	virtual bool isDone() const override;
	virtual void update(float t) override;
	//virtual void stop() override;
    
CC_CONSTRUCTOR_ACCESS:
    CustomerArrive(){}
    virtual ~CustomerArrive();
	void init(const std::string& id);
    
private:
    CC_DISALLOW_COPY_AND_ASSIGN(CustomerArrive);

	std::string mID;
	Customer* mCustomer;
};

#endif
