cmake_minimum_required (VERSION 2.8.11)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXE_LINKER_FLAGS "-static")

project(server LANGUAGES CXX)
add_executable(server ./servidor/main_servidor.cpp ./servidor/serverFileManager.h ./servidor/serverFileManager.cpp ./servidor/filemanager.cpp ./servidor/filemanager.h ./servidor/operaciones.h ./servidor/utils.cpp ./servidor/utils.h)
target_link_libraries(server pthread)

project(client LANGUAGES CXX)
add_executable(client ./cliente/main_filemanager.cpp ./cliente/clientFileManager.cpp ./cliente/clientFileManager.h ./cliente/filemanager.cpp ./cliente/filemanager.h ./cliente/operaciones.h ./cliente/utils.cpp ./cliente/utils.h)
target_link_libraries(client pthread)

