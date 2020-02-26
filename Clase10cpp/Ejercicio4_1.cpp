#include <iostream>
#include <cmath>
#include <unistd.h>
#include <stdio.h>
#include <thread>
#include <cstring>
#include <fcntl.h>
using namespace std;
char buffer[1757600*4];

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
    
    for(int i=0; i<1757600*4 ; i++){
        write(destino, buffer+i, 1);
    }


	 fsync(destino);
	 close(destino);
}


int main(int argc, char *argv[])
{
	 if(argc != 3){
	 cout << "Forma de uso: " << argv[0] <<" nombre_del_archivo1 nombre2\n";
	 exit(0);
	 }
	thread th1(dd, argv[1] ), th2(dd, argv[2] );
	th1.join();
	th2.join();
	exit(0);
}