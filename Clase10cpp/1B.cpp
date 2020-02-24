#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

using namespace std;
char buffer[BUFSIZ];

int main(int argc, char *argv[])
{
    int destino;

    if(argc != 2){
	    cout << "Forma de uso: " << argv[0] <<" nombre_del_archivo\n";
	    exit(0);
	}

    string linea;
    string alfabeto  ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string npalabras;
    string palabra="";
    srand(time(NULL));
    string letra;
    int n;

    cout<<"Introdusca n: ";
    cin>>n;
    for (int i=0; i<n; i++)
    {
        for(int j=0; j<3; j++)
        {
            letra=alfabeto[1+rand()%(25)];
            palabra.append(letra);
        }
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
    
    for(int i=0; i<strlen(buffer); i++)
    {
        write(destino, buffer+i, 4);
    }
        
    fsync(destino);
    close(destino);
}
