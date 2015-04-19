#include "CustomerFactory.h"
#include "CustomerFirst.h"
#include "CustomerRandom.h"

Customer* CustomerFactory::create(const std::string& id)
{
    if(id == "First") return CustomerFirst::create();
    if(id == "Random") return CustomerRandom::create();
    CC_ASSERT(false && "Unknown Customer ID");
    return nullptr;
}

