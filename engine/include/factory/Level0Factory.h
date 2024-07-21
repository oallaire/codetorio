#pragma once

#include <array>

#include <factory/IFactory.h>

namespace codetorio {

template<uint8_t FactoryLevel>
class Level0Factory : public IFactory{
public:
    struct Slot {
        IItem::ItemIdType itemType;
        std::list<std::shared_ptr<IItem>> items;
    };

    SetRecipeResult setRecipe(const std::shared_ptr<IItemRecipe> &recipe) override;
    InsertResult insertItem(const std::shared_ptr<IItem> &item) override;

private:
    std::shared_ptr<IItemRecipe> mRecipe;
    std::array<Slot, FactoryLevel> mSlots;

    uint8_t getFactoryLevel() {
        return FactoryLevel;
    }

    /*
     * Returns a slot capable of storing the requested type.
     */
    Slot& getSlot(IItem::ItemIdType itemType);
};

}// namespace codetorio
