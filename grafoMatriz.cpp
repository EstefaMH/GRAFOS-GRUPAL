#include "grafoMatriz.h"


GrafoMatriz::GrafoMatriz() {
	vertice = NULL;
	numvertices = 0;
}

bool GrafoMatriz::grafoVacio() {
	return numvertices == 0;
}

int GrafoMatriz::getNumeroDeVertices()
{
	return numvertices;
}

Vertice* GrafoMatriz::getVertice(string nombre)
{
	Vertice* i = vertice;

	while (i != NULL)
	{
		if (i->nombre == nombre) 
			return i;

		i = i->pVertice;
	}

	return NULL;
}

void GrafoMatriz::InsertaVertice(string nombre)
{
	if (getVertice(nombre) == NULL) // saber si el vertice no existe
	{
		Vertice* nuevo = new Vertice(nombre);  //instanciar un vertice

		if (grafoVacio())			// verificar si el grafo esta vacio
			vertice = nuevo;		//si esta vacio se asigna al atributo vertice  el vertice que acabo de crear
		else
		{
			Vertice* agregar = vertice; // asignar el atributo vertice del grafo a la clase Vertice 

			while (agregar-> pVertice != NULL) // 
				agregar = agregar->pVertice;

			agregar->pVertice = nuevo;
		}

		numvertices++;
	}
	else
		cout << "Ese vertice ya existe en el grafo" << endl;
}

void GrafoMatriz::InsertaArista(string vi, string vj)
{
	Vertice* pVi = getVertice(vi);
	Vertice* pVj = getVertice(vj);

	if (pVi == NULL)
		cout << "El vertice origen no existe" << endl;

	if (pVj == NULL)
		cout << "El vertice destino no existe" << endl;

	if (pVi != NULL && pVj != NULL)
	{
		int adyacente = 1;
		Arista* nueva = new Arista(pVj,adyacente);
		

		if (pVi-> arista == NULL) {
			pVi->arista = nueva;
		}  else
		{
			Arista* j = pVi->arista;

			while (j->sig != NULL)
				j = j->sig;

			j->sig = nueva;
		}
	}
}

void GrafoMatriz::RecorridoProfundidad(string vi)
{
	Vertice* vOrigen = getVertice(vi);

	if (vOrigen != NULL)
	{
		cout << "Origen: " << vi << endl;
		cout << "En profundidad: ";
		stack<Vertice*> pila; //crear una pila que almacena los vertices
		list<Vertice*> lista; // crear lista de vertices
		pila.push(vOrigen);

		while (!pila.empty())
		{
			Vertice* vActual = pila.top();
			pila.pop(); //elimina el ultimo vertice de la pila

			list<Vertice*>::iterator iter = find(lista.begin(), lista.end(), vActual);

			if (iter == lista.end())
			{
				cout << vActual->nombre << ", ";
				lista.push_back(vActual);
			}

			Arista* i = vActual->arista;

			while (i != NULL)
			{
				Vertice* vDestino = i->destino;
				iter = find(lista.begin(), lista.end(), vDestino);

				if (iter == lista.end())
					pila.push(vDestino);

				i = i->sig;
			}
		}
	}
	else
		cout << "El vertice especificado no existe" << endl;
}

void GrafoMatriz::RecorridoAnchura(string vi) {
	Vertice* vOrigen = getVertice(vi);

	if (vOrigen != NULL)
	{
		cout << "Origen: " << vi << endl;
		cout << "En anchura: ";
		queue<Vertice*> cola;
		list<Vertice*> lista;
		cola.push(vOrigen);

		while (!cola.empty())
		{
			Vertice* vActual = cola.front();
			cola.pop();

			list<Vertice*>::iterator iter = find(lista.begin(), lista.end(), vActual);

			if (iter == lista.end())
			{
				cout << vActual->nombre << ", ";
				lista.push_back(vActual);
			}

			Arista* i = vActual->arista;

			while (i != NULL)
			{
				Vertice* vDestino = i->destino;
				iter = find(lista.begin(), lista.end(), vDestino);

				if (iter == lista.end())
					cola.push(vDestino);

				i = i->sig
					;
			}
		}
	}
	else
		cout << "El vertice especificado no existe" << endl;
}


void GrafoMatriz::MostrarLista() {

	Vertice* i = vertice;

	while (i != NULL)
	{
		Arista* j = i->arista;
		
		while (j != NULL)
		{
			cout << i->nombre << "->" << j->destino->nombre << ",";
			
			j = j->sig;
		}

		cout << endl;
		i = i->pVertice;
	}
}


