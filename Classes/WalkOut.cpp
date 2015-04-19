#include "WalkOut.h"

using namespace cocos2d;

ActionInterval* WalkOut::create(float duration, const Vec2& move, float height, int times)
{
	return Spawn::create(
			FadeOut::create(duration),
			JumpBy::create(duration,move,height,times),
			NULL);
}

