//
//  Say.cpp
//  GoldRush
//
//  Created by 益田 直生2 on 2015/04/18.
//
//

#include "Say.h"
#include "MessageBalloon.h"

using namespace cocos2d;

Say* Say::create(const char* message)
{
    Say* ret = new (std::nothrow) Say();
    
    if (ret) {
        ret->autorelease();
        ret->init(message);
    }
    
    return ret;
}

void Say::init(const char* message)
{
    mMessage = message;
}

void Say::update(float time) {
    CC_UNUSED_PARAM(time);
    MessageBalloon::getInstance()->birth(mMessage, MessageBalloon::LEFT);
}

ActionInstant* Say::reverse() const
{
    return nullptr;
}

Say * Say::clone() const
{
    // no copy constructor
    auto a = new (std::nothrow) Say();
    a->autorelease();
    a->init(mMessage);
    return a;
}

