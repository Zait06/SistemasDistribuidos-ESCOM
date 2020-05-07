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
    if(argc != 3){
        cout<<"Forma de usa: nombre_programa ip nombre_archivo"<<endl;
    }

    ifstream archivo(argv[2], ios::binary);
    SocketDatagrama sockClient(0);
    char cadena[256];
    string s;
    int res=0;

    getline(archivo,s);
    memcpy(cadena,s.c_str(),s.size());
    PaqueteDatagrama package00(cadena, sizeof(cadena), argv[1], 7200);
    int resp;
    sockClient.envia(package00);
    PaqueteDatagrama package01(3);
    resp=sockClient.recibe(package01);
    if(resp)
        resp=resp;
    else{
        cout<<"Algo salio mal"<<endl;
        archivo.close();
        exit(0);
    }
    
    sleep(1);
    cout<<"Registro terminado de leer"<<endl;
    archivo.close();

    return 0;
}