#include <iostream>

class Vertice;

class Arista
{
	int ady; 
	Arista* sig;
	Vertice* destino;

	friend class GrafoMatriz;// puede acceder a los metodos public y private de la clase amiga
	
public:

	Arista(Vertice* dest);
	Arista(Vertice* dest, int ady);
};

