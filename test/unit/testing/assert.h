#pragma once

#include <gtest/gtest.h>

#define ASSERT_EXPECTED_ERROR(_result, _expected_error) ASSERT_EQ(_result, std::unexpected(_expected_error))
#define ASSERT_EXPECTED_NO_ERROR(_result) ASSERT_TRUE(_result)
#define ASSERT_EXPECTED_VALUE_EQ(_result, _value) ASSERT_EQ(_result.value(), _value)
