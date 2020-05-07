#include <string>
#include <iostream>
using namespace std;
struct celulares{
	char celular[11];
	char CURP[19];
	char partido[4];
	string toString()
	{
		return string(celular)+"@"+string(CURP)+"@"+string(partido);
	}
    bool operator<(const celulares & other) const
    {
        return atoi(celular) < atoi(other.celular);
    }//
};
