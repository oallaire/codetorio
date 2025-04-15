#include <spdlog/sinks/stdout_color_sinks.h>

#include "CodetorioGame.h"

#include "log/log.h"

using namespace spdlog;

namespace codetorio {

static CodetorioGame game;

ICodetorioGame& getICodetorioGame() {
    return game;
}

CodetorioGame::CodetorioGame() : logger(buildLogger("Game")), tickCount(0) {
}

ITechTree & CodetorioGame::getTechTree() {
}

ILander & CodetorioGame::getLander() {
}

void CodetorioGame::tick() {
    logger.info("Starting tick {}", ++tickCount);
    logger.info("Completed tick {}", tickCount);
}
} // codetorio