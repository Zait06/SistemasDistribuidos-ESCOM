#include "Coordenada.h"
#include "Rectangulo.h"
#include <iostream>
using namespace std;

int main()
{
    Rectangulo rectangulo1(2,3,5,1);

    cout << "Calculando el área de un rectángulo dadas sus coordenadas en un plano cartesiano:" << endl;
    
    rectangulo1.imprimeEsq();

    cout << "El área del rectángulo es = " <<rectangulo1.obtieneArea()<< endl;

    return 0;
 }