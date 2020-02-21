#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <thread>
#include <mutex>

using namespace std;

int varGlob=0;
mutex mux;

void incrementa(int n){
	for(int i=0;i<n;i++){
		mux.lock();
        varGlob++;
		mux.unlock();
	}	
}

void decrementa(int n){
    for(int i=0;i<n;i++){
		mux.lock();
        varGlob--;
		mux.unlock();
	}
}

int main(int argc, char *argv[])
{
    int a=strtol(argv[1], NULL, 10);
	thread th1(incrementa,a), th2(decrementa,a);
	printf("Proceso principal espera que los hilos terminen\n");
	th1.join();
	th2.join();
	printf("El hilo principal termina\n");
    printf("VALOR: %d\n", varGlob);
	exit(0);
}