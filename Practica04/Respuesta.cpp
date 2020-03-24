#include "Respuesta.h"
#include <cstring>
#include <iostream>
using namespace std;

PaqueteDatagrama p = PaqueteDatagrama(4000);

Respuesta::Respuesta(int pl) {
    /*En esta clase el constructor recibe como parámetro el puerto al que estará 
    escuchando solicitudes el servidor.*/
    socketlocal = new SocketDatagrama(pl);
}

struct mensaje* Respuesta::getRequest(void){
    /*Este método devuelve una estructura mensaje porque frecuentemente el código
    del servidor debe tener información al menos del operationId para saber qué 
    operación de las varias que dispone el servidor le están solicitando.*/
    int tam = socketlocal->recibe(p);
    if (tam == -1) {
      perror("Recvfrom fallo");
    }
    cout << "\nMensaje recibido:" << endl;
    cout << "Direccion: " << p.obtieneDireccion() << endl;
    cout << "Puerto: " << p.obtienePuerto() << endl;
    return (struct mensaje*) p.obtieneDatos();
}

void Respuesta::sendReply(char *respuesta){
    /*El método sendReply no incluye IP ni puerto pues se presupone que se envía al
    proceso remoto que hizo la solicitud.*/
    struct mensaje sms;
    sms.messageType = 1;
    sms.operationId = 0;
    sms.requestId = 0;
    memcpy(sms.arguments, respuesta, sizeof(respuesta));

    p.inicializaDatos((char*)&sms);
    cout << "\nMensaje recibido" << endl;
    cout << "Direccion: " << p.obtieneDireccion() << endl;
    cout << "Puerto: " << p.obtienePuerto() << endl;
    socketlocal->envia(p);
}