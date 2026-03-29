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
        ip::tcp::acceptor acceptor(io_context, ip::tcp::endpoint(ip::tcp::v4(), portNumber));

        while(true)
        {
            ip::tcp::socket socket(io_context);
            acceptor.accept(socket);

            std::string server_response = "Message received";
            int client_message_size;

            boost::system::error_code error_code;
            std::vector<char> receive_buffer(1024);

            boost::asio::read(socket, boost::asio::buffer(&client_message_size, sizeof(client_message_size)));
            receive_buffer.resize(client_message_size);
            size_t reply_length = boost::asio::read(socket, boost::asio::buffer(receive_buffer), error_code);

            std::cout.write(receive_buffer.data(), reply_length) << std::endl;

            int send_message_size = server_response.size();
            boost::asio::write(socket, boost::asio::buffer(&send_message_size, sizeof(send_message_size)), error_code);
            boost::asio::write(socket, boost::asio::buffer(server_response), error_code);

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