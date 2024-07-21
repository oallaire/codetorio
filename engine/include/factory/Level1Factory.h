#pragma once

#include <factory/Level0Factory.h>

namespace codetorio {

class Level1Factory : public Level0Factory {
protected:
    uint8_t getFactoryLevel() final;

public:
};

}// namespace codetorio
