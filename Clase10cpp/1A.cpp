#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
using namespace std;
char buffer[1757600*4];
int main(int argc, char *argv[])
{
    int destino;
	 if(argc != 2){
	 cout << "Forma de uso: " << argv[0] <<" nombre_del_archivo\n";
	 exit(0);
	 }
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
	 if((destino = open(argv[1], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1)
	 {
	 perror(argv[1]);
	 exit(-1);
	 }
    //write(destino, buffer, strlen(buffer));
    
    for(int i=0; i<strlen(buffer) ; i++){
        write(destino, buffer+i, 1);
    }


	 fsync(destino);
	 close(destino);
}