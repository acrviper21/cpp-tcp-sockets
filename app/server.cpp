#include <iostream>
#include <boost/asio.hpp>

int getPortNumber();

int main()
{
    namespace ip = boost::asio::ip;
    int portNumber = getPortNumber();

    try
    {
        boost::asio::io_context io_context;
        ip::tcp::acceptor acceptor(io_context, ip::tcp::endpoint(ip::tcp::v4(), portNumber));

        while(true)
        {
            ip::tcp::socket socket(io_context);
            acceptor.accept(socket);

            std::cout << "Client Connected" << std::endl;

        }
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

    std::cout << "Which port number do you want to use: ";
    std::cin >> portNumber;

    return portNumber;
}