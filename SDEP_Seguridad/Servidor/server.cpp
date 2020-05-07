#include "Respuesta.h"
#include "SocketDatagrama.h"
#include <cstring>
#include <iostream>
#include <ctime>
#include <fstream>//archivo
#include <fcntl.h>//open

#include <unistd.h>
#include <sys/time.h>

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
    cout << "Servidor iniciado....\n";
    while (true) {
        struct mensaje *msj = resp.getRequest();       
        if(msj != NULL) {
            char msjRecib[1024];
            memcpy(msjRecib,&msj->arguments,34);
	    
	    timeval actual;
            actual.tv_sec = 0;
            actual.tv_usec = 0;  
	    
	    gettimeofday(&actual,NULL);
                cout <<"Server.cpp:"<< actual.tv_sec <<" : "<< actual.tv_usec<< endl;
            string regs;
            regs += to_string(actual.tv_sec)+"@"+ to_string(actual.tv_usec);
            write(destino,msjRecib, 34);
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
    close(destino);
}
