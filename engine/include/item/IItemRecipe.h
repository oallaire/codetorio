#pragma once

#include <cstdint>
#include <list>
#include <memory>

#include <item/IItem.h>

namespace codetorio {

class IItemRecipe {
public:
    virtual ~IItemRecipe() = default;

    virtual uint8_t getLevel() = 0;
    virtual std::list<IItem::ItemIdType> getIngredients() = 0;
    virtual std::shared_ptr<IItem> build(const std::list<std::shared_ptr<IItem>> &items) = 0;
};

}// namespace codetorio
