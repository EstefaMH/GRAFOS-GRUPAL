#include <iostream>

using namespace std;

class Arista;


class Vertice
{
protected:
	string nombre;
	int numvertice;
	Vertice* pVertice;
	Arista* arista;

	friend class GrafoMatriz;


public:

	/*-------------------- CONSTRUCTORES ---------------------*/

	//CONSTRUCTOR VACIO
	Vertice();

	//CONSTRUCTOR QUE INICIALIZA EL NOMBRE Y EL NUM EN -1 POR DEFECTO
	Vertice(string x)
	{ // inicializa el nombre y pone el número de vértice e -1
		nombre = x;
		numvertice = -1;
	}

	//CONSTRUCTOR QUE INICIALIZA TANTO EL NOMBRE COMO EL NUMERO DE VERTICE
	Vertice(string x, int n)
	{ // inicializa el nombre y el número de vértice
		nombre = x;
		numvertice = n;
	}

};

