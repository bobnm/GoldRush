#ifndef __ITEM_DB_H__
#define __ITEM_DB_H__

class ItemDB {
public:
    static const char* getNameJa(const std::string& id);
    static int getPrice(const std::string& id);
	static const char* getRandomItemID();
	static int getItemIDMax();
	static const char* getItemIDByIndex(int index);
};

#endif

