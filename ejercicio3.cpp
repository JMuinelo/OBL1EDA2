#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

#include <iostream>
using namespace std;

class MinHeap {
private:
    int* datos;
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

    void intercambiar(int pos1, int pos2) {
        int aux = datos[pos1];
        datos[pos1] = datos[pos2];
        datos[pos2] = aux;
    }

    void flotar(int pos) {
        while (pos > 0 && datos[pos] < datos[padre(pos)]) {
            intercambiar(pos, padre(pos));
            pos = padre(pos);
        }
    }

    void hundir(int pos) {
        while (hijoIzquierdo(pos) < cantidad) {

            int hijoMenor = hijoIzquierdo(pos);

            if (hijoDerecho(pos) < cantidad &&
                datos[hijoDerecho(pos)] < datos[hijoIzquierdo(pos)]) {

                hijoMenor = hijoDerecho(pos);
            }

            if (datos[pos] <= datos[hijoMenor]) {
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
        this->datos = new int[capacidad];
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

    void insertar(int valor) {
        if (cantidad == capacidad) {
            return;
        }

        datos[cantidad] = valor;
        flotar(cantidad);
        cantidad++;
    }

    int obtenerMinimo() {
        if (esVacio()) {
            cout << "Error: el heap esta vacio" << endl;
            return -1;
        }

        return datos[0];
    }

    int eliminarMinimo() {
        if (esVacio()) {
            cout << "Error: el heap esta vacio" << endl;
            return -1;
        }

        int minimo = datos[0];

        datos[0] = datos[cantidad - 1];
        cantidad--;

        if (cantidad > 0) {
            hundir(0);
        }

        return minimo;
    }

    void imprimir() {
        for (int i = 0; i < cantidad; i++) {
            cout << datos[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap heap(10);

    heap.insertar(8);
    heap.insertar(3);
    heap.insertar(10);
    heap.insertar(1);
    heap.insertar(6);
    heap.insertar(4);

    cout << "Heap:" << endl;
    heap.imprimir();

    cout << "Minimo: " << heap.obtenerMinimo() << endl;

    cout << "Eliminamos: " << heap.eliminarMinimo() << endl;

    cout << "Heap luego de eliminar:" << endl;
    heap.imprimir();

    return 0;
}
