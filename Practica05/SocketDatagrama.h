#ifndef SOCKET_DATAGRAMA_H_
#define SOCKET_DATAGRAMA_H_
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

class SocketDatagrama{
    private:
        struct sockaddr_in direccionLocal;
        struct sockaddr_in direccionForanea;
        int s;                                  //  ID socket
        struct timeval timeout;
    public:
        SocketDatagrama(int);
        ~SocketDatagrama();                     
        int recibe(PaqueteDatagrama &p);       // Recibe un paquete tipo datagrama proveniente de este socket
        int envia(PaqueteDatagrama &p);        // Envía un paquete tipo datagrama desde este socket
        int recibeTimeout(PaqueteDatagrama &p, time_t segundos, suseconds_t microsegundos);
};
#endif