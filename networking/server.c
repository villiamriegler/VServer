#include "server.h"
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "connection.h"

void defaultlaunch(struct Server *server){
    int newSocket;
    int adressLen = sizeof(server->adress);

    while (1){
        printf("******Server Waiting For Request******\n");
        if ((newSocket = accept(server->socket, (struct sockaddr *)&server->adress, (socklen_t *)&adressLen)) < 0){
            perror("Server could not accept connection");
            exit(EXIT_FAILURE);
        }
        
        handleConnection(&newSocket);
    }
}

struct Server initServer(int domain, int type, int protocol, int port, int bindingAdress, int backlog){
    struct Server server;
    
    server.domain = domain;
    server.type = type;
    server.protocol = protocol;
    server.port = port;
    server.bindingAdress = bindingAdress;
    server.backlog = backlog;

    server.launch = &defaultlaunch;

    if ((server.socket = socket(server.domain, server.type, server.protocol)) < 0){
        perror("Server could not create socket");
        exit(EXIT_FAILURE);
    }

    server.adress.sin_family = server.domain;
    server.adress.sin_port = htons(server.port);
    server.adress.sin_addr.s_addr = htonl(server.bindingAdress);

    if (bind(server.socket, (struct sockaddr *)&server.adress, sizeof(server.adress)) < 0){
        perror("Server could not bind socket");
        exit(EXIT_FAILURE);
    }
    
    if (listen(server.socket, server.backlog) < 0){
        perror("Server filed to listen at adress");
        exit(EXIT_FAILURE);
    }

    return server;
}
