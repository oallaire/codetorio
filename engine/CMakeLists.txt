project(codetorio-engine)

add_library(${PROJECT_NAME} src/engine/Engine.cpp include/engine/Engine.h
        include/engine/IEngine.h
        include/thread/ITask.h
        include/thread/IThreadable.h
        src/vault/Vault.cpp
        include/vault/Vault.h
        include/item/IItem.h
        src/factory/Level1Factory.cpp
        include/factory/Level1Factory.h
        include/item/IItemRecipe.h
        include/factory/IFactory.h
        src/factory/Level0Factory.cpp
        include/factory/Level0Factory.h
)

target_include_directories(${PROJECT_NAME} PUBLIC include PRIVATE src)
