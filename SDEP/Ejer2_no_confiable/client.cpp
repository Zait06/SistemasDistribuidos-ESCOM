#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <fstream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    //El cliente debe recibir el parámetro n en la línea de comandos...
    if(argc != 4){
        cout<<"Forma de usa: nombre_programa ip nombre_archivo num__registros"<<endl;
        exit(0);
    }

    ifstream archivo(argv[2], ios::binary);
    SocketDatagrama sockClient(0);
    char cadena[256];
    string s;
    int res=0;
    int regactual=0;
    //lee n registros de un archivo...
    int n=atoi(argv[3]);
    while(regactual<n){
        getline(archivo,s);
        memcpy(cadena,s.c_str(),s.size());
        // y los manda en mensajes UDP(un registro en cada mensaje UDP) hacia el servidor.
        PaqueteDatagrama package00(cadena, sizeof(cadena), argv[1], 7200);//Dentro de solicitud
        cout<<cadena<<endl;
        int resp;
        sockClient.envia(package00);//Dentro de solicitud
        cout<<"Enviado..."<<endl;
        PaqueteDatagrama package01(3);
        resp=sockClient.recibe(package01);//Dentro de solicitud
        if(resp){
            cout<<"Entrega confirmada."<<endl;
            regactual+=1;
            continue;
        }else{
            cout<<"Algo salio mal"<<endl;
            archivo.close();
            exit(0);
        }
        
        sleep(1);
    }
    cout<<"Los "<<n<< " registros han sido leidos y enviados."<<endl;
    archivo.close();

    return 0;
}