#include "Solicitud.h"
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <sys/time.h>
#include <thread>  
#include <fstream>//archivo

void enviarMensaje(char *ipserv, int portserv, char *cadena, Solicitud s)
{
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
    cout<<argv[3]<<" "<<argv[4]<<endl;
	while (regactual < n){
        //irá leyendo cada registro del archivo...
        getline(archivo,s);
        memcpy(cadena,s.c_str(),s.size());
        //cout<<cadena<<endl;//comprobación
        
        // y los manda en mensajes UDP(un registro en cada mensaje UDP) hacia el servidor.;
        Solicitud s;
        //timeval res;
        //memcpy(&res, s.doOperation(argv[3], atoi(argv[4]), 1, (char *)&cadena), sizeof(timeval));
        // timeval res;
        //memcpy(&res, s.doOperation(argv[1], 7200, 1, (char *)&cadena), sizeof(timeval));

        if(cadena[9] >= '0' || cadena[9]<= '3'){
            cout<<cadena[9]<<endl;
            //timeval res;
            //memcpy(&res, s.doOperation(argv[3], atoi(argv[4]), 1, (char *)&cadena), sizeof(timeval));
            thread t(enviarMensaje, argv[3], atoi(argv[4]), cadena, s);
			t.detach();
        }

        if(cadena[9] >= '4' || cadena[9] <= '6'){
            cout<<cadena[9]<<endl;
            //timeval res;
            //memcpy(&res, s.doOperation(argv[5], atoi(argv[6]), 1, (char *)&cadena), sizeof(timeval));
            thread t(enviarMensaje, argv[5], atoi(argv[6]), cadena, s);
			t.detach();
        }

        if(cadena[9] >= '7' || cadena[9] <= '9'){
            cout<<cadena[9]<<endl;
            //timeval res;
            //memcpy(&res, s.doOperation(argv[7], atoi(argv[8]), 1, (char *)&cadena), sizeof(timeval));
            thread t(enviarMensaje, argv[7], atoi(argv[8]), cadena, s);
			t.detach();
        }
		
		//cout <<"Client.cpp:"<<res.tv_sec<<" : "<< res.tv_usec << endl;
		regactual++;
        //sleep(1);
	}
	return 0;
}