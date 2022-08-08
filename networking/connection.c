#include "connection.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



void handleConnection(int *socket){ 
    //unsigned int requestLength = 0;
    char buffer[30000] = {0};
    int vals;    
    //requestLength = 

    //buffer = malloc(120 * sizeof(char));
    //memset(buffer,0,120);

    vals = read(*socket, buffer, 30000);

    // handle the request
    printf("%s\n", buffer);


    // IMPORTANT** CLOSE socket
    close(*socket);
    //free(buffer);
}
