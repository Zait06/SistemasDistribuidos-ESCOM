#include "Solicitud.h"

Solicitud::Solicitud() {
    //El objeto SocketDatagrama se deberá instanciar en el constructor como sigue:
    socketlocal = new SocketDatagrama(0);
    //puesto que el usuario de esta clase es un cliente y su puerto será variable.
}

char * Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments) {
    /*Los datos privados adicionales y la implementación del método doOperation son a completa
    satisfacción del programador.*/
    
}