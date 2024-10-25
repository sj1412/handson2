/*
============================================================================
Name : 33a.c
Author : Soumya Jain
Description : Write a program to communicate between two machines using socket.
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *message = "Hello from server";

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    if (new_socket < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    read(new_socket, buffer, 1024);
    printf("Message from client: %s\n", buffer);
    send(new_socket, message, strlen(message), 0);
    printf("Hello message sent\n");

    close(new_socket);
    close(server_fd);

    return 0;
}

/* output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ gcc 33b.c -o 33b
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./33a
Message from client: hello server

Hello message sent

soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./33b
Enter message to send to server: hello server
Message sent from client: hello server
*/
