#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <thread>
using namespace std;

int varGlob=0;

void incrementa(int n){
	for(int i=0;i<n;i++)
        varGlob++;
}

void decrementa(int n){
    for(int i=0;i<n;i++)
        varGlob--;
}

int main(int argc, char *argv[])
{
    int a=strtol(argv[1], NULL, 10);
	thread th1(incrementa,a), th2(decrementa,a);
	cout << "Proceso principal espera que los hilos terminen\n";
	th1.join();
	th2.join();
	cout << "El hilo principal termina\n";
	cout<<"Valor global: "<<varGlob<<endl;
	exit(0);
}