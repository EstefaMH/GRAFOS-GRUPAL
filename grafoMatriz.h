#include <iostream>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <unordered_set>
#include "vertice.h"
#include "arista.h"

using namespace std;


class GrafoMatriz
{
protected:
	int maxvertices;// máximo numero de vértices
	int numvertices; // número de vértices actual
	Vertice* vertice; // array de vértices

public:
	// métodos públicos de la clase GrafoMatriz
	/*----------------- CONSTRUCTORES ---------------*/
	
	GrafoMatriz();


	/*------------------ METODOS ---------------------*/
	bool grafoVacio(); // Retorna true si el grafo esta vacio
	int getNumeroDeVertices(); // Retorna numero de vertices del grafo
	Vertice* getVertice(string nombre); // Retorna el vertice de acuerdo al nombre enviado
	void InsertaVertice(string nombre); // Inserta un vertice al grafo
	void InsertaArista(string vi, string vj); // Inserta arista entre los dos vertices especificados 
	void InsertaArista(string vi, string vj , int ady); // para grafos valorados
	void RecorridoAnchura(string origen); // Recorre el grafo con el algoritmo de anchura ( arbol -> recorrido por niveles)
	void RecorridoProfundidad(string origen); // Recorre el grafo con el algoritmo de profundidad (arbol -> recorrido en pre-orden )
	void MostrarLista(); // Mostrar todos los vertices con sus aristas 

};
 
