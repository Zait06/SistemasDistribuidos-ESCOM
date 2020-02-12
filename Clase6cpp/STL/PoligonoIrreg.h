#include "Coordenada.h"
#include <vector>
using namespace std;
#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_

class PoligonoIrreg{
        private:
                vector<Coordenada> coordenadas;
                static int numVertices;
	public:
                static int getNumVertices();
                PoligonoIrreg(double=0,double=0,double=1,double=1,double=1,double=0);
                void anadeVertice(double xx, double yy);
                void imprimeVertices();
                void ordenaA();
};

#endif