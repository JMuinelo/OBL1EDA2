#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
using namespace std;

template <typename T>
class MinHeap {
private:
    T* datos;
    int cantidad;
    int capacidad;
    int* prioridades;

    int padre(int pos);
    int hijoIzquierdo(int pos);
    int hijoDerecho(int pos);

    bool menor(T a, T b);
    void intercambiar(int pos1, int pos2);
    void flotar(int pos);
    void hundir(int pos);

public:
    MinHeap(int capacidad, int* prioridades);
    ~MinHeap();

    bool esVacio();
    int tamanio();

    void insertar(T valor);
    T obtenerMinimo();
    T eliminarMinimo();

    void imprimir();
    int getCantidad();
};



#endif