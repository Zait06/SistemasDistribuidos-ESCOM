#include "Respuesta.h"
#include <cstring>
#include <iostream>
using namespace std;

int nbd=0;

int main(){
    Respuesta resp(7200);
    cout <<"Cajero iniciado....\n"<<endl;
    while(1){
        struct mensaje* msj = resp.getRequest();
        int moneda[1];
        memcpy(&moneda, &msj->arguments, sizeof(msj->arguments));
        // cout<<"Datos recibidos: "<<moneda[0]<<endl;
        nbd+=moneda[0];
        // cout<<"\nEnviando respuesta: "<<nbd<<endl;
        resp.sendReply((char*) &nbd);
    }
    return 0;
}
