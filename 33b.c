/*
============================================================================
Name : 33b.c
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
    int client_fd;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    char message[1024];

    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/Address not supported");
        return -1;
    }

    if (connect(client_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        return -1;
    }

    printf("Enter message to send to server: ");
    fgets(message, 1024, stdin);  // Get input from the user

    send(client_fd, message, strlen(message), 0);  // Send user input to server
    printf("Message sent from client: %s", message);

    read(client_fd, buffer, 1024);
    printf("Message from server: %s\n", buffer);

    close(client_fd);

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

