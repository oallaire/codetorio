#pragma once

#include <memory>

#include <item/IItem.h>
#include <item/IItemRecipe.h>

namespace codetorio {

class IFactory {
public:
    enum class SetRecipeResult {
        ACCEPTED,
        INCOMPATIBLE
    };

    enum class InsertResult {
        ACCEPTED,
        REFUSED,
        FULL
    };

    virtual ~IFactory() = default;

    virtual SetRecipeResult setRecipe(const std::shared_ptr<IItemRecipe> &recipe) = 0;
    virtual InsertResult insertItem(const std::shared_ptr<IItem> &item) = 0;
    virtual std::shared_ptr<IItem> build() = 0;
};

}// namespace codetorio
