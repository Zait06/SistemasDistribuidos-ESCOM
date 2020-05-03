#include "Respuesta.h"
#include <cstring>
#include <iostream>

#include <fstream>//archivo
#include <fcntl.h>//open

#include <unistd.h>


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
    int nbd=0;
    Respuesta resp(7200);
    cout << "Servidor iniciado....\n";
    while (true) {
        struct mensaje *msj = resp.getRequest();       
        if(msj != NULL) {
            char msjRecib[1024];
            memcpy(msjRecib,&msj->arguments,34);
	        resp.sendReply((char *)&nbd);     
            write(destino,msjRecib, 34);
            write(destino,"\n", 1);
        }else{//si es duplicado
            resp.sendReply((char *)&nbd);
        }       
    }
    close(destino);
}