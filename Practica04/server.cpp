#include "SocketDatagrama.h"
#include "Respuesta.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    SocketDatagrama servidor(8080);
    PaqueteDatagrama paqueteRec(2);
    char num[2],res[2]; int cres;
    cout<<"SERVIDOR"<<endl;
    while(1){
        if(servidor.recibe(paqueteRec)){
            cout<<"Mensaje de: "<<paqueteRec.obtieneDireccion()<<endl;
            memcpy(num,paqueteRec.obtieneDatos(),2);
            cres=int(num[0]-'0')+int(num[1]-'0');
            paqueteRec.inicializaPuerto(paqueteRec.obtienePuerto());
            paqueteRec.inicializaIp(paqueteRec.obtieneDireccion());
            sprintf(res,"%d",cres);
            paqueteRec.inicializaDatos(res);
            cout<<paqueteRec.obtieneDatos()<<endl;
            servidor.envia(paqueteRec);
            cout<<"Respuesta enviada"<<endl;
        }
    }
    return 0;
}