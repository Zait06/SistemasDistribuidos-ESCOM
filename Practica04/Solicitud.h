#ifndef SOLICITUD_H_
#define SOLICITUD_H_

#include "SocketDatagrama.h"

class Solicitud{
    private:
        SocketDatagrama *socketlocal;
    public:
        Solicitud();
        char * doOperation(char *IP, int puerto, int operationId, char *arguments);

};


#endif