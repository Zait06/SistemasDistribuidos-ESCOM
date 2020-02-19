#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
    double n=strtod(argv[1], NULL);
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

    return 0;
}