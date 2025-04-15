#include "log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace codetorio {

static std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> consoleSink;

spdlog::logger buildLogger(const std::string& name) {
    if (nullptr == consoleSink) {
        consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    }
    return spdlog::logger(name, {consoleSink});
}
} // codetorio
