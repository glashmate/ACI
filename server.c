

#include <stdio.h>
#include <string.h>

/* Bibliotecas obrigatorias para se poder utilizar sockets */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 22222
#define IP "127.0.0.1"
#define BUF_LEN 100

char* uppercase (char* msg);

int main(int argc, char const *argv[]) {

   /* Inicializacao do servidor */
   struct sockaddr_in server_addr, client_addr; /* armazena o endereco do socket */
   socklen_t addr_len = sizeof (server_addr); /* define o tamanho do endereco do servidor local */
   int sockfd, /* socket servidor */
      newsockfd, /* socket cliente */
      msgLenght; /* tamanho da mensagem */
   char buffer[BUF_LEN];

   /* Inicializar o socket
    * PF_INET - para indicar que queremos usar IP
    * SOCK_STREAM - para indicar que queremos usar TCP
    * 0 - para indicar que estamos num unico protocolo
    */
   sockfd = socket (PF_INET, SOCK_STREAM, 0); /* criacao do socket do servidor */
   if (sockfd < 0){
      printf ("Ocorreu um erro ao criar o socket.");
      return -1;
   }

   server_addr. sin_family = AF_INET;
   server_addr.sin_port = htons (PORT);
   inet_aton (IP, &server_addr.sin_addr); /* converte o endereco para um numero */

   /* Associamos o endereço ao socket */
   bind (sockfd, (struct sockaddr*)&server_addr, addr_len);

   /* Recebemos uma nova ligacao */
   listen (sockfd, 10); /* O servidor pode ter até 10 clientes em espera para estabelecer uma ligacao */
   newsockfd = accept(sockfd, (struct sockaddr*)&client_addr, &addr_len);

   while (1){ /* recebe continuamente dados, enquanto nao receber # */
     msgLenght = recv (newsockfd, buffer, BUF_LEN, 0);
     if (msgLenght < 0) {
        printf("Ocorreu um erro ao receber a mensagem.\n");
        return -1;
     }

     if (buffer[0] == '#')
        break;

     char* newBuffer = uppercase (buffer);

     msgLenght = send (newsockfd, newBuffer, strlen(newBuffer), 0);
     if (msgLenght < 0) {
        printf("Ocorreu um erro ao receber a mensagem.\n");
        return -1;
     }
   }

   shutdown (sockfd, 2);
   close (newsockfd);
   close (sockfd);

   return 0;
}

char* uppercase (char* msg) {
  int i;

  for (i = 0; i < strlen (msg); i++) {
    if (msg[i] >= 97 && msg [i] <= 122)
      msg[i] = msg[i] - (97-65);
  }

  return msg;
}
