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
// imprimir las coordenadas y la magnitud(distancia de la coordenada al origen)
// de cada elemento del vector, pero haciendo uso de un iterador para recorrerlo. Para mejorar el
// desempeño es necesario añadir un dato miembro para almacenar la magnitud.
    // int i;
    // for(i=0;i<coordenadas.size();i++)
    //     cout<<"Vertice ("<<coordenadas[i].obtenerX()<<","<<coordenadas[i].obtenerY()<<")"<<endl;

    vector<Coordenada>::iterator i;
    for (i = coordenadas.begin( ); i != coordenadas.end( ); i++){
        Coordenada c=*i;
         cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(3);
        cout<<"Vertice ("<<c.obtenerX()<<","<<c.obtenerY()<<"), Magnitud: "<< c.obtenerMag()<<endl;

    }
 
}