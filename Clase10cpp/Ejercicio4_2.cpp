#include <iostream>
#include <cmath>
#include <unistd.h>
#include <stdio.h>
#include <thread>
using namespace std;

#define numeroElementos 100000000

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
        cout << "Forma de uso: " << argv[0] <<" valor_de_n\n";
        exit(0);
	}
    int a=strtol(argv[1], NULL, 10);
	thread th1(ram,a), th2(ram,a);
	th1.join();
	th2.join();
	exit(0);
}