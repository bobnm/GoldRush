#ifndef __PUT_ITEM_H__
#define __PUT_ITEM_H__

#include <cocos2d.h>

class Item;

class CC_DLL PutItem : public cocos2d::ActionInstant
{
public:
    /** Allocates and initializes the action.
     *
     * @return  An autoreleased Show object.
     */
    static PutItem * create(const std::string& id);
    
    //
    // Overrides
    //
    /**
     * @param time In seconds.
     */
    virtual void update(float time) override;
    virtual ActionInstant* reverse() const override;
    virtual PutItem* clone() const override;
    
CC_CONSTRUCTOR_ACCESS:
    PutItem(){}
    virtual ~PutItem(){}
	void init(const std::string& id);
    
private:
    CC_DISALLOW_COPY_AND_ASSIGN(PutItem);

	std::string mID;
};

#endif
