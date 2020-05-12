#include "Respuesta.h"
#include <cstring>
#include <iostream>
using namespace std;

PaqueteDatagrama p = PaqueteDatagrama(65000);

Respuesta::Respuesta(int pl) {
    socketlocal = new SocketDatagrama(pl);
    contRequest = 0;
}

struct mensaje *Respuesta::getRequest(void)
{
    int tam = socketlocal->recibe(p);
    if (tam == -1){
        perror("Recvfrom failed");
    }

    //cout << "\nRegistro recibido: " << endl;
    //cout << "Direccion: " << p.obtieneDireccion() << endl;
    //cout << "Puerto: " << p.obtienePuerto() << endl;
    struct mensaje* sms = (struct mensaje*)p.obtieneDatos();

    unsigned int reqId = 0;
    memcpy(&reqId, &sms->requestId, sizeof(sms->requestId));
    //printf("Paquete: %u SMS->requestId: %d\n", contRequest, reqId);
    //cout << "Registro: " <<sms->arguments << endl;
    if(reqId < contRequest) {
        cout << "PAQUETE DUPLICADO" << endl;
        return NULL;
    }
    else {
        contRequest++;
        return (struct mensaje*)sms;
    }
}

void Respuesta::sendReply(char *respuesta)
{
    struct mensaje sms;
    sms.messageType = 1;
    sms.operationId = 0;
    sms.requestId = 0;
    memcpy(sms.arguments, respuesta, sizeof(timeval));
    /*prueba
    timeval res;
    memcpy(&res, (char *)sms.arguments, sizeof(timeval));
		cout <<"Respuesta.cpp:"<< res.tv_sec <<" : "<< res.tv_usec<< endl;
    //Prueba*/

    p.inicializaDatos((char *)&sms);
    //cout << "\nMensaje enviado" << endl;
    //cout << "Direccion: " << p.obtieneDireccion() << endl;
    //cout << "Puerto: " << p.obtienePuerto() << endl;
    socketlocal->envia(p);
    
    //socketlocal->~SocketDatagrama();
}
