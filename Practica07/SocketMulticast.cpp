#include "SocketMulticast.h"

SocketMulticast::SocketMulticast(int puerto){
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
    if((s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP))<0){
        perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
    }
    direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	
    if(puerto == 0)
		direccionLocal.sin_port = htons(puerto);
	else
		direccionLocal.sin_port = puerto;
	
    if (bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal))<0 ) { 
		perror("bind failed"); 
		exit(EXIT_FAILURE);
}

SocketMulticast::~SocketMulticast(){
    close(s);
}

void SocketMulticast::unirseGrupo(char *multicastIP){
    multicast.imr_multiaddr.s_addr = inet_addr(multicastIP);
    multicast.imr_interface.s_addr = htonl(INADDR_ANY);
    int aceptado=setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *) &multicast, sizeof(multicast));
    if(aceptado<0){
        perror("No se pudo unir al grupo");
    }
}

void SocketMulticast::salirseGrupo(char *multicastIP){
    multicast.imr_multiaddr.s_addr = inet_addr(multicastIP);
    setsockopt(s, IPPROTO_IP, IP_DROP_MEMBERSHIP, (void *) &multicast, sizeof(multicast));   
}