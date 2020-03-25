#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;

SocketDatagrama::SocketDatagrama(int puerto) {

	bzero((char *)&direccionForanea, sizeof(direccionForanea));
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	if ((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	}
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	if(puerto == 0)
		direccionLocal.sin_port = htons(puerto);
	else
		direccionLocal.sin_port = puerto;
	if (bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal))<0 ) { 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	}
}

SocketDatagrama::~SocketDatagrama() {
    close(s);
}

int SocketDatagrama::recibe(PaqueteDatagrama &p){
    socklen_t clilen = sizeof(direccionForanea);
    int i = recvfrom(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *) &direccionForanea, &clilen);
    unsigned char ip[4];
	memcpy(ip, &direccionForanea.sin_addr.s_addr, 4);

    string ip1 = to_string(ip[0]);
	string ip2 = to_string(ip[1]);
	string ip3 = to_string(ip[2]);
	string ip4 = to_string(ip[3]);

	ip1.append(".");
	ip1.append(ip2);
	ip1.append(".");
	ip1.append(ip3);
	ip1.append(".");
	ip1.append(ip4);

    char dirIp[16];
	strcpy(dirIp, ip1.c_str());
	p.inicializaIp(dirIp);
	p.inicializaPuerto(direccionForanea.sin_port);
    return i;
}

int SocketDatagrama::envia(PaqueteDatagrama &p){
    direccionForanea.sin_family = AF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
    direccionForanea.sin_port = p.obtienePuerto();
    return sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud()* sizeof(char), 0, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea)); 
}

int SocketDatagrama::recibeTiemout(PaqueteDatagrama &p, time_t segundos, suseconds_t microsegundos){
	// Inicialización de timeout
	timeout.tv_sec=segundos;
	timeout.tv_usec=microsegundos;

	/*
		Función para inicializar timeval, es decir,
		que correrá un reloj para saber si llegó o no un mensaje
	*/
	setsockopt(s,SOL_SOCKET,SO_RCVTIMEO,(char *)&timeout,sizeof(timeout));
	
	socklen_t clilen = sizeof(direccionForanea);
    int i = recvfrom(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *) &direccionForanea, &clilen);
    unsigned char ip[4];
	memcpy(ip, &direccionForanea.sin_addr.s_addr, 4);

    string ip1 = to_string(ip[0]);
	string ip2 = to_string(ip[1]);
	string ip3 = to_string(ip[2]);
	string ip4 = to_string(ip[3]);

	ip1.append(".");
	ip1.append(ip2);
	ip1.append(".");
	ip1.append(ip3);
	ip1.append(".");
	ip1.append(ip4);

    char dirIp[16];
	strcpy(dirIp, ip1.c_str());
	p.inicializaIp(dirIp);
	p.inicializaPuerto(direccionForanea.sin_port);

	if(i<0){
		if(errno==EWOULDBLOCK){		// Si el tiempo acabó, regresar -1
			cout<<"Tiempo de recepción transcurrido"<<endl;
			return -1;
		}
	}
	return i;
}