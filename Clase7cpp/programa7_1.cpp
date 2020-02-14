#include <string>
#include <iostream>
using namespace std;

int main(){
    int n;
    string line;
    cout<<"Ingreese el numero: ";
    cin>>n;
    cout<<"Ingrese un texto: ";
    getline(cin,line);
    cout<<line<<endl;

    return 0;
}