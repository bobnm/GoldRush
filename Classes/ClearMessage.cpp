//
//  ClearMessage.cpp
//  GoldRush
//
//  Created by 益田 直生2 on 2015/04/18.
//
//

#include "ClearMessage.h"
#include "MessageBalloon.h"

using namespace cocos2d;

ClearMessage* ClearMessage::create()
{
    ClearMessage* ret = new (std::nothrow) ClearMessage();
    
    if (ret) {
        ret->autorelease();
    }
    
    return ret;
}


void ClearMessage::update(float time) {
    CC_UNUSED_PARAM(time);
    MessageBalloon::getInstance()->clear();
}

ActionInstant* ClearMessage::reverse() const
{
    return nullptr;
}

ClearMessage * ClearMessage::clone() const
{
    // no copy constructor
    auto a = new (std::nothrow) ClearMessage();
    a->autorelease();
    return a;
}

