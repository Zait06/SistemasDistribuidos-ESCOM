#include "PoligonoIrreg.h"
#include "Coordenada.h"
#include <iostream>
#include <vector>
using namespace std;

int PoligonoIrreg::numVertices=0;

int PoligonoIrreg::getNumVertices(){
    return numVertices;
}

PoligonoIrreg::PoligonoIrreg(double x1,double y1,double x2,double y2,double x3,double y3){
    coordenadas.push_back(Coordenada(x1,y1));
    coordenadas.push_back(Coordenada(x2,y2));
    coordenadas.push_back(Coordenada(x3,y3));
    numVertices=numVertices+3;
    return;
}

void PoligonoIrreg::anadeVertice(double xx, double yy){
    coordenadas.push_back(Coordenada(xx,yy));
    numVertices++;
    return;
}

void PoligonoIrreg::imprimeVertices(){
    int i;
    for(i=0;i<coordenadas.size();i++)
        cout<<"Vertice ("<<coordenadas[i].obtenerX()<<","<<coordenadas[i].obtenerY()<<")"<<endl;
}