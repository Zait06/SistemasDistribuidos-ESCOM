#include "Coordenada.h"
#include <vector>
using namespace std;
#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_
class PoligonoIrreg{
        private:
                vector<Coordenada> poligono;
                static int numVertices;
	public:
                PoligonoIrreg(double=0,double=0,double=1,double=1,double=1,double=0);
                void anadeVertice(double xx, double yy);
                void imprimeVertices();
                static int getNumVertices();
};

#endif