#include "Solicitud.h"
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <sys/time.h>
#include <thread>  
#include <fstream>//archivo

void enviarMensaje(char *ipserv, char portserv, char *cadena, Solicitud s){
    timeval res;
    memcpy(&res, s.doOperation(ipserv, portserv, 1, (char *)&cadena), sizeof(timeval));
}

using namespace std;
int randNum();
int main(int argc, char *argv[]){
    //El cliente debe recibir el parámetro n en la línea de comandos...
    if(argc != 9){
        cout<<"Forma de usa: nombre_programa nombre_archivo num_registros ipA portA ipB portB ipC portC"<<endl;
        exit(0);
    }
    
    ifstream archivo(argv[1], ios::binary);
    char cadena[256];

    string s;
    int regactual=0;
    int res = 0;
    //leerá n registros de un archivo...
	int n = atoi(argv[2]);
	while (regactual < n){
        //irá leyendo cada registro del archivo...
        getline(archivo,s);
        memcpy(cadena,s.c_str(),s.size());
        //cout<<cadena<<endl;//comprobación               
               
        // y los manda en mensajes UDP(un registro en cada mensaje UDP) hacia el servidor.;¿¿
        Solicitud s;
        
        int n = atoi(&cadena[9]);
        cout<<"n: "<<n<<"  ";
        if(n == 0 || n == 3 || n == 1 || n == 2){
            cout<<"numero : "<<cadena<<" numero 10: "<<cadena[9]<<"  -1"<<endl;
            thread t(enviarMensaje, argv[5], atoi(argv[6]), cadena, s);
			t.detach();
        }
        /*if(n == 4 || n == 6 || n == 5){
            cout<<"numero : "<<cadena<<" numero 10: "<<cadena[9]<<"  -2"<<endl;
            thread t(enviarMensaje, argv[5], atoi(argv[6]), cadena, s);
			t.detach();
        }
        if(n == 7 || n == 9 || n == 8){
            cout<<"numero : "<<cadena<<" numero 10: "<<cadena[9]<<"  -3"<<endl;
            thread t(enviarMensaje, argv[7], atoi(argv[8]), cadena, s);
			t.detach();
        }*/
        //cout <<"Client.cpp:"<<res.tv_sec<<" : "<< res.tv_usec << endl;
		regactual++;
        sleep(1);
	}
	return 0;
}