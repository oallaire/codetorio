#pragma once

#include <expected>
#include <spdlog/spdlog.h>

#include "types/types.h"

namespace codetorio {

enum class ConnectionError {
    ALREADY_CONNECTED,
    TARGET_ALREADY_CONNECTED,
    TARGET_INVALID
};

enum class DisconnectionError {
    NOT_CONNECTED
};

enum class GetConnectionError {
    NOT_CONNECTED
};

class IConnection {
public:
    virtual ~IConnection() = default;

    virtual expected_void<ConnectionError> connect(const std::shared_ptr<IConnection> &connection) = 0;
    virtual expected_void<DisconnectionError> disconnect() = 0;
    virtual std::expected<std::shared_ptr<IConnection>, GetConnectionError> getConnection() = 0;
};

} // codetorio

template<>
struct fmt::formatter<codetorio::IConnection> : fmt::formatter<std::string>
{
    auto format(const codetorio::IConnection &my, format_context &ctx) const -> decltype(ctx.out())
    {
        // TODO - Better logging for connections
        return fmt::format_to(ctx.out(), "connection");
    }
};
