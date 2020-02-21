#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <thread>
#include <atomic>
#include <mutex>

using namespace std;
mutex m;

void incrementa(atomic<int>& variable, int n){
	for(int i=0;i<n;i++)
        variable++;
}

void decrementa(atomic<int>& variable, int n){
    for(int i=0;i<n;i++)
        variable--;
}

int main(int argc, char *argv[])
{
    atomic<int> var_local(0);
    int a=strtol(argv[1], NULL, 10);
    
	thread th1(incrementa,ref(var_local), a);
    thread th2(decrementa,ref(var_local), a);
	cout << "Proceso principal espera que los hilos terminen\n";
	th1.join();
    m.lock();
	th2.join();
    m.unlock();
	cout << "El hilo principal termina\n";
	cout<<"Valor global: "<<var_local<<endl;
	exit(0);
}