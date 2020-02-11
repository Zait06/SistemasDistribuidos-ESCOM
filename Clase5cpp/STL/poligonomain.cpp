#include "PoligonoIrreg.h"
#include "Coordenada.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
    PoligonoIrreg pp1(0,0,1,1,1,0);
    pp1.anadeVertice(5,5);
    pp1.imprimeVertices();
    
    vector<PoligonoIrreg> ppn;
    // ppn.reserve(20);
    
    return 0;
}