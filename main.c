#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <_stdlib.h>
#include <unistd.h>
#include "question1.h"
#include "question2.h"
#include "question3.h"
#include "gettftp.h"




int main(int argc, char ** argv) {

    if (command_failure(argc) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }

    char* server ;
    char* host_file ;
    request_information(argv, &server, &host_file);

    struct addrinfo * result;

    if (addr_info(server, &result) != EXIT_SUCCESS) {
        printf("Failed to resolve hostname\n");
        freeaddrinfo(result);
        return EXIT_FAILURE;
    }

    print_addr_info(result);

    int sockfd ;
    creating_socket(result, &sockfd);
    if (socket_connect(result, &sockfd) != EXIT_SUCCESS) {
        printf("Failed to connect to server\n");
        close(sockfd);
        freeaddrinfo(result);
        return EXIT_FAILURE;
    }

    char request[REQUEST_MAX_SIZE] , response[RESPONSE_MAX_SIZE];
    int request_size;
    construct_request(request, host_file, &request_size);
    // Afficher la requête sous forme hexadécimale pour la vérification
    for (size_t i = 0; i < request_size ; i++) {  // Longueur approximative de la requête
        printf("%02x ", (unsigned char)request[i]);
    }
    printf("\n");
    if (send_to_network(sockfd, request, request_size) == EXIT_FAILURE) {
        printf("Failed to send request\n");
        close(sockfd);
        freeaddrinfo(result);
        return EXIT_FAILURE;
    }
    printf("ça marche \n");
    reading_response(sockfd, response);

    close(sockfd);
    freeaddrinfo(result);

    return EXIT_SUCCESS;
}

/*