#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]){
    //
    cout <<"Servidor iniciado...\n"<<endl;
    ifstream archivo(argv[1]);       // Abrimos un documento con el nombre que tenga argv[1]
    string s;

    while(getline(archivo,s)){
        cout<<s<<endl;
    }

    archivo.close();
    // while(1){
    //     struct mensaje* msj = resp.getRequest();
    //     char *moneda;
    //     memcpy(&moneda, &msj->arguments, sizeof(msj->arguments));
        
    // }

    return 0;
}
