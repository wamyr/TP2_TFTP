cmake_minimum_required(VERSION 3.30)
project(TP2_TFTP C)

set(CMAKE_C_STANDARD 11)

add_executable(TP2_TFTP main.c
        question1.c
        question1.h
        question2.c
        question2.h
        question3.c
        question3.h
        gettftp.c
        gettftp.h)
