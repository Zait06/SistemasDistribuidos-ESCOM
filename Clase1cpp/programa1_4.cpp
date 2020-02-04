#include <iostream>
using namespace std;

// Se ha elaborado el siguiente programa para convertir grados centígrados a Fahrenheit
int main( )
{
	double c = 20;
	double f;

	

	f =  (static_cast<double>(9)/static_cast<double>(5)) * c + 32.0;
	//68

	cout << f;


    return 0;
}