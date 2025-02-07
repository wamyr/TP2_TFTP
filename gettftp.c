//
// Created by Sammy Gros on 23/12/2024.
//

#include "gettftp.h"

void construct_request(char* request_ptr, const char* host_file, int* request_size) {
    char* request_start = request_ptr;
    unsigned short opcode = htons(RRQ_REQUEST);  // Opcode 1 pour la requête RRQ
    // Ajouter l'opcode
    memcpy(request_ptr, &opcode, 2);  // 2 octets pour l'opcode
    request_ptr += 2;
    // Ajouter le nom du fichier, suivi d'un caractère nul
    strcpy(request_ptr, host_file);
    request_ptr += strlen(host_file) + 1;  // +1 pour le caractère nul
    // Ajouter le mode, suivi d'un caractère nul
    strcpy(request_ptr, MODE_OCTET);
    request_ptr += strlen(MODE_OCTET) + 1 ;  // +1 pour le caractère nul caractère nul est automatiuement ajouté
    *request_size = (int) (request_ptr - request_start) ;
}

int send_to_network(int sockfd, const char* message_to_network_ptr, int message_size ) {
    return (int) send(sockfd, message_to_network_ptr, message_size, NO_FLAGS);
}

void reading_response(int sockfd, char* response_ptr ) {

    unsigned short opcode, block_num;
    // Réception du paquet DATA
    int bytes_received = (int) recv(sockfd, response_ptr, RESPONSE_MAX_SIZE, 0);
    if (bytes_received < 4) {
        perror("Erreur lors de la réception du paquet DATA");
        return;
    }
    // Analyse du paquet DATA
    memcpy(&opcode, response_ptr, 2);  // Extraire l'opcode
    opcode = ntohs(opcode);  // Convertir en format hôte
    if (opcode != 3) {
        fprintf(stderr, "Paquet inattendu : opcode %d\n", opcode);
        return;
    }

    memcpy(&block_num, response_ptr + 2, 2);  // Extraire le numéro de bloc
    block_num = ntohs(block_num);  // Convertir en format hôte

    // Extraire les données
    char *data = response_ptr + 4;  // Les données commencent après les 4 premiers octets
    int data_size = bytes_received - 4;  // Taille des données

    printf("Reçu bloc %d avec %d octets de données.\n", block_num, data_size);

    // Écrire les données dans un fichier ou les traiter (ici, affichage pour l'exemple)
    /*FILE *file = fopen("output.txt", "wb");
    if (file) {
        fwrite(data, 1, data_size, file);
        fclose(file);
        printf("Données sauvegardées dans 'output.txt'.\n");
    }*/

    // Construire et envoyer le paquet ACK
    char ack_packet[4];
    opcode = htons(4);  // Opcode 4 pour ACK
    memcpy(ack_packet, &opcode, 2);  // Ajouter l'opcode
    block_num = htons(block_num);  // Convertir le numéro de bloc en réseau
    memcpy(ack_packet + 2, &block_num, 2);  // Ajouter le numéro de bloc

    // Envoyer le paquet ACK
    if (send(sockfd, ack_packet, 4, 0) == -1) {
        perror("Erreur lors de l'envoi du paquet ACK");
    } else {
        printf("Paquet ACK envoyé pour le bloc %d.\n", block_num);
    }
}

