#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <thread>
using namespace std;

int varGlob=0;

void funcion(int valor)
{
	printf("Hilo: %ld Valor recibido: %d\n",(this_thread::get_id()),valor);
	sleep(2);
}

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
	// thread th1(funcion, 5), th2(funcion, 10);
	thread th1(incrementa), th2(decrementa);
	cout << "Proceso principal espera que los hilos terminen\n";
	th1.join();
	th2.join();
	cout << "El hilo principal termina\n";
	cout<<"Valor global: "<<varGlob<<endl;
	exit(0);
}