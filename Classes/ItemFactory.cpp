#include "ItemFactory.h"
#include "ItemGoldPan.h"
#include "ItemDollar.h"
#include "ItemPickaxe.h"
#include "ItemShovel.h"
#include "ItemMapPickaxe.h"
#include "ItemLayer.h"

namespace {
	Item* CreateItemImpl_(const std::string& id)
	{
		if(id == "GoldPan") return GoldPan::create();
		if(id == "Dollar100") return Dollar::create(100);
		if(id == "Dollar50") return Dollar::create(50);
		if(id == "Dollar20") return Dollar::create(20);
		if(id == "Dollar10") return Dollar::create(10);
		if(id == "Dollar5") return Dollar::create(5);
		if(id == "Dollar2") return Dollar::create(2);
		if(id == "Dollar1") return Dollar::create(1);
		if(id == "Pickaxe") return Pickaxe::create();
		if(id == "Shovel") return Shovel::create();
		if(id == "MapPickaxe") return MapPickaxe::create();
		CC_ASSERT(false && "Unknown Item ID");
		return nullptr;
	}
}

Item* ItemFactory::create(const std::string& id)
{
	Item* item = CreateItemImpl_(id);
	if( item )
	{
		ItemLayer::getInstance()->addItem(item);
	}
	return item;
}

