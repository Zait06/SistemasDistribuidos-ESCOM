#include "Solicitud.h"
#include <string.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    /*Los dos enteros se le deben pasar al cliente como parámetros en la línea de comandos.*/
    if(argc != 5) {
		printf("Forma de uso: %s ip_servidor num1 num2 N_repeticiones\n", argv[0]);
		exit(0);
	}

    int num[2],rep=0;
	num[0] = atoi(argv[2]);
	num[1] = atoi(argv[3]);
    cout<<"Cliente Iniciado"<<endl;
    while(rep<atoi(argv[4])){
        Solicitud s;
        int res=0;
        // memcpy(&res, s.doOperation(argv[1], 7200, 1, (char *)&num), 4);
        memcpy(&res, s.doOperation(argv[1], 7200, 1, (char *)&num,3,0), 4);
      //  cout<<"El resultado de "<<num[0]<<" + "<<num[1]<<" es: "<<res<<endl; 
      //Se comenta la línea 23 para evitar la impresión de pantalla.
	rep++;
    }
    return 0;
}
