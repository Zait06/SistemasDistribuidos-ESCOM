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

    ofstream archivo(argv[1], ios::binary | fstream::in | fstream::out | fstream::trunc);
    SocketDatagrama sockServer(0);
    PaqueteDatagrama p00 = PaqueteDatagrama(4000);
    int con=123;
    //Respuesta.h
    SocketDatagrama *socketlocal;
    socketlocal = new SocketDatagrama(7200);

    while(1){
        cout <<"Servidor iniciado....\n"<<endl;
        //getRequest
        int tam=socketlocal->recibe(p00);
        if(tam==-1){
            perror("Recvfrom fallo");
            break;
        }
        cout << "Mensaje recibido: " << flush;
        cout<<p00.obtieneDatos()<<endl;

        char msjRecib[1024];
        memcpy(msjRecib,p00.obtieneDatos(),32);
        if(strcmp(msjRecib,"ya")==0)
            break;
        archivo.write(msjRecib,32);
        archivo.write("\n",1);
        PaqueteDatagrama p01((char*)&(con),3,p00.obtieneDireccion(),p00.obtienePuerto());
        socketlocal->envia(p01);
        //Abre un archivo para escritura, si no existe lo crea, si existe lo trunca, con permisos rw-
        int destino;
        if((destino = open(argv[1], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1)
        {
            perror(argv[2]);
            exit(-1);
        }
         write(destino,msjRecib, 32);
    }

    archivo.close();

    return 0;
}
