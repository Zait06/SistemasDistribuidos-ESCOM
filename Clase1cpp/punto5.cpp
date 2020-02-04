#include <iostream>
#include <string>
using namespace std;

int main(){
    int n=2;
    int op=0;
    op=n+(++n);
    cout<<"op="<<op<<endl;

    return 0;
}