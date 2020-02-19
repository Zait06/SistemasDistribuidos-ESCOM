#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <thread>
using namespace std;

int varGlob=0;

void incrementa(int n){
	varGlob++;
	sleep(1);
}

void decrementa(int n){
	varGlob--;
	sleep(1);
}

int main()
{
	thread th1(incrementa), th2(decrementa);
	cout << "Proceso principal espera que los hilos terminen\n";
	th1.join();
	th2.join();
	cout << "El hilo principal termina\n";
	cout<<"Valor global: "<<varGlob<<endl;
	exit(0);
}