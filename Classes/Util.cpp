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

}

