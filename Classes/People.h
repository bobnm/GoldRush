#ifndef __PEOPLE_H__
#define __PEOPLE_H__

#include <cocos2d.h>

class People : public cocos2d::Layer {
public:
    People();
    virtual ~People();
    
public:
    // implement the "static create()" method manually
    CREATE_FUNC(People);

public:
    virtual bool init();
	void update(float delta);

private:
    static const int cSpriteNum = 2;
    cocos2d::Vector<cocos2d::Sprite*>* mSprite;
};

#endif
