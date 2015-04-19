#ifndef __BUY_H__
#define __BUY_H__

#include <cocos2d.h>

class Item;

class CC_DLL Buy : public cocos2d::ActionInstant
{
public:
    /** Allocates and initializes the action.
     *
     * @return  An autoreleased Show object.
     */
    static Buy * create(Item* item);
    
    //
    // Overrides
    //
    /**
     * @param time In seconds.
     */
    virtual void update(float time) override;
    virtual ActionInstant* reverse() const override;
    virtual Buy* clone() const override;
    
CC_CONSTRUCTOR_ACCESS:
    Buy(){}
    virtual ~Buy(){}
	void init(Item* item);
    
private:
    CC_DISALLOW_COPY_AND_ASSIGN(Buy);

	Item* mItem;
};

#endif
