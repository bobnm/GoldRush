#ifndef __PAY_DOLLAR_H__
#define __PAY_DOLLAR_H__

#include <cocos2d.h>

class Item;

class CC_DLL PayDollar : public cocos2d::ActionInstant
{
public:
    /** Allocates and initializes the action.
     *
     * @return  An autoreleased Show object.
     */
    static PayDollar * create(int amount);
    
    //
    // Overrides
    //
    /**
     * @param time In seconds.
     */
    virtual void update(float time) override;
    virtual ActionInstant* reverse() const override;
    virtual PayDollar* clone() const override;
    
CC_CONSTRUCTOR_ACCESS:
    PayDollar(){}
    virtual ~PayDollar(){}
	void init(int amount);
    
private:
    CC_DISALLOW_COPY_AND_ASSIGN(PayDollar);

	int mAmount;
};

#endif
