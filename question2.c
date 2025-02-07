//
// Created by Sammy Gros on 20/12/2024.
//

#include "question2.h"


int addr_info(const char* server, struct addrinfo **result_ptr) {
    struct addrinfo hints;
    memset(&hints,0,sizeof(struct addrinfo));
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_family = AF_INET;//IPV4
    return getaddrinfo(server,HTTP_PORT,&hints,result_ptr);
}

void print_addr_info(struct addrinfo *result) {
    struct addrinfo * current = result;

    while(current != NULL){
        printf("Found one answer : \n");
        printf("**\t family = %d\n",current->ai_family);
        printf("**\t socktype = %d\n", current->ai_socktype);
        printf("**\t protocol = %d\n", current->ai_protocol);

        char host_name[BUFFER_SIZE]={0};
        char serv_name[BUFFER_SIZE]={0};

        getnameinfo(current->ai_addr,current->ai_addrlen,host_name,BUFFER_SIZE,serv_name,BUFFER_SIZE,NI_NUMERICHOST | NI_NUMERICSERV);
        printf("**\t host_name = %s\n",host_name);
        printf("**\t serv_name = %s\n",serv_name);
        current=current->ai_next;

    }
}