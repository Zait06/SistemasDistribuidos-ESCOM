#include "SocketMulticast.h"
#include "SocketDatagrama.h"

int main(int argc, char *argv[]) {
	if(argc != 5) {
        printf("Forma de uso: %s ip_multicast puerto valorTTL \"cadena\"\n", argv[0]);
		exit(0);
    }

    char *cadena=argv[4], *ipMulti=argv[1];
    int puerto=atoi(argv[2]);
    unsigned char valorTTL=(unsigned char) argv[3];

    SocketMulticast sm = SocketMulticast(puerto);
    PaqueteDatagrama p = PaqueteDatagrama(cadena, 8, ipMulti, puerto);
    int cont = 0;

    while((sm.envia(p, valorTTL)) > 0) {
        cout << "\nMensaje  enviado" << endl;
        cout << "IP: " << p.obtieneDireccion() << endl;
        cout << "Puerto: " << p.obtienePuerto() << endl;
        cout << "Longitud: " << p.obtieneLongitud() << endl;
        // SocketDatagrama  s = SocketDatagrama(7200);
        // PaqueteDatagrama respuesta = PaqueteDatagrama(4);
        // s.recibeTimeout(respuesta, 2, 500);
        // int resul = 0;
        // memcpy(&resul , respuesta.obtieneDatos(), 4);
        // cout << "Mensaje recibido" << endl;
        // cout << "IP: " << respuesta.obtieneDireccion() << endl;
        // cout << "Resultado: " << resul <<endl;  
        cont++; 
    }
    return 0;