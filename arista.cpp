#include "arista.h"



Arista::Arista(Vertice* dest)
{
	destino = dest;
	ady = 0;
	sig = NULL;
}


Arista::Arista(Vertice* dest, int adyacente)
{
	destino = dest;
	ady = adyacente;
	sig = NULL;
}

