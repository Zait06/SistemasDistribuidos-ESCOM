#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>

int puerto = 7200;

int main(int argc, char const *argv[])
{
   struct sockaddr_in msg_to_server_addr, client_addr;
   int s, num[2], res;
    int tam, puerto_cliente;
    unsigned char ip_cliente[4], ip_servidor[4];
    
    puerto_cliente = atoi(argv[2]);
    s = socket(AF_INET, SOCK_DGRAM, 0);
    /* rellena la dirección del servidor */
    bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
    msg_to_server_addr.sin_family = AF_INET;
    msg_to_server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    msg_to_server_addr.sin_port = htons(puerto);
   
    /* rellena la direcciòn del cliente*/
    bzero((char *)&client_addr, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = INADDR_ANY;
    client_addr.sin_port = htons(puerto_cliente);

    memcpy(ip_servidor, &msg_to_server_addr.sin_addr.s_addr+0,4);
    memcpy(ip_cliente, &client_addr.sin_addr.s_addr+0,4);

    bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));
    num[0] = 2;
    num[1] = 5; /*rellena el mensaje */
    sendto(s, (char *)num, 2 * sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
   
    printf("IP local: ");
	for(int i=0; i<4; i++)
        printf("%d. ", ip_cliente[i]);
    printf("\nPuerto local: %d\n", ntohs(client_addr.sin_port));

    tam = recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
    if(tam == -1)
    {
        perror("\nError al recibir.\n");
        exit(0);
    }
    else
    {
        printf("\nIP del servidor: ");
	    for(int i=0; i<4; i++)
            printf("%d. ", ip_servidor[i]);
        printf("\nPuerto del servidor: %d\n", htons(msg_to_server_addr.sin_port));
    }
    /* se bloquea esperando respuesta */
    
    printf("2 + 5 = %d\n", res);
    close(s);
}