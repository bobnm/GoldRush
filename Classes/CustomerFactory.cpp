#include "CustomerFactory.h"
#include "CustomerFirst.h"
#include "CustomerRandom.h"
#include "CustomerInformPickaxe.h"

Customer* CustomerFactory::create(const std::string& id)
{
	Customer::deleteInstance();
    if(id == "First") return CustomerFirst::create();
    if(id == "Random") return CustomerRandom::create();
    if(id == "InformPickaxe") return CustomerInformPickaxe::create();
    CC_ASSERT(false && "Unknown Customer ID");
    return nullptr;
}

