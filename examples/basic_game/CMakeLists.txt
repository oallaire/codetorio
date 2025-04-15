project(basic-game)

add_executable(${PROJECT_NAME} basic_game.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC codetorio-engine)