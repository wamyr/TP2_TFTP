//
// Created by Sammy Gros on 20/12/2024.
//

#include "question3.h"

void creating_socket(const struct addrinfo *result, int *sockfd_ptr) {
    *sockfd_ptr = socket(result->ai_family,result->ai_socktype,result->ai_protocol);
}

int socket_connect(struct addrinfo *result,int* sockfd_ptr) {
    return connect(*sockfd_ptr,result->ai_addr,result->ai_addrlen);
}