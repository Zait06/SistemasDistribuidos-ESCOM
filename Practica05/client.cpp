#include "Solicitud.h"
#include <string.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    /*Los dos enteros se le deben pasar al cliente como parámetros en la línea de comandos.*/
    if(argc != 4) {
		printf("Forma de uso: %s ip_servidor num1 num2\n", argv[0]);
		exit(0);
	}

    int num[2];
	num[0] = atoi(argv[2]);
	num[1] = atoi(argv[3]);
	Solicitud s;
	int res=0;
	// memcpy(&res, s.doOperation(argv[1], 7200, 1, (char *)&num), 4);
	memcpy(&res, s.doOperation(argv[1], 7200, 1, (char *)&num,5,0), 4);
    cout<<"Cliente Iniciado"<<endl;
    //cout<<"El resultado de "<<num[0]<<" + "<<num[1]<<" es: "<<res<<endl;
	printf("El resultado de %d + %d es: %d\n",num[0],num[1],res);
    return 0;
}
