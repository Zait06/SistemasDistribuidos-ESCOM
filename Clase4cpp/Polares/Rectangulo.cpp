#include "Rectangulo.h"
#include "Coordenada.h"
#include <iostream>
using namespace std;

Rectangulo::Rectangulo() : superiorIzq(0,0), inferiorDer(0,0)
{ }

Rectangulo::Rectangulo(Coordenada supIzq, Coordenada infDer)
{
    superiorIzq = supIzq;
    inferiorDer = infDer;
}

Rectangulo::Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer):superiorIzq(xSupIzq, ySupIzq), inferiorDer(xInfDer, yInfDer)
{ }



void Rectangulo::imprimeEsq()
{
    cout << "Para la esquina superior izquierda.\n";
    cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY() << endl;
    cout << "Para la esquina inferior derecha.\n";
    cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY() << endl;
}


double Rectangulo::obtieneArea()
{
    double alto, ancho;
    alto = superiorIzq.obtenerY() -inferiorDer.obtenerY();
    ancho = inferiorDer.obtenerX() - superiorIzq.obtenerX();
    return ancho*alto;
}


Coordenada Rectangulo::obtieneSupIzq()
{
    return superiorIzq;
}

Coordenada Rectangulo::obtieneInfDer()
{
    return inferiorDer;
}