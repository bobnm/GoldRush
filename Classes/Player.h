#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Item.h"

class Player {
    
public:
	static Player* create();
    static Player* getInstance();
    
public:
    bool init();

	void sell(Item* item);
	void take(Item* item);

	void sayItemName(Item* item);

	std::vector<std::string>* getInventory() { return mInventory; }
	bool isUnlockedItem(const std::string& item_id);
	bool hasItem(const std::string& item_id);
    
private:
    std::vector<std::string>* mInventory;
    std::vector<std::string>* mUnlockedItem;
};
#endif

