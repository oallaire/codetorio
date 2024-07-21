#pragma once

#include <string>

namespace codetorio {

class IItem {
public:
    typedef std::string ItemIdType;

    virtual ~IItem() = default;
    virtual ItemIdType getItemId() = 0;
};

}// namespace codetorio
