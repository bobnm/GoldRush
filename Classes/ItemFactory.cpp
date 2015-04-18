#include "ItemFactory.h"
#include "ItemGoldPan.h"

Item* ItemFactory::create(const std::string& id)
{
    if(id == "GoldPan") return GoldPan::create();
    CC_ASSERT(false && "Unknown Item ID");
    return nullptr;
}

