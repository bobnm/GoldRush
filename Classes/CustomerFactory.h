#ifndef __CUSTOMER_FACTORY_H__
#define __CUSTOMER_FACTORY_H__

#include <cocos2d.h>
#include "Customer.h"

class CustomerFactory {
public:
    static Customer* create(const std::string& id);
};

#endif

