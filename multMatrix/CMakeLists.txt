cmake_minimum_required (VERSION 2.8.11)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXE_LINKER_FLAGS "-static")

project(clientMatrix LANGUAGES CXX)
add_executable(clientMatrix ./cliente/clientMatrix.cpp ./cliente/clientMatrix.h ./cliente/main_multMatrix.cpp ./cliente/operacionesMatrix.h ./cliente/utils.h ./cliente/utils.cpp)
target_link_libraries(clientMatrix pthread)

project(serverMatrix LANGUAGES CXX)
add_executable(serverMatrix  ./servidor/serverMatrix.cpp ./servidor/conexion_cliente.h ./servidor/operacionesMatrix.h ./servidor/multmatrix.h ./servidor/multmatrix.cpp ./servidor/utils.cpp ./servidor/utils.h)
target_link_libraries(serverMatrix pthread)