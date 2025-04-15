#pragma once

#include <cstdint>
#include <spdlog/spdlog.h>

#include "game/ICodetorioGame.h"

namespace codetorio {

class CodetorioGame : public ICodetorioGame {
public:
    CodetorioGame();

    ITechTree & getTechTree() override;
    ILander & getLander() override;
    void tick() override;

private:
    spdlog::logger logger;
    uint64_t tickCount;
};

} // codetorio
