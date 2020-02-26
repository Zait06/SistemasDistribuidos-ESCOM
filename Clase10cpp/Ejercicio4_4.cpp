#include <iostream>
#include <cmath>
#include <unistd.h>
#include <stdio.h>
#include <thread>
#include <fcntl.h>
#include <cstring>
using namespace std;

void DD(char nombre[]){
	char buffer[1757600*4];
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
    for(int i=0; i< 1757600*4; i++){
        write(destino, buffer+i, 1);
    }
	 fsync(destino);
	 close(destino);
}

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
    if(argc != 3){
        cout << "Forma de uso: " << argv[0] <<" valor_de_n\n";
        exit(0);
	}
    //String a=strtol(argv[1], NULL, 10);
    int b=strtol(argv[2], NULL, 10);
	thread th1(DD,argv[1]),th2(cpu,b);
	th1.join();
	th2.join();
	exit(0);
}