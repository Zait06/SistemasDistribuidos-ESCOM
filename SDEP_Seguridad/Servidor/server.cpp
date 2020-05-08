#include "Respuesta.h"
#include "SocketDatagrama.h"
#include <cstring>
#include <iostream>
#include <ctime>
#include <fstream>//archivo
#include <fcntl.h>//open
#include <vector>
#include <unistd.h>
#include <sys/time.h>
#include <algorithm>  
using namespace std;
//Para cada registro recibido, el servidor deberá irlos guardando en un archivo, el cual será nuestra base
//de datos.
int main(int argc, char* argv[]){
    if(argc != 2){
        cout<<"Forma de usa: nombre_programa nombre_archivo"<<endl;
        exit(0);
    }
    int destino;
    //Abre un archivo para escritura, si no existe lo crea, si existe lo trunca, con permisos rw-
        if((destino = open(argv[1], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1){
            perror(argv[2]);
            exit(-1);
        }
    Respuesta resp(7200);
    vector <int> celulares;
    cout << "Servidor iniciado....\n";
    while (true) {
        struct mensaje *msj = resp.getRequest();       
        if(msj != NULL) {
            char msjRecib[1024];
            struct celulares re;
            memcpy(&re,&msj->arguments,sizeof(struct celulares));
	    timeval actual;
            actual.tv_sec = 0;
            actual.tv_usec = 0;  

		//Ejercicio 2
	    if(!binary_search(celulares.begin(), 		celulares.end(),atoi(re.celular))){
	    celulares.push_back(atoi(re.celular));
            sort(celulares.begin(), celulares.end());
	    gettimeofday(&actual,NULL); //Ejericio1
            cout <<"Server.cpp:"<< actual.tv_sec <<" : "<< actual.tv_usec<< endl;
            string regs = re.toString();
            regs +="@"+to_string(actual.tv_sec)+"@"+ to_string(actual.tv_usec);
            //write(destino,msjRecib, 34);
	    write(destino,regs.c_str(), regs.length());
            write(destino,"\n", 1);

	    resp.sendReply((char *)&actual);  
        }else{//si es duplicado
         timeval actual;
            actual.tv_sec = 0;
            actual.tv_usec = 0; 
		cout << "Telefono ya registrado" << endl;
                resp.sendReply((char *)&actual);
        }
      }       
    }
    close(destino);
}
