#include <gtest/gtest.h>

#include "connection/Connection.h"
#include "testing/assert.h"

using namespace codetorio;

TEST(ConnectionTest, NewConnectionIsNotConnected) {
    auto c1 = std::make_shared<Connection>("", "1");
    ASSERT_EXPECTED_ERROR(c1->getConnection(), GetConnectionError::NOT_CONNECTED);
}

TEST(ConnectionTest, ConnectToSelf) {
    auto c1 = std::make_shared<Connection>("", "1");
    ASSERT_EXPECTED_ERROR(c1->connect(c1), ConnectionError::TARGET_INVALID);
}

TEST(ConnectionTest, ConnectUnconnectedConnections) {
    auto c1 = std::make_shared<Connection>("", "1");
    auto c2 = std::make_shared<Connection>("", "2");

    ASSERT_EXPECTED_NO_ERROR(c1->connect(c2));
    ASSERT_EXPECTED_VALUE_EQ(c1->getConnection(), c2);
    ASSERT_EXPECTED_VALUE_EQ(c2->getConnection(), c1);
}

TEST(ConnectionTest, ConnectToConnectedConnection) {
    auto c1 = std::make_shared<Connection>("", "1");
    auto c2 = std::make_shared<Connection>("", "2");
    auto c3 = std::make_shared<Connection>("", "3");

    ASSERT_EXPECTED_NO_ERROR(c1->connect(c2));
    ASSERT_EXPECTED_ERROR(c1->connect(c3), ConnectionError::ALREADY_CONNECTED);
    ASSERT_EXPECTED_VALUE_EQ(c1->getConnection(), c2);
    ASSERT_EXPECTED_VALUE_EQ(c2->getConnection(), c1);
    ASSERT_EXPECTED_ERROR(c3->getConnection(), GetConnectionError::NOT_CONNECTED);

    ASSERT_EXPECTED_ERROR(c3->connect(c1), ConnectionError::TARGET_ALREADY_CONNECTED);
    ASSERT_EXPECTED_VALUE_EQ(c1->getConnection(), c2);
    ASSERT_EXPECTED_VALUE_EQ(c2->getConnection(), c1);
    ASSERT_EXPECTED_ERROR(c3->getConnection(), GetConnectionError::NOT_CONNECTED);
}

TEST(ConnectionTest, DisconnectWhenNotConnected) {
    auto c1 = std::make_shared<Connection>("", "1");

    ASSERT_EXPECTED_ERROR(c1->disconnect(), DisconnectionError::NOT_CONNECTED);
}

TEST(ConnectionTest, DisconnectFromCallerWhenConnected) {
    auto c1 = std::make_shared<Connection>("", "1");
    auto c2 = std::make_shared<Connection>("", "2");

    ASSERT_EXPECTED_NO_ERROR(c1->connect(c2));

    ASSERT_EXPECTED_NO_ERROR(c1->disconnect());
    ASSERT_EXPECTED_ERROR(c1->getConnection(), GetConnectionError::NOT_CONNECTED);
    ASSERT_EXPECTED_ERROR(c2->getConnection(), GetConnectionError::NOT_CONNECTED);
}

TEST(ConnectionTest, DisconnectFromCalleeWhenConnected) {
    auto c1 = std::make_shared<Connection>("", "1");
    auto c2 = std::make_shared<Connection>("", "2");

    ASSERT_EXPECTED_NO_ERROR(c1->connect(c2));

    ASSERT_EXPECTED_NO_ERROR(c2->disconnect());
    ASSERT_EXPECTED_ERROR(c1->getConnection(), GetConnectionError::NOT_CONNECTED);
    ASSERT_EXPECTED_ERROR(c2->getConnection(), GetConnectionError::NOT_CONNECTED);
}
