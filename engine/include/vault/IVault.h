#pragma once

#include "connection/IConnectableEntity.h"
#include "recipe/ItemType.h"
#include "types/types.h"

namespace codetorio {

class IVault : public IConnectableEntity {
public:
    virtual level getLevel() = 0;
    virtual uint64_t getItemCount(ItemType type) = 0;
    virtual uint64_t getSlotCount() = 0;
    virtual uint64_t getFreeSlotCount() = 0;
    virtual uint64_t getUsedSlotCount() = 0;
};

} // codetorio
