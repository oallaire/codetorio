#pragma once

#include <expected>
#include <memory>

#include "Tech.h"
#include "types/types.h"
#include "recipe/IRecipe.h"

namespace codetorio {

enum class TechStatus {
    UNLOCKED,
    LOCKED,
    UNLOCKABLE,
    RESEARCHING
};

enum class TechResearchError {
    IN_PROGRESS,
    COMPLETED,
    UNAVAILABLE
};

enum class ActiveResearchError {
    NOT_RESEARCHING
};

enum class GetRecipeError {
    NOT_RESEARCHED
};

class ITechTree {
public:
    virtual ~ITechTree() = default;

    virtual TechStatus getTechStatus(Tech tech) = 0;
    virtual std::unexpected<TechResearchError> research(Tech tech) = 0;
    virtual std::expected<percentage, TechResearchError> getProgress(Tech tech) = 0;
    virtual std::expected<Tech, ActiveResearchError> getActiveResearch() = 0;

    virtual std::expected<std::shared_ptr<IRecipe>, GetRecipeError> getRecipe(ItemType itemType) = 0;
};

} // codetorio
