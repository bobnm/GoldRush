

#ifndef GoldRush_ClearMessage_h
#define GoldRush_ClearMessage_h

#include <cocos2d.h>

class CC_DLL ClearMessage : public cocos2d::ActionInstant
{
public:
    /** Allocates and initializes the action.
     *
     * @return  An autoreleased Show object.
     */
    static ClearMessage * create();
    
    //
    // Overrides
    //
    /**
     * @param time In seconds.
     */
    virtual void update(float time) override;
    virtual ActionInstant* reverse() const override;
    virtual ClearMessage* clone() const override;
    
CC_CONSTRUCTOR_ACCESS:
    ClearMessage(){}
    virtual ~ClearMessage(){}
    
private:
    CC_DISALLOW_COPY_AND_ASSIGN(ClearMessage);
};

#endif
