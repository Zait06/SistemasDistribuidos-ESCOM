#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]){
    int n;
    string npalabras;
    string alfabeto  ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // cout << "Ingrese el número de palabras: ";
    // cin >> n;
    n=strtol(argv[1], NULL, 10);
    string palabra="";
    srand(time(NULL));
    string letra;
    // generar n “palabras” de tres
    // letras cada una y de contenido aleatorio
    for (int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            letra=alfabeto[1+rand()%(25)];
            palabra.append(letra);
        }
        //manteniendo un espacio en blanco de separación entre cada palabra.
        palabra.append(" ");
        npalabras.append(palabra);
        palabra="";
    }
    //cout<< npalabras;
    int total=0;
    int pos=0;
    int i=0;
    //búsqueda de la subcadena “IPN”
    while(i<npalabras.length()){
        if(npalabras.find("IPN", pos)!= string::npos){
            total++;
            pos=npalabras.find("IPN", pos) + 2;
        }else{
            break;
        }
    }
    cout << "numero de ocurrencias: " << total<<endl;   
    return 0;
}