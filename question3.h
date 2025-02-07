//
// Created by Sammy Gros on 20/12/2024.
//

#ifndef QUESTION3_H
#define QUESTION3_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <_stdlib.h>

void creating_socket(const struct addrinfo *result,int* sockfd_ptr);
int socket_connect(struct addrinfo *result,int* sockfd_ptr);
#endif //QUESTION3_H
