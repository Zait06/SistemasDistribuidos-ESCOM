#include "PaqueteDatagrama.h"

PaqueteDatagrama::PaqueteDatagrama(char *dd, unsigned int ll, char *cip, int pp){
    datos=new char[ll];
    datos=dd;
    longitud=ll;
    memcpy(ip,cip,sizeof(char)*16);
    puerto=pp;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int ll){
    datos=new char[ll];
    longitud=ll;
}

PaqueteDatagrama::~PaqueteDatagrama(){
    delete datos;
}

char *PaqueteDatagrama::obtieneDireccion(){
    return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud(){
    return longitud;
}

int PaqueteDatagrama::obtienePuerto(){
    return puerto;
}

char *PaqueteDatagrama::obtieneDatos(){
    return datos;
}

void PaqueteDatagrama::inicializaDatos(char *dd){
    memcpy(datos, dd, longitud);
}

void PaqueteDatagrama::inicializaIp(char *cip){
    memcpy(ip, cip, sizeof(char)*16);
}

void PaqueteDatagrama::inicializaPuerto(int pp){
    puerto=pp;
}