#pragma once

#include "ItemType.h"

namespace codetorio {

class IRecipe {
public:
    virtual ~IRecipe() = default;

    virtual ItemType getItemType() = 0;
};

} // codetorio
