#ifndef __WALK_OUT_H__
#define __WALK_OUT_H__

#include <cocos2d.h>

class WalkOut
{
public:
    static cocos2d::ActionInterval * create(float duration, const cocos2d::Vec2& move, float height, int times); 
    
};

#endif
