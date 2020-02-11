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
    
    vector<PoligonoIrreg> ppn;

    // Sin reservar con push_back
    for(i=0;i<10000;i++){
        ppn.push_back((PoligonoIrreg()));
        for(j=0;j<10000;j++)
            ppn[i].anadeVertice(rand()%100,rand()%100);
    }

    // Reservando memoria
    // ppn.reserve(10000);
    // for(i=0;i<10000;i++){
    //     ppn[i]=PoligonoIrreg();
    //     for(j=0;j<10000;j++)
    //         ppn[i].anadeVertice(rand()%100,rand()%100);
    // }

    cout<<"Numero de vertices: "<<ppn[i].getNumVertices()<<endl;
    
    return 0;
}