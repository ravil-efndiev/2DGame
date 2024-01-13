cmake_minimum_required(VERSION 3.1)

project(game)

add_executable(game src/Main.cpp src/MainState.cpp)

set_property(TARGET game PROPERTY CXX_STANDARD 20)

target_link_libraries(game ${CMAKE_CURRENT_SOURCE_DIR}/RVL/libRVL.a ${CMAKE_CURRENT_SOURCE_DIR}/RVL/RVL/vendor/assimp/bin/libassimp.5.2.5.dylib ${CMAKE_CURRENT_SOURCE_DIR}/RVL/RVL/vendor/lib/libglfw3.a)

set(CMAKE_BUILD_TYPE Release)

target_include_directories(game PRIVATE .)
target_include_directories(game PRIVATE RVL/RVL/src/RVL)
target_include_directories(game PRIVATE RVL/RVL/src/RVL/API/)
target_include_directories(game PRIVATE RVL/RVL/src/RVL/API/ECS)
target_include_directories(game PRIVATE RVL/RVL/vendor/)
target_include_directories(game PRIVATE RVL/RVL/vendor/include/)
target_include_directories(game PRIVATE RVL/RVL/vendor/assimp/include/)
target_include_directories(game PRIVATE RVL/RVL/vendor/yaml/include/)
target_include_directories(game PRIVATE RVL/RVL/vendor/include/glm)
target_include_directories(game PRIVATE RVL/RVL/vendor/imgui/)
target_include_directories(game PRIVATE RVL/RVL/src)
target_include_directories(game PRIVATE RVL/RVL/)

include(GNUInstallDirs)

set(CMAKE_CXX_FLAGS "-Wall -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -framework CoreFoundation -Wno-unused -Wno-deprecated")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O4")
