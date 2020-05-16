#include "Solicitud.h"
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <sys/time.h>
#include <thread>  
#include <fstream>//archivo
using namespace std;

void enviarMensaje(char *ipserv, int portserv, char cadena[256], Solicitud s){
    timeval res;
    memcpy(&res, s.doOperation(ipserv, portserv, 1, (char*)cadena), sizeof(timeval));
}

using namespace std;
int randNum();
int main(int argc, char *argv[]){
    //El cliente debe recibir el parámetro n en la línea de comandos...
    if(argc != 9){
        cout<<"Forma de usa: nombre_programa nombre_archivo num_registros ipA portA ipB portB ipC portC"<<endl;
        exit(0);
    }

    char *ipA=argv[3];  int portA=atoi(argv[4]);
    char *ipB=argv[5];  int portB=atoi(argv[6]);
    char *ipC=argv[7];  int portC=atoi(argv[8]);
    
    ifstream archivo(argv[1], ios::binary);
    char cadena[256];

    string linea;
    int regactual=0;
    int res = 0;
    //leerá n registros de un archivo...
	int n = atoi(argv[2]);
	while (regactual < n){
        //irá leyendo cada registro del archivo...
        getline(archivo,linea);
        memcpy(cadena,linea.c_str(),linea.size());
        //cout<<cadena<<endl;//comprobación               
               
        // y los manda en mensajes UDP(un registro en cada mensaje UDP) hacia el servidor.;¿¿
        Solicitud sol;
        
        int ultDig = atoi(&cadena[9]);

        if(ultDig >= 0 && ultDig <= 3){
            cout<<"Mandar al servidor A "<<cadena<<endl;
            // timeval res;
            // memcpy(&res,sol.doOperation(ipA,portA,1,(char *)&cadena),sizeof(timeval));
            // enviarMensaje(ipA,portA,cadena,sol);
            thread t(enviarMensaje,ipA,portA,cadena,sol);
			t.detach();
        }

        if(ultDig >= 4 && ultDig <= 6){
            cout<<"Mandar al servidor B "<<cadena<<endl;
            thread t(enviarMensaje,ipB,portB,cadena,sol);
			t.detach();
        }

        if(ultDig >= 7 && ultDig <= 9){
            cout<<"Mandar al servidor C "<<cadena<<endl;
            thread t(enviarMensaje,ipC,portC,cadena,sol);
			t.detach();
        }
        
		regactual++;
        sleep(1);
	}
	return 0;
}