#include <iostream>
#include <cmath>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <thread>
using namespace std;

#define numeroElementos 100000000
char buffer[1757600*4];

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

void dd(char nombre[]){
    int destino;
    long n;
    string npalabras;
    string alfabeto  ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    n=1757600;
    string palabra="";
    srand(time(NULL));
    string letra;
    // generar n “palabras” de tres
    // letras cada una y de contenido aleatorio
    for (long i=0; i<n; i++){
        for(int j=0; j<3; j++){
            letra=alfabeto[1+rand()%(25)];
            palabra.append(letra);
        }
        //manteniendo un espacio en blanco de separación entre cada palabra.
        palabra.append(" ");
        npalabras.append(palabra);
        palabra="";
    }

	strcpy(buffer, npalabras.c_str( ));

	 //Abre un archivo para escritura, si no existe lo crea, si existe lo trunca, con permisos rw-
	 if((destino = open(nombre, O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1)
	 {
        perror(nombre);
        exit(-1);
	 }
    //write(destino, buffer, strlen(buffer));
    
    for(int i=0; i<1757600*4; i++){
        write(destino, buffer+i, 1);
    }


	 fsync(destino);
	 close(destino);
}

int main(int argc, char *argv[])
{
    if(argc != 2){
        cout << "Forma de uso: " << argv[0] <<" valor_de_n\n";
        exit(0);
	}
    int a=strtol(argv[1], NULL, 10);
	thread th1(cpu,a), th2(ram,a),th2(dd,argv[2]); 
	th1.join();
	th2.join();
	exit(0);
}