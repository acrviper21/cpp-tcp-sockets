set(SERVER_SRC server.cpp)

add_executable(${NETWORK_SERVER} ${SERVER_SRC})

target_link_libraries(${NETWORK_SERVER} PRIVATE
    Boost::system
    Threads::Threads)