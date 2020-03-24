#include "Solicitud.h"
#include <iostream>
#include <cstring>
using namespace std;

Solicitud::Solicitud() {
    //El objeto SocketDatagrama se deberá instanciar en el constructor como sigue:
    socketlocal = new SocketDatagrama(0);
    //puesto que el usuario de esta clase es un cliente y su puerto será variable.
}

char * Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments) {
    /*Los datos privados adicionales y la implementación del método doOperation son a completa
    satisfacción del programador.*/
    struct mensaje sms;
	sms.messageType = 0;
	sms.requestId = 0;
	sms.operationId = operationId;
    memcpy(sms.arguments, arguments, sizeof(arguments));
    
	PaqueteDatagrama p = PaqueteDatagrama((char*)&sms, sizeof(sms), IP, puerto);
	cout << "Direccion: " << p.obtieneDireccion() << endl;
	cout << "Puerto: " << p.obtienePuerto() << endl;
	socketlocal->envia(p);

	PaqueteDatagrama p1 = PaqueteDatagrama(4000);
    int tam = socketlocal->recibe(p1);
    if (tam == -1) {
      perror("Recvfrom fallo");
    }
    cout << "\nMensaje recibido" << endl;
    cout << "Direccion: " << p1.obtieneDireccion() << endl;
    cout << "Puerto: " << p1.obtienePuerto() << endl;
	struct mensaje* msj = (struct mensaje *)p1.obtieneDatos();
    return (char *) msj->arguments;
}