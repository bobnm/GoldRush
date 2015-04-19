#include "CustomerFactory.h"
#include "CustomerFirst.h"

Customer* CustomerFactory::create(const std::string& id)
{
    if(id == "First") return CustomerFirst::create();
    CC_ASSERT(false && "Unknown Customer ID");
    return nullptr;
}

