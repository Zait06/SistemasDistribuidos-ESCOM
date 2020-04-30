#include "Respuesta.h"
#include <cstring>
#include <iostream>
using namespace std;
int main(){
    int nbd=0;
    Respuesta resp(7200);
    cout << "Servidor iniciado....\n";
    while (true) {
        struct mensaje *msj = resp.getRequest();

        
        if(msj != NULL) {

	        resp.sendReply((char *)&nbd);
        }else{//si es duplicado
            resp.sendReply((char *)&nbd);
        }
        
    }
}