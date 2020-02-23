#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]){
    double n=strtol(argv[1], NULL, 10);
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