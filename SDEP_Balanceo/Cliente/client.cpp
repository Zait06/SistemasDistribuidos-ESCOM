#include "Solicitud.h"
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <sys/time.h>
#include <fstream>//archivo

using namespace std;
int randNum();
int main(int argc, char *argv[]){
    //El cliente debe recibir el parámetro n en la línea de comandos...
    if(argc != 4){
        cout<<"Forma de usa: nombre_programa ip nombre_archivo num__registros"<<endl;
        exit(0);
    }
    ifstream archivo(argv[2], ios::binary);
    char cadena[256];
    char *serverA;  int portA;
    char *serverB;  int portB;
    char *serverC;  int portC;
    string s;
    int regactual=0;
    int res = 0;
    //leerá n registros de un archivo...
	int n = atoi(argv[3]);
	while (regactual < n){
        //irá leyendo cada registro del archivo...
        getline(archivo,s);
        memcpy(cadena,s.c_str(),s.size());
        //cout<<cadena<<endl;//comprobación
        
        // y los manda en mensajes UDP(un registro en cada mensaje UDP) hacia el servidor.;
        Solicitud s;
	    timeval res;

        // memcpy(&res, s.doOperation(argv[1], 7200, 1, (char *)&cadena), sizeof(timeval));

        if(cadena[9]>=0 || cadena[9]<=3){
            memcpy(&res, s.doOperation(serverA, portA, 1, (char *)&cadena), sizeof(timeval));
        }

        if(cadena[9]>=4 || cadena[9]<=6){
            memcpy(&res, s.doOperation(serverB, portB, 1, (char *)&cadena), sizeof(timeval));
        }

        if(cadena[9]>=7 || cadena[9]<=9){
            memcpy(&res, s.doOperation(serverC, portC, 1, (char *)&cadena), sizeof(timeval));
        }
		
		//cout <<"Client.cpp:"<<res.tv_sec<<" : "<< res.tv_usec << endl;
		regactual++;
	}
	return 0;
}