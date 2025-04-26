#pragma once

#include <cstdint>
#include <expected>

namespace codetorio {

typedef uint8_t level;
typedef double percentage;
typedef int expected_void_value;

constexpr expected_void_value _ = 0;

template <class E>
using expected_void = std::expected<expected_void_value, E>;

} // codetorio
