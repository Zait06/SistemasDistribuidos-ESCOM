#include <iostream>
#include <cmath>
#include <unistd.h>
#include <stdio.h>
#include <thread>
using namespace std;

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

int main(int argc, char *argv[])
{
    if(argc != 2){
        cout << "Forma de uso: " << argv[0] <<" valor_de_n\n";
        exit(0);
	}
    int a=strtol(argv[1], NULL, 10);
	thread th1(cpu,a), th2(cpu,a);
	th1.join();
	th2.join();
	exit(0);
}