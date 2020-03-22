#include "SocketDatagrama.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    char num[]{'2','5'};
    char ip[]="127.0.0.1";
    SocketDatagrama cliente(8080);
    PaqueteDatagrama paquete(num,sizeof(num),ip,8080), p2(sizeof(char));;
    
    cout<<"Cliente"<<endl;
    
    cliente.envia(paquete);
    cliente.recibe(paquete);
    cout<<"El resultado de 2+5 es: "<<paquete.obtieneDatos()<<endl;


    return 0;
}