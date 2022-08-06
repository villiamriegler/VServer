#include "server.h"

int main (void){
    struct Server server = initServer(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 5);
    server.launch(&server);
}
