#include "WalkIn.h"

using namespace cocos2d;

ActionInterval* WalkIn::create(float duration, const Vec2& move, float height, int times)
{
	return Spawn::create(
			FadeIn::create(duration),
			JumpBy::create(duration,move,height,times),
			NULL);
}

