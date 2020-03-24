#include "SocketDatagrama.h"
#include "Solicitud.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char* argv[]){
    /*Los dos enteros se le deben pasar al cliente como parámetros en la línea de comandos.*/
    if(argc != 3) {
		printf("Forma de uso: %s num_1 num_2\n", argv[0]);
		exit(0);
	}
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