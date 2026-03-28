set(SERVER_SRC server.cpp)
set(CLIENT_SRC client.cpp)

add_executable(${NETWORK_SERVER} ${SERVER_SRC})
add_executable(${NETWORK_CLIENT} ${CLIENT_SRC})

target_link_libraries(${NETWORK_SERVER} PRIVATE
    Boost::system
    Threads::Threads)

target_link_libraries(${NETWORK_CLIENT} PRIVATE
    Boost::system
    Threads::Threads)   