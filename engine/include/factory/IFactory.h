#pragma once

#include <expected>

#include "connection/IConnectableEntity.h"
#include "recipe/IRecipe.h"
#include "types/types.h"

namespace codetorio {

enum class SetRecipeError {
    ALREADY_SET,
    LEVEL_TOO_LOW
};

enum class FactoryStatus {
    IDLE,
    CRAFTING,
    FULL
};

class IFactory : public IConnectableEntity {
public:
    virtual level getLevel() const = 0;
    virtual std::unexpected<SetRecipeError> setRecipe(const std::shared_ptr<IRecipe> &recipe) = 0;
};

} // codetorio
