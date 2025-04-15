#pragma once

#include <expected>
#include <memory>

#include "IConnection.h"

namespace codetorio {

enum class ConnectionResult {
    SUCCESS,
    FULL
};

enum class DisconnectionResult {
    SUCCESS
};

enum class GetConnectionResult {
    SUCCESS,
    EMPTY
};

class IConnectableEntity {
public:
    virtual ~IConnectableEntity() = default;

    virtual std::unexpected<ConnectionResult> connect(const std::shared_ptr<IConnection> &connection) = 0;
    virtual std::unexpected<DisconnectionResult> disconnect() = 0;
    virtual std::unexpected<DisconnectionResult> disconnect(const std::shared_ptr<IConnection> &connection) = 0;

    virtual std::expected<std::shared_ptr<IConnection>, GetConnectionResult> getInputConnection();
    virtual std::expected<std::shared_ptr<IConnection>, GetConnectionResult> getOutputConnection();
};

} // codetorio
