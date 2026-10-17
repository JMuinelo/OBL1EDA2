#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/Heap.h"

using namespace std;


struct nodoGrafo{
    int numVert;
    nodoGrafo* sig;
};

class Grafo{
    private: 
        int cantVertices;
        nodoGrafo** dependencias; //lista de adyacencia
        int* prioridades; //donde prioridades[i] contiene la prioridad del modulo i, 0 no importa
        

        int* gradosEntrada(){
            int* retorno = new int[this->cantVertices+1]();
            nodoGrafo** dependencias = this->dependencias;

            for(int i=1;i<this->cantVertices+1;i++){
                nodoGrafo* lista = dependencias[i];
                while(lista){
                    retorno[lista->numVert]++;
                    lista = lista->sig;
                }
            }
            return retorno;

        }


    public:
        Grafo(int cantVertices, int* prioridades){
            this->cantVertices = cantVertices;
            nodoGrafo** dependencias = new nodoGrafo*[cantVertices+1](); //la posicion 0 queda vacía [1,V]
            this->dependencias=dependencias;
            //int* prioridades = new int[cantVertices+1]();
            this->prioridades = prioridades;
        };

        //Agrega la arista v1->v2
        void agregarArista(int v1, int v2){

            nodoGrafo* nuevaAr = new nodoGrafo;
            nuevaAr->numVert = v2; //??puedo?
            nuevaAr->sig = this->dependencias[v1];
            this->dependencias[v1] = nuevaAr;
        }

        //Borra la arista v1->v2
        void eliminarArista(int v1, int v2){
            nodoGrafo *actual = this->dependencias[v1];
            nodoGrafo *anterior = nullptr;

            while (actual)
            {
                if (actual->numVert == v2){
                    if (!anterior) this->dependencias[v1] = actual->sig;
                    else anterior->sig = actual->sig;

                    delete actual;
                    return;
                }

                anterior = actual;
                actual = actual->sig;
            }
        }

        // devuelve un array que siempre tiene largo cantVertices
        int* obtenerVecinos(int v1){
            
            int* retorno = new int[this->cantVertices]();
            nodoGrafo* lista = this->dependencias[v1];
            int i = 0;

            while(lista){
                retorno[i] = lista->numVert;

                i++;
                lista = lista->sig;
            }

            return retorno;
            
        }
        

// devuelve un array cuya primera posicion indica si hay ciclo (0: ciclo, 1: no ciclo) y el resto son el orden topológico si aplica
        int* Khan(){
            int* ordenTopologico = new int[this->cantVertices+1]();
            int punteroArray = 1;
            int cantidadProcesados = 0;
            MinHeap<int>* modulosListos = new MinHeap<int>(this->cantVertices,this->prioridades);

            int* grados = this->gradosEntrada();

            for(int i=1; i<this->cantVertices+1;i++){
                if (grados[i]==0){
                    modulosListos->insertar(i);
                }
            }

            while(!modulosListos->esVacio()){
                int actual = modulosListos->eliminarMinimo();
                ordenTopologico[punteroArray] = actual;
                punteroArray++;
                cantidadProcesados++;
                int* adyacentes = this->obtenerVecinos(actual);
                for(int i=0; i < this->cantVertices; i++){
                    int vecino = adyacentes[i];
                    if(vecino == 0) break; // corto si terminan los adyacentes

                    grados[vecino]--;
                    if(grados[vecino] == 0){
                        modulosListos->insertar(vecino);
                    }
                }
                delete [] adyacentes;
            }
            delete [] grados;
            delete modulosListos;

           if(this->cantVertices == cantidadProcesados){
            //procesé todos, pongo 1 en ordenTopologico[0]
            // si no entro a este if, queda un 0 indicando que hay un ciclo
            ordenTopologico[0]=1;
           }

            return ordenTopologico;

        }

};

int main()
{

    int cantV =0;
    int cantAr=0;
    cin >> cantV >> cantAr ;
    int* prioridades = new int[cantV+1]();

    for(int i = 1; i<cantV+1; i++){
        int prioridad = 0;
        cin >> prioridad;
        prioridades[i] = prioridad;
    }

    Grafo* grafo = new Grafo(cantV,prioridades);

    for(int i = 0; i < cantAr;i++){
        int ar1;
        int ar2;
        cin >> ar1 >> ar2;
        grafo->agregarArista(ar1,ar2);
    }
    int* ordenTopologico = grafo->Khan();

    if(ordenTopologico[0]){
        for(int i=1; i < cantV+1; i++){
            cout<<ordenTopologico[i]<<"\n";
        }
    }else{
        cout << "imposible\n";
    }

    return 0;
}