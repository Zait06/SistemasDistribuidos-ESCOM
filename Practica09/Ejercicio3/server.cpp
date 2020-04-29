#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <cstring>
#include <iostream>
#include <fstream>

#include <fcntl.h>

using namespace std;

int main(int argc, char* argv[]){
    
    if(argc != 2){
        cout<<"Forma de usa: nombre_programa nombre_archivo"<<endl;
        exit(0);
    }

    SocketDatagrama sockServer(0);
    PaqueteDatagrama p00 = PaqueteDatagrama(4000);
    int con=123;
    //Respuesta.h
    SocketDatagrama *socketlocal;
    socketlocal = new SocketDatagrama(7200);

    int destino;
    if((destino = open(argv[1], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1){
        perror(argv[1]);
        exit(-1);
    }

    cout <<"Servidor iniciado....\n"<<endl;
    while(1){
        //getRequest
        int tam=socketlocal->recibe(p00);
        if(tam==-1){
            perror("Recvfrom fallo");
            break;
        }

        char msjRecib[1024];
        memcpy(msjRecib,p00.obtieneDatos(),32);
        if(strcmp(msjRecib,"ya")==0)
            break;
        PaqueteDatagrama p01((char*)&(con),3,p00.obtieneDireccion(),p00.obtienePuerto());
        socketlocal->envia(p01);
        //Abre un archivo para escritura, si no existe lo crea, si existe lo trunca, con permisos rw-
        
        write(destino,msjRecib, 32);
        write(destino,"\n",1);
    }

    close(destino);

    return 0;
}
