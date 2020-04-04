#ifndef SOLICITUD_H_
#define SOLICITUD_H_
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "mensaje.h"

class Solicitud{
    private:
        SocketDatagrama *socketlocal;
    public:
        Solicitud();
        char * doOperation(char *IP, int puerto, int operationId, char *arguments, time_t seg, suseconds_t microseg);

};
#endif