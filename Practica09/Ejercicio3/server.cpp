#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]){
    
    if(argc != 2){
        cout<<"Forma de usa: nombre_programa nombre_archivo"<<endl;
    }

    ofstream archivo(argv[1], ios::binary | fstream::in | fstream::out | fstream::trunc);
    SocketDatagrama sockServer(0);
    PaqueteDatagrama p00 = PaqueteDatagrama(4000);
    int con=123;

    cout <<"Servidor iniciado...."<<endl;

    while(1){
        char msjRecib[1024];
        int tam;
        tam=sockServer.recibe(p00);
        if(tam==-1){
            perror("Recvfrom fallo");
            break;
        }
        cout << "Mensaje recibido: " << flush;
        cout<<p00.obtieneDatos()<<endl;
        memcpy(msjRecib,p00.obtieneDatos(),32);
        if(strcmp(msjRecib,"ya")==0)
            break;
        archivo.write(msjRecib,32);
        archivo.write("\n",1);
        PaqueteDatagrama p01((char*)&(con),3,p00.obtieneDireccion(),p00.obtienePuerto());
        sockServer.envia(p01);
    }

    archivo.close();

    return 0;
}
