#include "SocketMulticast.h"
#include "SocketDatagrama.h"

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Forma de uso: %s ip_servidor puerto\n", argv[0]);
		exit(0);
    }

    int puerto=atoi(argv[2]);
    char *ip=argv[1];
    SocketMulticast sm = SocketMulticast(puerto);
    PaqueteDatagrama p = PaqueteDatagrama(100);
    
    sm.unirseGrupo(ip);
    // int cont = 0;

    while(sm.recibe(p)) {
        cout<<"\nMensaje recibido" << endl;
        cout<<"IP: " << p.obtieneDireccion() << endl;
        cout<<"Puerto: " << p.obtienePuerto() << endl;
        cout<<"Mensaje: "<<p.obtieneDatos()<<endl;;
        
        // PaqueteDatagrama respuesta = PaqueteDatagrama(4);
        // respuesta.inicializaIp(p.obtieneDireccion());
        // respuesta.inicializaDatos((char*)resul);
        // respuesta.inicializaPuerto(7200);
        // SocketDatagrama s = SocketDatagrama(0);
        // s.envia(respuesta);
        // cont++;
    }

    return 0;
}