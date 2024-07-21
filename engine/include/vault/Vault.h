#pragma once

#include <cstdint>
#include <list>
#include <memory>

#include <item/IItem.h>

namespace codetorio {

class Vault {
public:
    template<class ItemClass>
    uint64_t getItemCount();

protected:
    std::list<std::shared_ptr<IItem>> items;
};

}// namespace codetorio
