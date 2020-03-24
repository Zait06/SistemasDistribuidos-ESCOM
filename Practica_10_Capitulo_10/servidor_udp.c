#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>

int puerto = 7200;

int main(void)
{
    int num[2];
    int s, res, clilen;
    struct sockaddr_in server_addr, msg_to_client_addr;
    int tam, puerto_cliente;
    unsigned char ip_servidor[4], ip_cliente[4];

    s = socket(AF_INET, SOCK_DGRAM, 0);
   
    /* se asigna una direccion al socket del servidor*/
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(puerto);
    bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
    clilen = sizeof(msg_to_client_addr);
    memcpy(ip_servidor, &server_addr.sin_addr.s_addr+0,4);
    memcpy(ip_cliente, &msg_to_client_addr.sin_addr.s_addr+0,4);

    printf("\nPuerto local: %d", server_addr.sin_port);
    while(1) 
    {
        tam = recvfrom(s, (char *) num, 2*sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);
        res = num[0] + num[1];
        
        if(tam == -1)
        {
            perror("\nError al recibir");
            exit(0);
        }
        else
        {
            printf("\n\nIP del cliente: ");
	        for(int i=0; i<4; i++)
                printf("%d. ", ip_cliente[i]);
            printf("\nPuerto del cliente: %d", ntohs(msg_to_client_addr.sin_port));
        }
    /* envía la petición al cliente. La estructura msg_to_client_addr contiene la dirección socket del cliente */
    sendto(s, (char *)&res, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
   }
}