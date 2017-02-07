#include <stdio.h>
#include <string.h>

/* Bibliotecas obrigatorias para se poder utilizar sockets */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 22222
#define IP "127.0.0.1"
#define MSG_LEN 100

int main(int argc, char const *argv[]) {

   /* Inicializacao do cliente */
   struct sockaddr_in client_addr; /* armazena o endereco do cliente */
   socklen_t addr_len = sizeof (client_addr); /* define o tamanho do endereco do servidor local */
   int sockfd, /* socket cliente */
      msgLenght; /* tamanho da mensagem */
   char msg[MSG_LEN];

   /* Inicializar o socket
    * PF_INET - para indicar que queremos usar IP
    * SOCK_STREAM - para indicar que queremos usar TCP
    * 0 - para indicar que estamos num unico protocolo
    */
   sockfd = socket (PF_INET, SOCK_STREAM, 0); /* criacao do socket do servidor */
   if (sockfd < 0) {
      printf ("Ocorreu um erro ao criar o socket.");
      return -1;
   }

   client_addr. sin_family = AF_INET;
   client_addr.sin_port = htons (PORT);
   inet_aton (IP, &client_addr.sin_addr);

   /* Estabelece-se a ligação */
   connect (sockfd, (struct sockaddr*)&client_addr, addr_len); /* o cliente bloqueia até conseguir a ligacao */

   /* Enviar e receber dados */
   fgets (msg, 100, stdin);
   msg [strlen(msg)-1] = '\0'; /* elimina o caracter enter do fgets */

   msgLenght = send (sockfd /* confirmar esta variavel */, msg, strlen(msg)+1, 0);
   if (msgLenght < 0) {
      printf("Ocorreu um erro ao receber a mensagem.\n");
      return -1;
   }

   msgLenght = recv (sockfd, msg, MSG_LEN, 0);
   if (msgLenght < 0) {
      printf("Ocorreu um erro ao receber a mensagem.\n");
      return -1;
   }

   puts (msg);

   return 0;

}
