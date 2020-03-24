#include "Respuesta.h"
#include <cstring>
#include <iostream>
using namespace std;

int main(){
    Respuesta resp(7200);
    while(1){
    	cout <<"Servidor iniciado....\n"<<endl;
        struct mensaje* msj = resp.getRequest();
        int n[2];
        memcpy(&n, &msj->arguments, sizeof(msj->arguments));
        cout<<"Datos recibidos: "<<n[0]<<" y "<<n[1]<<endl;
        int res = n[0] + n[1];
        cout<<"\nEnviando respuesta: \n"<<res<<endl;
        resp.sendReply((char*) &res);
    }
    return 0;
}
