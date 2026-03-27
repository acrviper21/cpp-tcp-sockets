cmake_minimum_required(VERSION 3.20)

project(cpp-tcp-sockets VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost REQUIRED COMPONENTS system)
find_package(Threads REQUIRED)

set(NETWORK_SERVER server)
set(NETWORK_CLIENT client)

add_subdirectory(app)