#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int n = 0, v= 0, i , j;
    char* gigante = NULL;
    char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char palabra[4];
    char ipn[] = "IPN";
    // printf("Ingresa N: ");
    // scanf("%d", &n);
	n=strtol(argv[1], NULL, 10);

    for (int i = 0; i < n; i++) {
    	gigante = (char*)realloc(gigante, (i + 1) * 4);
    for(int i = 0; i < 3; i++) {
		int aleat = rand() % 25;
		palabra[i] = alfabeto[aleat];
	}
	palabra[3] = ' ';
	memcpy(gigante + 4 * i, palabra, 4);

}
    int SUB = strlen(ipn); //Tamaño de la subcadena 3
	int CAD = strlen(gigante); //Tamaño de la cadenota
	for(i = 0; i <= CAD-SUB; i++) {
		for(j = 0; j < SUB; j++)
			if(gigante[i + j] != ipn[j])
				break;
		if(j == SUB)
			v++;
	}
    printf("Subcadena IPN encontrada: %d veces\n", v);
    return 0;
}
