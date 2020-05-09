#include "Solicitud.h"
#include <iostream>
#include <cstring>
using namespace std;
unsigned int contRequest = 0;

Solicitud::Solicitud() {
	socketlocal = new SocketDatagrama(0);
}

char *Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments) {
	struct mensaje sms;
	sms.messageType = 0;
	sms.requestId = contRequest;
	printf("\nContRequest: %u\n", contRequest);
	sms.operationId = operationId;
	memcpy(sms.arguments, arguments, 256);
	PaqueteDatagrama p = PaqueteDatagrama((char *)&sms, sizeof(sms), IP, puerto);
	//cout << "Direccion: " << p.obtieneDireccion() << endl;
	//cout << "Puerto: " << p.obtienePuerto() << endl;
	struct mensaje* smsprueba = (struct mensaje*)p.obtieneDatos();
    //cout << "Registro: " <<smsprueba->arguments << endl;
	//cout << "Registro: " <<sms.arguments << endl;
	//cout << "Registro: " <<arguments << endl;
	socketlocal->envia(p);
	PaqueteDatagrama p1 = PaqueteDatagrama(65000);
	int tam = socketlocal->recibeTimeout(p1, 2, 500);
	int n = 1;

	while (tam == -1 && n < 7) {
		socketlocal->envia(p);
		tam = socketlocal->recibeTimeout(p1, 2, 500);
		n++;
	}
	
	if (n == 7) {
		cout << "Servidor no esta disponible, intente mas tarde." << endl;
		exit(0);
	}
	else
	{
		socketlocal->~SocketDatagrama();
		//cout << "\nMensaje recibido" << endl;
		//cout << "Direccion: " << p1.obtieneDireccion() << endl;
		//cout << "Puerto: " << p1.obtienePuerto() << endl;
		struct mensaje *msj = (struct mensaje *)p1.obtieneDatos();
		/*Prueba
		timeval res;
   		 memcpy(&res, (char *)msj->arguments, sizeof(timeval));
		//cout <<"Solicitud:"<<res.tv_sec<<" : "<< res.tv_usec << endl;
		//Prueba*/

		contRequest++;
		return (char *)msj->arguments;
	}
}
