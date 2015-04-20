#include "ItemFactory.h"
#include "ItemGoldPan.h"
#include "ItemDollar.h"
#include "ItemPickaxe.h"

Item* ItemFactory::create(const std::string& id)
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
    CC_ASSERT(false && "Unknown Item ID");
    return nullptr;
}

