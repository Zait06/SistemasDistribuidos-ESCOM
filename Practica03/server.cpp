#include "SocketDatagrama.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[]) {
    SocketDatagrama servidor(7200), cliente(7200);
    PaqueteDatagrama paqueteRec(2);
    char num[2],*msg;
    int res;
    cout<<"\nSERVIDOR"<<endl;
    while(1){
        servidor.recibe(paqueteRec);
        memcpy(num, paqueteRec.obtieneDatos(), sizeof(char)*2);
        cout<<num<<endl;
    }
    return 0;
}