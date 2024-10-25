/*
============================================================================
Name : 34b.c
Author : Soumya Jain
Description : Write a program to create concurrent server.
a. use pthread_create.
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *handle_client(void *arg) {
    int client_socket = *(int*)arg;
    char buffer[BUFFER_SIZE] = {0};
    int bytes_read;

    while ((bytes_read = read(client_socket, buffer, BUFFER_SIZE)) > 0) {
        printf("Client: %s", buffer);
        send(client_socket, buffer, bytes_read, 0);
    }
    close(client_socket);
    free(arg);
    pthread_exit(NULL);
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        int *client_sock_ptr = malloc(sizeof(int));
        *client_sock_ptr = client_socket;

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, client_sock_ptr) != 0) {
            perror("Failed to create thread");
        }
        pthread_detach(thread_id); 
    }

    close(server_fd);
    return 0;
}

/*output:

soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./33b
Enter message to send to server: hello from client1
Message sent from client: hello from client1
Message from server: hello from client1

soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./33b
Enter message to send to server: hello from client 2
Message sent from client: hello from client 2
Message from server: hello from client 2


soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./34a
Client: hello from client1
Client: hello from client 2
*/

