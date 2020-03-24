#include "Respuesta.h"

Respuesta::Respuesta(int pl) {
    /*En esta clase el constructor recibe como parámetro el puerto al que estará 
    escuchando solicitudes el servidor.*/
    socketlocal = new SocketDatagrama(pl);
}

struct mensaje Respuesta::*getRequest(void){
    /*Este método devuelve una estructura mensaje porque frecuentemente el código
    del servidor debe tener información al menos del operationId para saber qué 
    operación de las varias que dispone el servidor le están solicitando.*/

}

void Respuesta::sendReply(char *respuesta){
    /*El método sendReply no incluye IP ni puerto pues se presupone que se envía al
    proceso remoto que hizo la solicitud.*/

}