#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/MFSet.h"

using namespace std;

struct Arista{
    int origen;
    int destino;
    int peso;
};
//minHeap para aristas
class MinHeap {
private:
    Arista** datos;
    int cantidad;
    int capacidad;
    


    int padre(int pos) {
        return (pos - 1) / 2;
    }

    int hijoIzquierdo(int pos) {
        return 2 * pos + 1;
    }

    int hijoDerecho(int pos) {
        return 2 * pos + 2;
    }

    // Devuelve true si a debe salir antes que b 
    bool menor(Arista* a, Arista* b) {
        

        return a->peso < b->peso;
    }

    void intercambiar(int pos1, int pos2) {
        Arista* aux = datos[pos1];
        datos[pos1] = datos[pos2];
        datos[pos2] = aux;
    }

    void flotar(int pos) {
        while (pos > 0 && menor(datos[pos], datos[padre(pos)])) {
            intercambiar(pos, padre(pos));
            pos = padre(pos);
        }
    }

    void hundir(int pos) {
        while (hijoIzquierdo(pos) < cantidad) {
            int hijoMenor = hijoIzquierdo(pos);

            if (hijoDerecho(pos) < cantidad &&
                menor(datos[hijoDerecho(pos)], datos[hijoIzquierdo(pos)])) {
                hijoMenor = hijoDerecho(pos);
            }

            if (!menor(datos[hijoMenor], datos[pos])) {
                return;
            }

            intercambiar(pos, hijoMenor);
            pos = hijoMenor;
        }
    }

public:
    MinHeap(int capacidad) {
        this->capacidad = capacidad;
        this->cantidad = 0;
        this->datos = new Arista*[capacidad];
    }

    ~MinHeap() {
        delete[] datos;
    }

    bool esVacio() {
        return cantidad == 0;
    }

    int tamanio() {
        return cantidad;
    }

    void insertar(Arista* valor) {
        if (cantidad == capacidad) {
            return;
        }

        datos[cantidad] = valor;
        flotar(cantidad);
        cantidad++;
    }

    Arista* obtenerMinimo() {
        if (esVacio()) {
            return nullptr;
        }

        return datos[0];
    }

    Arista* eliminarMinimo() {
        if (esVacio()) {
            return nullptr;
        }

        Arista* minimo = datos[0];

        datos[0] = datos[cantidad - 1];
        cantidad--;

        if (cantidad > 0) {
            hundir(0);
        }

        return minimo;
    }

};

long long Kruskal(MinHeap* heap, int cantV){
    long long costo=0;
    MFSet* mfset = new MFSet(cantV+1);
    int agregadas=0;

    while(!heap->esVacio()&&agregadas < cantV-1){
        Arista* ar = heap->eliminarMinimo();

        if(mfset->find(ar->destino) != mfset->find(ar->origen)){
            mfset->merge(ar->origen,ar->destino);
            costo+= ar->peso;
            agregadas++;
        }
    }

    if(mfset->getCantGrupos()>2) return -1;  // porque el grupo 0 nunca se une
    return costo;
}



int main()
{
    int cantV=0;
    int cantA=0;
    cin>> cantV >> cantA;
    MinHeap* heap = new MinHeap(cantA);

    for(int i=0; i<cantA; i++){
        int destino;
        int origen;
        int peso;
        cin >> origen >> destino >> peso;
        Arista* arista = new Arista;
        arista->origen=origen;
        arista->destino=destino;
        arista->peso=peso;
        heap->insertar(arista);
    }
    long long costo = Kruskal(heap,cantV);

    if(costo==-1){
        cout<<"imposible\n";
    }else{
        cout<<costo<<"\n";
    }

    return 0;
}