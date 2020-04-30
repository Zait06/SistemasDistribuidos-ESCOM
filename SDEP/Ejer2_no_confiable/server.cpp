#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <cstring>
#include <iostream>
#include <fstream>

#include <fcntl.h>

using namespace std;

int main(int argc, char* argv[]){

    PaqueteDatagrama p00 = PaqueteDatagrama(4000);//Respuesta.h
    int con=123;
    //Respuesta.h
    SocketDatagrama *socketlocal;//respuesta.h
    socketlocal = new SocketDatagrama(7200);//lo hace respuesta
     //Abre un archivo para escritura, si no existe lo crea, si existe lo trunca, con permisos rw-
        int destino;
        if((destino = open(argv[1], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1)
        {
            perror(argv[2]);
            exit(-1);
        }
    while(1){
        cout <<"Servidor iniciado....\n"<<endl;
        //getRequest
        int tam=socketlocal->recibe(p00);//respuesta
        if(tam==-1){
            perror("Recvfrom fallo");//respuesta
            break;
        }
        cout << "Mensaje recibido: " << flush;
        char msjRecib[1024];
        memcpy(msjRecib,p00.obtieneDatos(),32);

        write(destino,p00.obtieneDatos(), 32);
        write(destino, "\n", 1);
        //El servidor responderá con un mensaje de acuse cualesquiera
        PaqueteDatagrama p01((char*)&(con),3,p00.obtieneDireccion(),p00.obtienePuerto());
        socketlocal->envia(p01);
    }
    
    return 0;
}
