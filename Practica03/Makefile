client: client.o PaqueteDatagrama.o SocketDatagrama.o
	g++ SocketDatagrama.o PaqueteDatagrama.o client.o -o client
client.o: client.cpp
	g++ -Wall -c client.cpp
server: server.o PaqueteDatagrama.o SocketDatagrama.o
	g++ SocketDatagrama.o PaqueteDatagrama.o server.o -o server
server.o: server.cpp
	g++ -Wall -c server.cpp
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ -Wall -c SocketDatagrama.cpp
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ -Wall -c PaqueteDatagrama.cpp
clean:
	rm *.o ./client ./server
