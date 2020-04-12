#include "Solicitud.h"
#include <iostream>
#include <cstring>
using namespace std;
unsigned int contRequest = 0;

Solicitud::Solicitud(){
	socketlocal = new SocketDatagrama(0);
}

char *Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments) {
	struct mensaje sms;
	sms.messageType = 0;
	sms.requestId = contRequest;
	sms.operationId = operationId;
	memcpy(sms.arguments, arguments, sizeof(arguments));
	PaqueteDatagrama p = PaqueteDatagrama((char *)&sms, sizeof(sms), IP, puerto);
	printf("IdRequest: %u\n", contRequest);
	//cout << "Direccion: " << p.obtieneDireccion() << endl;
	//cout << "Puerto: " << p.obtienePuerto() << endl;
	PaqueteDatagrama p1 = PaqueteDatagrama(4000);
		
	int resp, tam;
	int inten = 1;
	socketlocal->envia(p);
	tam = socketlocal->recibeTimeout(p1, 2, 500);
	
	while (tam == -1 && inten < 10) {
		tam = socketlocal->envia(p);
		if (tam == -1)
			cout<<"\nError al enviar, reintentando";
		tam = socketlocal->recibeTimeout(p1, 2, 500);
		inten++;
	}
	
	if (inten == 10){
		perror("Recvfrom fallo");
		printf( "El servidor no esta disponible, intente mas tarde.");
		exit(0);
	}
	else
	{
		socketlocal->~SocketDatagrama();
		struct mensaje *msj = (struct mensaje *)p1.obtieneDatos();
		contRequest++;
		return (char *)msj->arguments;
	}
}
