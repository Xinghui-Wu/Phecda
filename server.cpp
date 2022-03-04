#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define IP_ADDRESS "127.0.0.1"
#define PORT 6666


int main()
{
    // Create a TCP socket.
    int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(IP_ADDRESS);
    server_address.sin_port = htons(PORT);

    bind(server_socket, (sockaddr*) &server_address, sizeof(server_address));

    listen(server_socket, 20);

    sockaddr_in client_address;
    socklen_t client_address_size = sizeof(client_address);
    int client_socket = accept(server_socket, (sockaddr*) &client_address, &client_address_size);

    char str[] = "Hello World!";
    write(client_socket, str, sizeof(str));

    close(client_socket);
    close(server_socket);

    return 0;
}
