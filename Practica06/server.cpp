#include "Respuesta.h"
#include <cstring>
#include <iostream>
using namespace std;

int ndb=0;

int main(){
    Respuesta resp(7200);
    cout <<"Cajero iniciado iniciado....\n"<<endl;
    while(1){
        struct mensaje* msj = resp.getRequest();
        int moneda;
        memcpy(&moneda, &msj->arguments, sizeof(msj->arguments));
        cout<<"Valor recibido: "<<moneda<<endl;
        ndb+=moneda;
        cout<<"\nValor de lo acumulado: "<<ndb<<endl;
        int aux=ndb;
        resp.sendReply((char*) &aux);
    }
    return 0;
}
