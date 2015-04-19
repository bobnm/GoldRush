#include "ItemDB.h"
#include "Util.h"

namespace {
	const char* sItemID[] = {
		"GoldPan",
	};
}

const char* ItemDB::getNameJa(const std::string& id)
{
    if(id == "GoldPan") return "ゴールドパン";
    CC_ASSERT(false && "Unknown Item ID");
    return nullptr;
}

int ItemDB::getPrice(const std::string& id)
{
	if(id == "GoldPan") return 25;
    CC_ASSERT(false && "Unknown Item ID");
    return 0;
}

const char* ItemDB::getRandomItemID()
{
	return getItemIDByIndex(Util::GetRand(getItemIDMax()));
}

int ItemDB::getItemIDMax()
{
	return sizeof(sItemID) / sizeof(sItemID[0]);
}

const char* ItemDB::getItemIDByIndex(int index)
{
	return sItemID[index];
}

