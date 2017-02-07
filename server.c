#include <stdio.h>

/* Bibliotecas obrigatorias para se poder utilizar sockets */
#include <sys/types.h>
#include <sys/sockets.h>
#include <netinet.h>
#include "socketaddr.h"

#define PORT 22222
#define IP "127.0.0.1"
#define BUF_LEN 100

int main(int argc, char const *argv[]) {

   /* Inicializacao do servidor */
   sockaddr_in local, remote; /* armazena o endereco do socket */
   socklen_t addressLength = sizeof (local); /* define o tamanho do endereco do servidor local */
   int sock, /* socket servidor */
      sockfd, /* socket cliente */
      msgLenght; /* tamanho da mensagem */
   char buffer[BUF_LEN];

   sock = socket (PF_INET, SOCK_STREAM, IPPROTO_TCP /*0*/); /* criacao do socket do servidor */
   local. sin_family = AF_INET;
   local.sin_port = htons (PORT);

   inet_aton (IP, &local.sin_addr);

   bind (sock, (struct sockaddr*)&local, addressLength);

   listen (sock, 10);
   sockfd = accept(sock, (struct sockaddr*)&remote, &addressLength);

   msgLenght = recv (sockfd, buffer, BUF_LEN, 0);

}
