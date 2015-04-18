//
//  Say.h
//  GoldRush
//
//  Created by 益田 直生2 on 2015/04/18.
//
//

#ifndef GoldRush_Say_h
#define GoldRush_Say_h

#include <cocos2d.h>

class CC_DLL Say : public cocos2d::ActionInstant
{
public:
    /** Allocates and initializes the action.
     *
     * @return  An autoreleased Show object.
     */
    static Say * create(const char* message);
    
    //
    // Overrides
    //
    /**
     * @param time In seconds.
     */
    virtual void update(float time) override;
    virtual ActionInstant* reverse() const override;
    virtual Say* clone() const override;
    
CC_CONSTRUCTOR_ACCESS:
    Say(){}
    virtual ~Say(){}
    
    void init(const char* message);
    
private:
    CC_DISALLOW_COPY_AND_ASSIGN(Say);

private:
    const char* mMessage;
};

#endif
