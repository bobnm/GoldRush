#include "Util.h"
#include <cocos2d.h>

using namespace cocos2d;

namespace Util {
    
int GetScreenWidth()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	return visibleSize.width;
}

int GetScreenHeight()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	return visibleSize.height;
}

float GetRand(float max)
{
	return (float)rand() / RAND_MAX * max;
}

int GetRand(int max)
{
	return (int)GetRand((float)max);
}

int GetRand(int min, int max)
{
	return GetRand(max - min) + min;
}

}

