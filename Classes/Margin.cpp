#include "Margin.h"
#include "Say.h"

using namespace cocos2d;

ActionInterval* Margin::create()
{
	return Sequence::create(
			Say::create(""),
			DelayTime::create(0.1),
			NULL);
}

