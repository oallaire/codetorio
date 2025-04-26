project(codetorio-unit-tests)

add_executable(${PROJECT_NAME}
        connection/ConnectionTest.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC GTest::gtest_main codetorio-engine)

target_include_directories(${PROJECT_NAME} PUBLIC ./ ../../engine/src)

include(GoogleTest)

gtest_discover_tests(${PROJECT_NAME})
