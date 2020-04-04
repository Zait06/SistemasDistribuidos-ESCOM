#include "Solicitud.h"
#include <string.h>
#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, char* argv[]){
    /*Los dos enteros se le deben pasar al cliente como parámetros en la línea de comandos.*/
    if(argc != 3) {
		cout<<"Forma de uso:"<<argv[0]<<" ip_servidor n\n"<<endl;;
		exit(0);
	}

	int seguir=0;
	cout<<"Cliente Iniciado"<<endl;
	srand(time(NULL));
	for(int i=1;i<=atoi(argv[2]);i++){
		int num=1+rand()%10;
		cout<<"Moneda de $"<<num<<endl;
		int res;
		int res2;
		Solicitud s;

		do
		{
			memcpy(&res, s.doOperation(argv[1], 7200, 1, (char *)&num, 2, 500000), 4);
			cout<<res<<" Volviendo a enviar mensaje\n";
		}while(res != -1);

		cout<<"La cantidad acumulada es: "<<res<<endl;
		cout<<"Es correcta la cantidad?\n1. Si\t2. No\nR.-";
		cin>>seguir;
		if(seguir==2)
			break;
	}
    
    return 0;
}