#pragma once

#include "tech/ITechTree.h"
#include "explore/ILander.h"

namespace codetorio {

class ICodetorioGame {
public:
    virtual ~ICodetorioGame() = default;

    virtual ITechTree& getTechTree() = 0;
    virtual ILander& getLander() = 0;

    virtual void tick() = 0;
};

ICodetorioGame& getICodetorioGame();

} // codetorio
