poligonomain: poligonomain.cpp PoligonoIrreg.o
	g++ poligonomain.cpp PoligonoIrreg.o Coordenada.o -o poligonomain
PoligonoIrreg.o: PoligonoIrreg.cpp Coordenada.o PoligonoIrreg.h
	g++ PoligonoIrreg.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c
