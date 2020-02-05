#include "Fecha.h"
#include <iostream>
using namespace std;

int main(){
    Fecha a, b, c(21,9,1973),f(4,3,1600);
    int s=0;
    b.inicializaFecha(17,6,2000);
    a.muestraFecha();
    b.muestraFecha();
    c.muestraFecha();
    cout<<a.convierte()<<endl;
    cout<<b.convierte()<<endl;
    cout<<c.convierte()<<endl;
    for(int i=1;i<2021;i++){
        f.inicializaFecha(1,1,i);
        if(f.leapyr()){
            s++;
        }
    }
    cout<<s<<endl;
}