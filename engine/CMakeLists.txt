project(codetorio-engine)

add_library(${PROJECT_NAME}
        include/recipe/IRecipe.h
        include/vault/IVault.h
        include/connection/IConnection.h
        include/connection/IConnectableEntity.h
        src/vault/Vault.cpp
        src/vault/Vault.h
        include/recipe/ItemType.h
        include/tech/Tech.h
        include/tech/ITechTree.h
        include/types/types.h
        src/game/CodetorioGame.cpp
        src/game/CodetorioGame.h
        include/game/ICodetorioGame.h
        include/factory/IFactory.h
        include/explore/ILander.h
        src/log/log.h
        src/log/log.cpp
        src/connection/Connection.cpp
        src/connection/Connection.h
)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${PROJECT_NAME} PUBLIC magic_enum::magic_enum spdlog::spdlog)

target_include_directories(${PROJECT_NAME} PUBLIC include PRIVATE src)
