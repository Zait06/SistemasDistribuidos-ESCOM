#ifndef SOCKETMULTICAST_H_
#define SOCKETMULTICAST_H_
#include "PaqueteDatagrama.h"
#include <sys/types.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <iostream>
using namespace std;

class SocketMulticast{
    private:
        int s;  // ID socket
    public:
        SocketMulticast(int);
        ~SocketMulticast();
        int recibe(PaqueteDatagrama &p);
        int envia(PaqueteDatagrama &p, unsigned char ttl);
        void unirseGrupo(char *);   // Se une a un grupo multicast, recibe la IP multicast
        void salirseGrupo(char *);  // Se sale de un grupo multicast, recibe la IP multicast
};

#endif