#include "ItemDB.h"
#include "Util.h"

namespace {
	const char* sItemID[] = {
		"Dollar100",
		"Dollar50",
		"Dollar20",
		"Dollar10",
		"Dollar5",
		"Dollar2",
		"Dollar1",
		"GoldPan",
		"Pickaxe",
		"Shovel",
	};
	int cDollarIDMax = 6;
}

const char* ItemDB::getNameJa(const std::string& id)
{
    if(id == "GoldPan") return "ゴールドパン";
    if(id == "Dollar100") return "100ドル";
    if(id == "Dollar50") return "50ドル";
    if(id == "Dollar20") return "20ドル";
    if(id == "Dollar10") return "10ドル";
    if(id == "Dollar5") return "5ドル";
    if(id == "Dollar2") return "2ドル";
    if(id == "Dollar1") return "1ドル";
    if(id == "Pickaxe") return "つるはし";
    if(id == "Shovel") return "シャベル";
    CC_ASSERT(false && "Unknown Item ID");
    return nullptr;
}

int ItemDB::getPrice(const std::string& id)
{
	if(id == "GoldPan") return 25;
	if(id == "Dollar100") return 100;
	if(id == "Dollar50") return 50;
	if(id == "Dollar20") return 20;
	if(id == "Dollar10") return 10;
	if(id == "Dollar5") return 5;
	if(id == "Dollar2") return 2;
	if(id == "Dollar1") return 1;
	if(id == "Pickaxe") return 50;
	if(id == "Shovel") return 65;
    CC_ASSERT(false && "Unknown Item ID");
    return 0;
}

const char* ItemDB::getRandomItemID()
{
	return getItemIDByIndex(Util::GetRand(cDollarIDMax + 1, getItemIDMax()));
}

int ItemDB::getItemIDMax()
{
	return sizeof(sItemID) / sizeof(sItemID[0]);
}

const char* ItemDB::getItemIDByIndex(int index)
{
	return sItemID[index];
}

