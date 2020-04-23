#include "SocketMulticast.h"

SocketMulticast::SocketMulticast(int puerto){
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
    s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(s<0){
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

SocketMulticast::~SocketMulticast(){
    close(s);
}

int SocketMulticast::recibe(PaqueteDatagrama &p){
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

int SocketMulticast::envia(PaqueteDatagrama &p, unsigned char ttl){
    int n=setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *) &ttl, sizeof(ttl));
    if(n<0){
        perror("Error al enviar el mensaje");
    }else{
        direccionForanea.sin_family = AF_INET;
        direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
        direccionForanea.sin_port = p.obtienePuerto();
        return sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud()* sizeof(char), 0, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea)); 
    }
}

void SocketMulticast::unirseGrupo(char *multicastIP){
    multicast.imr_multiaddr.s_addr = inet_addr(multicastIP);
    multicast.imr_interface.s_addr = htonl(INADDR_ANY);
    int aceptado=setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *) &multicast, sizeof(multicast));
    if(aceptado<0){
        perror("No se pudo unir al grupo");
    }
}

void SocketMulticast::salirseGrupo(char *multicastIP){
    multicast.imr_multiaddr.s_addr = inet_addr(multicastIP);
    setsockopt(s, IPPROTO_IP, IP_DROP_MEMBERSHIP, (void *) &multicast, sizeof(multicast));   
}