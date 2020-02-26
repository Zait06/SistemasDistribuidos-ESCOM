#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <thread>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>
using namespace std;

#define numeroElementos 100000000
char buffer[1757600*4];
void DD(long n, int argc, char *argv[]){
    int destino;
	if(argc != 2)
    {
	    cout << "Forma de uso: " << argv[0] <<" nombre_del_archivo\n";
	    exit(0);
	}
    string npalabras;
    string alfabeto  ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    n=1757600;
    string palabra="";
    srand(time(NULL));
    string letra;
    // generar n “palabras” de tres
    // letras cada una y de contenido aleatorio
    for (long i=0; i<n; i++)
    {
        for(int j=0; j<3; j++)
        {
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
	if((destino = open(argv[1], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1)
	{
	    perror(argv[1]);
	    exit(-1);
	}
    //write(destino, buffer, strlen(buffer));
    for(int i=0; i<1757600*4; i++)
    {
        write(destino, buffer+i, 1);
    }
    fsync(destino);
	close(destino);
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

int main(int argc, char *argv[])
{
    /*if(argc != 2){
        cout << "Forma de uso: " << argv[0] <<" valor_de_n\n";
        exit(0);
	}*/
    //int a=strtol(argv[1], NULL, 10);
    long a =1757600*4;
	thread th1(DD,a, argc, argv), th2(ram,a);
	th1.join();
	th2.join();
	exit(0);
}