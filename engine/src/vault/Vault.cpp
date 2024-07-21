#include "vault/Vault.h"

namespace codetorio {

template<class ItemClass>
uint64_t Vault::getItemCount() {
    static_assert(std::is_base_of<IItem, ItemClass>::value, "Must fetch items only");
    uint64_t itemCount = 0;
    for (const auto &item : items) {
        if (const auto& _ = std::dynamic_pointer_cast<ItemClass>(item)) {
            itemCount++;
        }
    }
    return itemCount;
}

}// namespace codetorio