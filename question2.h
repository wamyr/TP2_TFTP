//
// Created by Sammy Gros on 20/12/2024.
//

#ifndef QUESTION2_H
#define QUESTION2_H

#include <netdb.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <_stdlib.h>

#define HTTP_PORT "80"
#define BUFFER_SIZE 128

int addr_info(const char* server, struct addrinfo **result_ptr);
void print_addr_info(struct addrinfo *result);
#endif //QUESTION2_H
