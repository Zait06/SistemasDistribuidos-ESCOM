#include "Solicitud.h"
#include <string.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    /*Los dos enteros se le deben pasar al cliente como parámetros en la línea de comandos.*/
    if(argc != 3) {
		printf("Forma de uso: %s ip_servidor n\n", argv[0]);
		exit(0);
	}

	cout<<"Cliente Iniciado"<<endl;
	Solicitud s;
	int seguir=0;
	srand(time(NULL));
	int res=0;
	for(int i=1;i<=atoi(argv[2]);i++){
		int num=1+rand()%9;
		// cout<<"Moneda con valor $"<<num<<endl;
		res=0;
		memcpy(&res, s.doOperation(argv[1], 7200, 1, (char *)&num,2,0), 4);
		// cout<<"El resultado "<<res<<endl;
		// cout<<"El valor es correcto?\n1. Si\t2. No\nR.- ";
		// cin>>seguir;
		seguir+=num;
		if(res!=seguir){
			cout<<"El acumludao es incorrecto: "<<res<<" != "<<seguir<<endl;
			exit(0);
		}
		// cout<<endl;
	}
	cout<<"Acumulado: "<<res<<endl;

    return 0;
}
