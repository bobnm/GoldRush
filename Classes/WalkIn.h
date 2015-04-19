#ifndef __WALK_IN_H__
#define __WALK_IN_H__

#include <cocos2d.h>

class WalkIn
{
public:
    static cocos2d::ActionInterval * create(float duration, const cocos2d::Vec2& move, float height, int times); 
    
};

#endif
