#include "Respuesta.h"
#include <cstring>
#include <iostream>
using namespace std;

int ndb=0;

int main(){
    Respuesta resp(7200);
    cout <<"Cajero iniciado....\n"<<endl;
    while(1){
        struct mensaje* msj = resp.getRequest();
        int moneda[1];
        memcpy(&moneda, &msj->arguments, sizeof(msj->arguments));
        cout<<"Datos recibidos: "<<moneda[0]<<endl;
        ndb+=moneda[0];
        cout<<"\nEnviando respuesta: "<<ndb<<endl;
        resp.sendReply((char*) &ndb);
    }
    return 0;
}
