#include <stdio.h>
#include <string.h>

/* Bibliotecas obrigatorias para se poder utilizar sockets */
#include <sys/types.h>
#include <sys/sockets.h>
#include <netinet.h>
#include "socketaddr.h"

#define PORT 22222
#define IP "127.0.0.1"
#define MSG_LEN 100

int main(int argc, char const *argv[]) {

   /* Inicializacao do servidor */
   sockaddr_in server; /* armazena o endereco do servidor */
   socklen_t addressLength = sizeof (server); /* define o tamanho do endereco do servidor local */
   int sockfd, /* socket cliente */
      msgLenght; /* tamanho da mensagem */
   char msg[MSG_LEN];

   sockfd = socket (PF_INET, SOCK_STREAM, IPPROTO_TCP /*0*/); /* criacao do socket do servidor */
   server. sin_family = AF_INET;
   server.sin_port = htons (PORT);

   inet_aton (IP, &server.sin_addr);

   connect (sock, (struct sockaddr*)&server, addressLength);

   fgets (buf, 100, stdin);
   msgLenght = send (sockfd /* confirmar esta variavel */, msg, strlen(msg)+1, 0);

}
