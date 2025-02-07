//
// Created by Sammy Gros on 20/12/2024.
//

#include "question1.h"

#include <stdio.h>
#include <_stdlib.h>

int command_failure(int argc) {
    if (argc != 3) {
        printf("Invalid number of arguments\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void request_information(char** argv, char** server_ptr, char** host_file_ptr) {
    *server_ptr = argv[1];
    *host_file_ptr = argv[2];
}