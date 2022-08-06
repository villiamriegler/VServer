#pragma once

#include <sys/socket.h>
#include <netinet/in.h>

struct Server {
    int domain;
    int type;
    int protocol;
    int port;
    int bindingAdress;
    int backlog;

    int socket;
    struct sockaddr_in adress;

    void (*launch)(struct Server* server);
};

struct Server initServer( int domain, int type, int protocol, int port, int bindingAdress, int backlog);
