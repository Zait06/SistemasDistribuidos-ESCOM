#include "Coordenada.h"
#include <iostream>
#include <math.h>
using namespace std;

Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy)
{
	mag=x*x+y*y; 
	mag=sqrt(mag);
}

double Coordenada::obtenerX()
{
	return x;
}

double Coordenada::obtenerY()
{
	return y;
}

double Coordenada::obtenerMag()
{
	return mag;
}
