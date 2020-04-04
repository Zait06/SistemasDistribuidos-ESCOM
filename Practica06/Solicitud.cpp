#include "Solicitud.h"
#include <iostream>
#include <cstring>
using namespace std;

Solicitud::Solicitud() {
    //El objeto SocketDatagrama se deberá instanciar en el constructor como sigue:
    socketlocal = new SocketDatagrama(0);
    //puesto que el usuario de esta clase es un cliente y su puerto será variable.
}

char * Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments, time_t seg, suseconds_t microseg){
    /*Los datos privados adicionales y la implementación del método doOperation son a completa
    satisfacción del programador.*/
    struct mensaje sms;
	sms.messageType = 0;
	sms.requestId = 0;
	sms.operationId = operationId;
    memcpy(sms.arguments, arguments, sizeof(arguments));
    
	PaqueteDatagrama p = PaqueteDatagrama((char*)&sms, sizeof(sms), IP, puerto);
	// cout << "Direccion: " << p.obtieneDireccion() << endl;
	// cout << "Puerto: " << p.obtienePuerto() << endl;
    //int resp = socketlocal->envia(p);
    //cout<<"\nRespuesta: "<<resp;
    int resp;
	
        resp = socketlocal->envia(p);
        //cout<<"\nRespuesta: "<<resp;
        /*if(resp == -1) 
        {
            char rep[]= {'-1'} ;
            cout<<"\nError al enviar, reintentando";
            cout<<"\nRespuesta: 7"<<resp;
            memcpy(sms.arguments, &rep, sizeof(arguments));
            cout<<"contenido: "<<sms.arguments;
            cout<<"\nRespuesta: 8"<<resp;
            /*struct mensaje* msj_p = struct mensaje *;
            msj_p->arguments = '1';
            //return (char *) -1;
            return sms.arguments;
        }*/
        
	PaqueteDatagrama p1 = PaqueteDatagrama(4000);
    // int tam = socketlocal->recibe(p1);
    int inten=1;
    int tam;
    do{
        tam = socketlocal->recibeTimeout(p1,seg,microseg);  // Metodo recibe con temporizador
        cout<<"Respuesta: \n"<<tam;
        if (tam == -1) {
            perror("Recvfrom fallo");
        }
        if(inten == 7) 
        {
            printf("Demasiados intentos de espera de respuesta, reintentando");
            inten = 1;
        }
        inten++;
    }while(tam == -1);
       
    // cout << "\nMensaje recibido" << endl;
    // cout << "Direccion: " << p1.obtieneDireccion() << endl;
    // cout << "Puerto: " << p1.obtienePuerto() << endl;
	struct mensaje* msj = (struct mensaje *)p1.obtieneDatos();
    return (char *) msj->arguments;
}