

#include "factory/Level0Factory.h"

namespace codetorio {
IFactory::SetRecipeResult Level0Factory::setRecipe(const std::shared_ptr<IItemRecipe> &recipe) {
    if (recipe->getLevel() > getFactoryLevel()) {
        return SetRecipeResult::INCOMPATIBLE;
    }
    mRecipe = recipe;
    return IFactory::SetRecipeResult::ACCEPTED;
}

IFactory::InsertResult Level0Factory::insertItem(const std::shared_ptr<IItem> &item) {
    if (mRecipe == nullptr) {
        return IFactory::InsertResult::REFUSED;
    }
    std::list<IItem::ItemIdType> ingredients = mRecipe->getIngredients();
    auto ingredientIt = std::find(ingredients.begin(), ingredients.end(), item->getItemId());
    if (ingredientIt == ingredients.end()) {
        return InsertResult::REFUSED;
    }
}

}// namespace codetorio