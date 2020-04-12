#include "Solicitud.h"
#include <string.h>
#include <unistd.h>
#include <iostream>
using namespace std;
int randNum();

int main(int argc, char *argv[])
{
	int cont = 0;
	int res = 0;
	int cuenta = 0;
	
	if (argc != 3)
	{
		printf("Forma de uso: %s ip_servidor n\n", argv[0]);
		exit(0);
	}
	
	cout<<"Cliente Iniciado"<<endl;
	
	srand(time(NULL));
	int n = atoi(argv[2]);
	
	while (cont < n)
	{
		int arr = 1 + rand() % 9;
		Solicitud s;

		memcpy(&res, s.doOperation(argv[1], 7200, 1, (char *)&arr), 4);
		cuenta = cuenta + arr;
		if (cuenta != res)
		{
			cout<<"El acumludao es incorrecto: "<<res<<" != "<<cuenta<<endl;
			exit(0);
		}
		cont++;
	}
	cout<<"Acumulado: "<<res<<" Original: "<<cuenta<<endl;
	
	return 0;
}
