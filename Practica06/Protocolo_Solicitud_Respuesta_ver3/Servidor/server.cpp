#include "Respuesta.h"
#include <cstring>
#include <iostream>
using namespace std;

int nbd = 0;

int main()
{
    Respuesta resp(7200);
    cout << "Cajero iniciado....\n";
 
    while(1){
        struct mensaje *msj = resp.getRequest();
        
        if(msj != NULL) {
        	int n = 0;
	        memcpy(&n, &msj->arguments, 4);
	        nbd = nbd + n;
	        printf("\nRecibido: %d \nNBD: %d\n", n, nbd);
	        resp.sendReply((char *)&nbd);
        }else{
            resp.sendReply((char *)&nbd);
        }
    }
}
