#include "Connection.h"

#include "log/log.h"

namespace codetorio {
Connection::Connection(const std::string &path, const std::string &id) :
    path(std::format("{}.{}", path, id)),
    logger(buildLogger(this->path)) {}

expected_void<ConnectionError> Connection::connect(const std::shared_ptr<IConnection> &connection) {
    if (nullptr != endPoint) {
        return validateConnection(connection);
    }
    if (connection.get() == this) {
        return std::unexpected(ConnectionError::TARGET_INVALID);
    }
    if (isConnectedToOther(connection)) {
        return std::unexpected{ConnectionError::TARGET_ALREADY_CONNECTED};
    }
    endPoint = connection;
    if (!isConnectedToThis(connection)) {
        return connection->connect(shared_from_this());
    }
    return {};
}

expected_void<DisconnectionError> Connection::disconnect() {
    if (nullptr == endPoint) {
        return std::unexpected(DisconnectionError::NOT_CONNECTED);
    }

    std::shared_ptr<IConnection> connection = endPoint;
    endPoint = nullptr;
    if (connection->getConnection().has_value()) {
        return connection->disconnect();
    }
    return {};
}

std::expected<std::shared_ptr<IConnection>, GetConnectionError> Connection::getConnection() {
    if (nullptr == endPoint) {
        return std::unexpected(GetConnectionError::NOT_CONNECTED);
    }
    return endPoint;
}

expected_void<ConnectionError> Connection::validateConnection(const std::shared_ptr<IConnection> &connection) {
    if (connection != endPoint) {
        return std::unexpected(ConnectionError::ALREADY_CONNECTED);
    }
    if (auto gcr = connection->getConnection()) {
        if (gcr.value().get() != this) {
            logger.error("{} was connected to {}, but not end point was connected to {}.",
                path, *connection, *(gcr.value()));
            return std::unexpected(ConnectionError::ALREADY_CONNECTED);
        }
    } else {
        logger.error("{} was connected to {}, but end point is not connected.", path, *connection);
        return std::unexpected(ConnectionError::ALREADY_CONNECTED);
    }
    return {};
}

bool Connection::isConnectedToThis(const std::shared_ptr<IConnection> &connection) const {
    const auto gcr = connection->getConnection();
    return gcr.has_value() && gcr.value().get() == this;
}

bool Connection::isConnectedToOther(const std::shared_ptr<IConnection> &connection) const {
    const auto gcr = connection->getConnection();
    return gcr.has_value() && gcr.value().get() != this;
}
} // codetorio