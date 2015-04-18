#ifndef __MESSAGE_BALLOON_H__
#define __MESSAGE_BALLOON_H__

#include <cocos2d.h>

class MessageBalloon : public cocos2d::Layer {
public:
	static MessageBalloon* getInstance();

    CREATE_FUNC(MessageBalloon);

	virtual bool init();

public:
	enum Side {
		LEFT,
		RIGHT
	};

public:
	void birth(const char* message, Side side);

private:
    void killOldBalloon();
    void moveUpwardActiveBalloon();
    
private:
	cocos2d::Vector<cocos2d::Label*>* mUseLabel;
	cocos2d::Vector<cocos2d::Label*>* mFreeLabel;
	cocos2d::Vector<cocos2d::Sprite*>* mUseBalloon;
	cocos2d::Vector<cocos2d::Sprite*>* mFreeBalloon;
};

#endif

