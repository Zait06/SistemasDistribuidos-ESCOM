#include "SocketMulticast.h"
#include "SocketDatagrama.h"

int main(int argc, char *argv[]) {
    if(argc != 2){
        printf("Forma de uso: %s ip_servidor \n", argv[0]);
		exit(0);
    }

    //int puerto=atoi(argv[2]);
    char *ip=argv[1];
    //int puerto = atoi(argv[2]);
    SocketMulticast sm = SocketMulticast(3030);
    PaqueteDatagrama p = PaqueteDatagrama(8);
    
    sm.unirseGrupo(ip);
    // int cont = 0;

    while(sm.recibe(p)) {
        cout<<"\nMensaje recibido" << endl;
        cout<<"IP: " << p.obtieneDireccion() << endl;
        //cout<<"Puerto: " << p.obtienePuerto() << endl;
        //cout<<"Mensaje: "<<p.obtieneDatos()<<endl;;
        int num[2];
        memcpy(&num, p.obtieneDatos(), 2*sizeof(int));
        cout<<"Enteros recibidos: "<<num[0]<<" y "<<num[1];
        int suma[1];
        suma[0] = num[0] + num[1];
        cout<<"Suma: "<<suma[0];
        PaqueteDatagrama resp = PaqueteDatagrama(4);
        resp.inicializaIp(p.obtieneDireccion());
        resp.inicializaDatos((char*)suma);
        resp.inicializaPuerto(7200);
        SocketDatagrama s = SocketDatagrama(0);
        s.envia(resp);
        // cont++;
    }

    return 0;
}