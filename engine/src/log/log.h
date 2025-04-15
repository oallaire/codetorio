#pragma once

#include <spdlog/spdlog.h>

namespace codetorio {

spdlog::logger buildLogger(const std::string& name);

}
