#include "SocketMulticast.h"
#include "SocketDatagrama.h"

int main(int argc, char *argv[])
{
	if(argc != 4){
        printf("Forma de uso: %s ip_multicast numero 1 numero 2\n", argv[0]);
		exit(0);
    }

    //char *cadena=argv[4], 
    char *ipMulti=argv[1];
    //int puerto=atoi(argv[2]);
    //unsigned char valorTTL=(unsigned char) argv[3];
    int num[2];
    num[0] = atoi(argv[2]);
    num[1] = atoi(argv[3]);
    SocketMulticast sm = SocketMulticast(6666);
    PaqueteDatagrama p = PaqueteDatagrama((char *)&num, 8, ipMulti, 3030);
    int cont = 0;

    while((sm.envia(p, 1)) > 0) {
        cout<<"\nMensaje  enviado"<<endl;
        cout<<"IP: " << p.obtieneDireccion()<<endl;
        //cout<<"Puerto: " << p.obtienePuerto()<<endl;
        SocketDatagrama s = SocketDatagrama(7200);
        PaqueteDatagrama respuesta = PaqueteDatagrama(4);
        s.recibeTimeout(respuesta, 2, 500);
        int result = 0;
        memcpy(&result, respuesta.obtieneDatos(), 4);
        cout<<"Mensaje recibido"<<endl;
        cout<<"IP de computadora: "<<endl;
        cout<<"Resultado: "<<result;
        cont++; 
    }
    return 0;
}