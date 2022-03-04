#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define IP_ADDRESS "127.0.0.1"
#define PORT 6666


int main()
{
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(IP_ADDRESS);
    server_address.sin_port = htons(PORT);

    connect(client_socket, (sockaddr*) &server_address, sizeof(server_address));

    char buffer[40];
    read(client_socket, buffer, sizeof(buffer) - 1);

    printf("Message from server: %s\n", buffer);

    close(client_socket);

    return 0;
}
