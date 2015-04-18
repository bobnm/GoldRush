#ifndef __UTIL_H__
#define __UTIL_H__
#include <cocos2d.h>
namespace Util {
	int GetScreenWidth()
	{
        using namespace cocos2d;
		Size visibleSize = Director::getInstance()->getVisibleSize();
		return visibleSize.width;
	}
	int GetScreenHeight()
	{
        using namespace cocos2d;
		Size visibleSize = Director::getInstance()->getVisibleSize();
		return visibleSize.height;
	}
}
#endif
