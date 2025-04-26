#pragma once

#include <expected>
#include <memory>
#include <spdlog/logger.h>

#include "connection/IConnection.h"

namespace codetorio {

class Connection : public IConnection, public std::enable_shared_from_this<Connection> {
public:
    Connection(const std::string &path, const std::string &id);

    expected_void<ConnectionError> connect(const std::shared_ptr<IConnection> &connection) override;
    expected_void<DisconnectionError> disconnect() override;
    std::expected<std::shared_ptr<IConnection>, GetConnectionError> getConnection() override;

private:
    std::string path;
    spdlog::logger logger;
    std::shared_ptr<IConnection> endPoint;

    expected_void<ConnectionError> validateConnection(const std::shared_ptr<IConnection> &connection);
    bool isConnectedToThis(const std::shared_ptr<IConnection> &connection) const;
    bool isConnectedToOther(const std::shared_ptr<IConnection> &connection) const;
};

} // codetorio
