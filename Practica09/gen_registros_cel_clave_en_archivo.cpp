//Programa para crear registros de votos [celular, CURP, partido, separador], con el campo "celular" como clave 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream> 
#include <iterator> 
#include <sys/types.h>
#include <sys/stat.h>
#include <cstring>

#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <cstdlib>      // std::rand, std::srand
#include <fstream>

using namespace std; 

struct registro{
	char celular[11];
	char CURP[19];
	char partido[4];
};

char buffer[BUFSIZ];

int main(int argc, char *argv[]){
	char telefono[11], curp[19], t[11], sexo;
	int i, n, destino, j, opcion, inicial, elemento;;
	struct registro reg1;
    vector<struct registro> registros_vector;

	//Partidos disponibles 2018
	char const partidos[9][4] = {"PRI", "PAN", "PRD", "P_T", "VDE", "MVC", "MOR", "PES", "PNL"};

	//Entidades federativas
	char const entidad[32][3] =  {"AS", "BC", "BS", "CC", "CS", "CH", "CL", "CM", "DF", "DG", "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TL", "TS", "VZ", "YN", "ZS"};

	if(argc != 3){
		printf("Forma de uso: programa numero_registros nombre_archivo\n");
		exit(0);
	}

	//Numero de registros n
	n = atoi(argv[1]);

	//Genera un numeros telefonicos inicial de 9 digitos y despues se obtendran su secuenciales para evitar repeticion
	inicial = 500000000 + rand()%100000000;

	//Crea todos los registros con numero de telefono consecutivo y los almacena en un vector
	for(j=0; j<n; j++){
		sprintf(telefono, "5%9d", inicial);
		inicial++;
		strcpy(reg1.celular, telefono);

		if(rand()%2 == 0)
			sexo = 77;
		else
			sexo = 72;

		i = rand()%32;
		sprintf(curp, "%c%c%c%c%c%c%c%c%c%c%c%s%c%c%c%c%c", 65 + rand()%25 , 65 + rand()%25, 65 + rand()%25, 65 + rand()%25, rand()%10 + 48, rand()%10 + 48, rand()%10 + 48, rand()%10 + 48, rand()%10 + 48, rand()%10 + 48, 
			sexo, entidad[i], 65 + rand()%25, 65 + rand()%25, 65 + rand()%25, rand()%10 + 48, rand()%10 + 48);
		strcpy(reg1.CURP, curp);

		i = rand()%9;
		strcpy(reg1.partido, partidos[i]);
		registros_vector.push_back(reg1);
	}

    //Abre un archivo para escritura, si no existe lo crea, si existe lo trunca, con permisos rw-
    // if((destino = open(argv[2], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1)
    // {
    //     perror(argv[2]);
    //     exit(-1);
    // }
	fstream archivo(argv[2],fstream::in | fstream::out | fstream::trunc); 

	//Aleatoriza el vector de registros e imprime el resultado
	random_shuffle(registros_vector.begin(), registros_vector.end());
	for (std::vector<struct registro>::iterator it=registros_vector.begin(); it!=registros_vector.end(); ++it){
		reg1 = *it;
		// write(1, &reg1, sizeof(reg1));
        // write(destino,&reg1, sizeof(reg1));
        // write(destino,"\n",1);
		char *info=reg1.celular;
		strcat(strcat(info,reg1.CURP),reg1.partido);
		strcat(info,"\n");
		archivo.write(info,32);
		// printf("\n");
	}
    // close(destino);
	archivo.close();
    exit(0);
}
