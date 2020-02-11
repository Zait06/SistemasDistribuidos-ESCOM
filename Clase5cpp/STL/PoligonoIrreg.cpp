#include "PoligonoIrreg.h"
#include "Coordenada.h"
#include <iostream>
#include <vector>
using namespace std;

PoligonoIrreg::PoligonoIrreg(double x1,double y1,double x2,double y2,double x3,double y3){
    poligono.push_back(Coordenada(x1,y1));
    poligono.push_back(Coordenada(x2,y2));
    poligono.push_back(Coordenada(x3,y3));
    numVertices=+3;
}

int PoligonoIrreg::numVertices=0;

void PoligonoIrreg::anadeVertice(double xx, double yy){
    poligono.push_back(Coordenada(xx,yy));
    numVertices++;
}

void PoligonoIrreg::imprimeVertices(){
    int i;
    for(i=0;i<poligono.size();i++)
        cout<<"Vertice ("<<poligono[i].obtenerX()<<","<<poligono[i].obtenerY()<<")"<<endl;
}

int PoligonoIrreg::getNumVertices(){
    return numVertices;
}