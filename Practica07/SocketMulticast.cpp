#include "SocketMulticast.h"

SocketMulticast::SocketMulticast(int puerto){

    if((s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP))<0){
        perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
    }
}

void SocketMulticast::unirseGrupo(char *multicastIP){
    struct ip_mreq multicast;
    multicast.imr_multiaddr.s_addr = inet_addr(multicastIP);
    multicast.imr_interface.s_addr = htonl(INADDR_ANY);
    setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *) &multicast, sizeof(multicast));
}

void SocketMulticast::salirseGrupo(char *multicastIP){
    struct ip_mreq multicast;
    multicast.imr_multiaddr.s_addr = inet_addr(multicastIP);
    multicast.imr_interface.s_addr = htonl(INADDR_ANY);
    setsockopt(s, IPPROTO_IP, IP_DROP_MEMBERSHIP, (void *) &multicast, sizeof(multicast));   
}