#include "Fecha.h"
#include <iostream>
#include <ctime>
using namespace std;

// int masVieja(Fecha fecha1, Fecha fecha2);
int masVieja(Fecha &fecha1, Fecha& fecha2);
// int masVieja(Fecha *fecha1, Fecha *fecha2);

int main(){
    Fecha a(21,9,2020),b;
    int n,fff;
    int d00,m00,a00;
    int d01,m01,a01;
    // cout<<sizeof(a)<<endl;
    // a.muestraFecha();
    // cout<<"Ingrese el número de veces a repetir: ";
    // cin>>n;
    n=10000000;

    srand(time(NULL));

    for(int i=0;i<n;i++){
        d00=1+rand()%(30);
        m00=1+rand()%(12);
        a00=0+rand()%(2020);
        d01=1+rand()%(30);
        m01=1+rand()%(12);
        a01=0+rand()%(2020);
        a.inicializaFecha(d00,m00,a00);
        b.inicializaFecha(d01,m01,a01);
        fff=masVieja(a,b);
        // cout<<masVieja(a,b)<<endl;
        // cout<<masVieja(a,b)<<endl;
        // cout<<<<endl;
    }
}

// int masVieja(Fecha fecha1, Fecha fecha2){
//     int a,b,r;
//     a=fecha1.convierte();
//     b=fecha2.convierte();
//     if(a>b){
//         r=1;
//     }else if(a==b){
//         r=0;
//     }else{
//         r=-1;
//     }

//     return r;
// }

int masVieja(Fecha &fecha1, Fecha& fecha2){
    int a,b,r;
    a=fecha1.convierte();
    b=fecha2.convierte();
    if(a>b){
        r=1;
    }else if(a==b){
        r=0;
    }else{
        r=-1;
    }
    return r;
}

// int masVieja(Fecha *fecha1, Fecha *fecha2){
//     int a,b,r;
//     a=fecha1->convierte();
//     b=fecha2->convierte();
//     if(a>b){
//         r=1;
//     }else if(a==b){
//         r=0;
//     }else{
//         r=-1;
//     }
//     return r;
// }