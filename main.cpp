#include <iostream>
#include "grafoMatriz.h" 



using namespace std;

//PROTOTIPOS
void menu();


int main() {
	menu();	//LLAMA LA FUNCION MENU
	return 0;
}

void menu() {
	//VARIABLES
	int opc;
	string nombre,vi,vj;
	string nombreNodo;
	//string vecti;

	//INSTANCIAR UN GRAFO
	GrafoMatriz* grafo = new GrafoMatriz();

	do {
		cout << "------------ MENU GRAFO -----------" << endl << endl;
		cout << " [1] Agregar vertice " << endl;
		cout << " [2] Agregar Arco " << endl;
		cout << " [3] Saber si el grafo esta vacio " << endl;
		cout << " [4] Buscar un vertice o nodo " << endl;
		cout << " [5] Ver el grafo " << endl;
		cout << " [9] Salir " << endl << endl;
		
		cout << "Elija una opcion " << endl;
		cin >> opc;

		system("cls");

		switch (opc)
		{
			case 1 : 
				
				cout << " ----------- AGREGAR VERTICE ----------" << endl << endl << endl;;
				
				cout << "Ingrese el nombre del vertice " << endl;
				cin >> nombre;

				grafo->InsertaVertice(nombre);
				cout << "el nombre del vertice es : " << nombre<<endl<<endl;
				break;

			case 2 : 
				cout << " ----------- AGREGAR ARCO ----------" << endl << endl << endl;
				
				if (grafo->grafoVacio() || grafo->getNumeroDeVertices() < 2 ) {
					cout << " Grafo vacio o numero de nodos menor que 2" << endl<<endl;
				}
				else {
					cout << "Ingrese el nombre del vertice origen " << endl;
					cin >> vi;
					cout << "Ingrese el nombre del vertice destino " << endl;
					cin >> vj;

					grafo->InsertaArista(vi, vj);
				}
				break;

			case 3:
				cout << " ----------- GRAFO VACIO  ----------" << endl << endl << endl;
				if (grafo->grafoVacio()) {
					cout << "    El grafo esta vacio    " << endl << endl;
				}
				else
					//cout << "  El grafo ya tiene "<< grafo->getNumeroDeVertices() <<" nodos  " << endl << endl << endl;;
					cout << " grafo con "<< grafo->getNumeroDeVertices() <<" nodos" << endl << endl;
				break;

			case 4:
				cout << " ----------- BUSCAR UN VERTICE O NODO  ----------" << endl << endl << endl;

				
				cout << "Ingrese el nombre del vertice a buscar : " << endl;
				cin >> nombreNodo;

				if (grafo->getVertice(nombreNodo) == NULL) {
					cout << "Este nodo no existe en el grafo " << endl << endl;
				}
				else {
					cout << "Nodo si existe" << endl << endl;
				}

				break; 

			case 5 : 
				cout << " ----------- VER LISTA DE ARISTAS PARA CADA VERTICE  ----------" << endl;
				if (grafo->grafoVacio()) {
					cout << "El grafo esta vacio" << endl << endl;
				}
				else
				{
					grafo->MostrarLista();
				}

				break;
		default:
			break;
		}

	} while (opc != 9);


	
}

