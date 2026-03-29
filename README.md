# cpp-tcp-sockets
A synchronous TCP Client-Server implementation built with **C++17** and **Boost.Asio**, featuring custom length prefixed message framing and managed by **CMake**.
---
## Key Features
- **Synchronous TCP Communication:** Implements a reliable, point to point connection for data exchange.
- **Length Prefixed Protocol:** Uses a 4 byte integer header to communicate message size to prevent data truncation or hanging.
- **Dynamic Buffer Management:** Automatically resizes the receive buffers based on incoming metadata to ensure memory efficiency.
- **Multi Target Build:** A single CMake configuration that builds independent, ready to run Client and Server binaries
---
## Tech Stack
- **Language:** C++17
- **Networking Library:** Boost.Asio
- **Build System:** CMake (3.20+)
- **Operating System:** Linux / macOS / Windows
---
## Prerequisites
To build this project, you will need:
- **C++ Compiler** (supporting c++17)
- **CMake (3.20+)**
- **Boost Libraries** (system and asio)
---
## Build Instructions

**1. Clone the repository**
```bash
git clone https://github.com/acrviper21/cpp-tcp-sockets.git
cd cpp-tcp-sockets
```
**2. Create a build directory**
```bash
mkdir build && cd build
```
**3. Configure and build**
```bash
cmake .. && cmake --build .
cd app
```
---
## Usage
>**Note:** Always start the **Server** before the **Client** to ensure the connection can be established.
```bash
./server
```
When prompted, enter a port number like (12345). The server will then begin listening for connections.

**Run the client in a separate terminal:**
```bash
./client
```
Enter the same port number. The client will establish a connection to `localhost` and initiate the message exchange.
---
## Expected Output
When running both applications on the same machine, your terminal should look like this:

### Server Terminal:
```
Which port number do you want to use: 12345
Hello from client!
```

### Client Terminal:
```
Which port number will you like to connect to?: 12345
Message received
```
---
## License
This project is licensed under the **MIT License** - see the [License](/LICENSE)