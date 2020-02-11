#include "Coordenada.h"
#include <math.h>

Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy)
{ }



// double Coordenada::obtenerX()
// {
//     return x;
// }

// double Coordenada::obtenerY()
// {
//     return y;
// }


double Coordenada::obtenerX()
{
    return x*cos((y*2*3.1416)/360);
}

double Coordenada::obtenerY()
{
    return x*sin((y*2*3.1416)/360);
}

