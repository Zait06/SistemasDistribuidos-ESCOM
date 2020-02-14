#include "PoligonoIrreg.h"
#include "Coordenada.h"
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int main(){
    // PoligonoIrreg pp1=PoligonoIrreg();
    // pp1.anadeVertice(5,5);
    // pp1.imprimeVertices();

    int i,j;
    //en la función principal instancie un objeto PoligonoIrreg al cual posea n vértices
    PoligonoIrreg ppn;
    int n=25;
    for(i=0;i<n;i++)
        ppn.anadeVertice( (drand48()* (100.000-300.000) + 100.000),(drand48()* (100.000-300.000) + 100.000));
    
    ppn.imprimeVertices();
    
    cout<<endl;
    ppn.ordenaA();

    ppn.imprimeVertices();

    //cout<<"Numero de vertices: "<<ppn[0].getNumVertices()<<endl;

    return 0;
}