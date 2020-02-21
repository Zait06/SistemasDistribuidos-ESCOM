#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <thread>
#include <atomic>
using namespace std;

int varGlob=0;
atomic<int> global(0);

void incrementa(int n){
	for(int i=0;i<n+1;i++)
        global++;
}

void decrementa(int n){
    for(int i=0;i<n;i++)
        global--;
}

int main(int argc, char *argv[])
{
    //atomic<int> var_local(0);
    int a=strtol(argv[1], NULL, 10);
    
	thread th1(incrementa, a), th2(decrementa, a);
	cout << "Proceso principal espera que los hilos terminen\n";
	th1.join();
	th2.join();
	cout << "El hilo principal termina\n";
	cout<<"Valor global: "<<global<<endl;
	exit(0);
}