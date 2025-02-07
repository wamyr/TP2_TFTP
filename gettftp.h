//
// Created by Sammy Gros on 23/12/2024.
//

#ifndef GETTFTP_H
#define GETTFTP_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <_stdlib.h>
#include <unistd.h>

#define NO_FLAGS 0
#define RRQ_REQUEST 1
#define REQUEST_MAX_SIZE 516
#define RESPONSE_MAX_SIZE 516
#define MODE_OCTET "octet"
#define NULL_CHAR '\0'
void construct_request(char* request_ptr, const char* host_file, int* request_size);
int send_to_network(int sockfd, const char* message_to_network_ptr, int message_size);
void reading_response(int sockfd, char* response_ptr );

#endif //GETTFTP_H
