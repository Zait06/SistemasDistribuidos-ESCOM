#include <iostream>
using namespace std;

int main(){
    const double PI=3.1415926;
    double radio,res,pi2;

    cout<<"\tRadio de un circulo"<<endl;
    cout<<"Ingrese el valor del radio: ";
    cin>>radio;
    res=PI*radio*radio;
    cout<<"El area del cirulo es: "<<res<<endl;
    PI=res;

    return 0;
}