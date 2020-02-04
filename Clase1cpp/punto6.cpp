#include <iostream>
using namespace std;

int main(){
    double precio=78.7;

    cout<<"Precio: "<<precio<<endl;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<"Precio: "<<precio<<endl;

    return 0;
}