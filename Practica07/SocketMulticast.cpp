#include "SocketMulticast.h"

SocketMulticast::SocketMulticast(int puerto){

    if((s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP))<0){
        perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
    }
}