#include "Respuesta.h"
#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <unistd.h>
using namespace std;

int main(int argc,char * argv[]) {
    if (argc != 2) {
        printf("Forma de uso: %s puerto\n", argv[0]);
        exit(0);
    }
    Respuesta resp(atoi(argv[1]));
    int cont = 0;
    cout << "Servidor timestamp iniciado....\n";
    while(true) {
        struct mensaje *msj = resp.getRequest();
        if(msj != NULL) {
            struct timeval actual;
            //Generamos el timestamp
            gettimeofday(&actual,NULL);
            cout << "Timestamp generado:"<< actual.tv_sec <<" : "<< actual.tv_usec<< endl;
            //Regresa el timestamp
            resp.sendReply((char *)&actual);
            cont++;
            cout <<"Mensaje "<< cont << " enviado"<< endl;
        }
    }
}