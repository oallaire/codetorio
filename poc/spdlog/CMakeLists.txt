project(spdlog-poc)

add_executable(${PROJECT_NAME} spdlog_poc.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${PROJECT_NAME} PUBLIC spdlog::spdlog)
