#include <iostream>
#include <cmath>
#include <unistd.h>
#include <stdio.h>
#include <thread>
using namespace std;

#define numeroElementos 100000000

void cpu(double n){
    double i=0;
    double seno=0;
    double coseno=0;
    double tangente=0;
    double logaritmo=0;
    double raiz=0;
    while (i<n)
    {
        seno=sin(i);
        coseno=cos(i);
        tangente=tan(i);
        logaritmo=log(i);
        raiz=sqrt(i);
        i++;
    }
}

void ram(long n){
    int *arreglo, i;
	arreglo = new int[numeroElementos];
	for(i = 0; i < numeroElementos; i++)
	arreglo[i] = 0;
	for(i = 0; i < n; i++){
	arreglo[rand()%numeroElementos] = rand();
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2){
        cout << "Forma de uso: " << argv[0] <<" valor_de_n nombre_archivo\n";
        exit(0);
	}
    int a=strtol(argv[1], NULL, 10);
	thread th1(cpu,a), th2(ram,a);
	th1.join();
	th2.join();
	exit(0);
}