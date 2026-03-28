#include <iostream>
#include <string>
#include <vector>
#include <boost/asio.hpp>

int getPortNumber();

int main()
{
    namespace ip = boost::asio::ip;
    
    int portNumber = getPortNumber();

    try
    {
        boost::asio::io_context io_context;

        ip::tcp::resolver resolver(io_context);
        ip::tcp::resolver::results_type results = resolver.resolve("localhost", std::to_string(portNumber));

        ip::tcp::socket socket(io_context);
        boost::asio::connect(socket, results);

        std::string client_message = "Hello from client!";
        boost::system::error_code error_code;
        boost::asio::write(socket, boost::asio::buffer(client_message), error_code);

        std::vector<char> server_message(1024);
        size_t reply_length = boost::asio::read(socket, boost::asio::buffer(server_message), error_code);

        std::cout.write(server_message.data(), reply_length) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}

int getPortNumber()
{
    int portNumber;
    std::cout << "Which port number will you like to connect to?: ";
    std::cin >> portNumber;

    return portNumber;
}